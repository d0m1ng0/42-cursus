
- main(..., ..., char **envp) envp is an array of strings type KEY=VALUE
  Example:    PATH=/usr/bin:/bin:...  HOME=/home/...
- < infile significa che lo stdin del comando (fd 0) deve leggere dal file
- open() ti ritorna un int (il file descriptor). Se fallisce ritorna -1 con open
  esistono 2 forme:
1. int fd = open(path, flags); se NON uso O_CREAT 1 int fd = open(path, flags,
mode); se USO O_CREAT devo dare i permessi

- sono due i passi da fare Aprire il file -> ottiengo un fd tipo infd con open()
  Collegarlo a stdin -> faccio dup2(infd, 0) nel processo figlio che esegue cmd1
- MINITUTORIAL open() “consuma” risorse: quando hai finito, fai close(fd).

--------------------------------- COMPRENSIONE open infile e outfile int
main(int argc, char **argv) { int	fd_in; int	fd_out; if (argc != 5) return
(px_arg_error()); fd_in = px_open_infile(argv[1]);	fd_out =
px_open_outfile(argv[4]); if (fd_in < 0 || fd_out < 0) { write(2, "pipex: file
error\n", 18); return (1); } close(fd_in); close(fd_out); return (0); }

Nel main dichiaro fd_in e fd_out (due int) e ci salvo i valori ritornati da
open() (tramite le mie funzioni px_open_*).  fd_in è il file descriptor del file
infile aperto in lettura (argv[1]), mentre fd_out è il file descriptor del file
outfile aperto in scrittura/creazione (argv[4]).

In pratica sto preparando le “porte” dei due file: una da cui il programma può
leggere (infile) e una su cui può scrivere (outfile).  Quando creerò la pipe,
otterrò altri due file descriptor (pfd[0] lettura e pfd[1] scrittura) che
rappresentano il canale in RAM.

Il lavoro successivo sarà collegare tutto con dup2 nei processi figli:

cmd1 leggerà da fd_in e scriverà su pfd[1] cmd2 leggerà da pfd[0] e scriverà su
fd_out Così riproduco: < infile cmd1 | cmd2 > outfile


QUINDI

Immagino la pipe come un tubo spezzato in due estremità:

pfd[1] è la “giunzione” di ingresso nel tubo (ci scrivo dentro: write end)
pfd[0] è la “giunzione” di uscita dal tubo (ci leggo fuori: read end) A queste
due giunzioni si aggiungono le due giunzioni dei file:

fd_in: giunzione del file di input (da cui leggere) fd_out: giunzione del file
di output (su cui scrivere) Quindi, quando ho tutto “spezzato”, ho 4 giunzioni
(4 fd) totali:

fd_in (file → lettura) pfd[1] (pipe → scrittura, entra in RAM) pfd[0] (pipe →
lettura, esce dalla RAM) fd_out (file → scrittura) E con dup2 costruisco i
collegamenti finali:

cmd1: stdin <- fd_in e stdout -> pfd[1] cmd2: stdin <- pfd[0] e stdout -> fd_out
Così il flusso è: file1 → cmd1 → (pipe/RAM) → cmd2 → file2.
------------------------------------------

PIPE

come prima cosa cerco di far funzionare < file1 /bin/cat | /usr/bin/wc > file2
cioe ./pipex file1 "/bin/cat" "/usr/bin/wc" file2

- int dup2(int oldfd, int newfd);

- VISUALIZZAZIONE

1. STDOUT “normale” (schermo/terminale) (il tuo programma) | |  write(1,
"ciao\n", 5) v fd 1 = STDOUT (di default) | v +----------------------+ |
TERMINALE / SHELL   | |  ciao                | +----------------------+

2. STDOUT collegato alla pipe (dentro il tubo)

pipe(fd_pipe) crea due estremità (NON IMPORTA IL SENSO, E UNA LISTA) fd_pipe[1]
= write end fd_pipe[0] = read end e poi nel child1 fai: dup2(fd_pipe[1], 1)
(child1 / cmd1) | |  write(1, buf, ...)   (o printf, ecc.) v fd 1 = STDOUT
----dup2---->  fd_pipe[1]  (WRITE end) | v +-----------------+ |      PIPE
| |   (buffer RAM)  | +-----------------+ | v fd_pipe[0]   (READ end)

Quindi, se cmd1 deve mandare il suo output dentro la pipe, deve scrivere su
fd_pipe[1]

dup2(fd_pipe[1], 1) significa: “rimpiazza stdout del processo con l’estremità di
scrittura della pipe”.  Quindi: printf(...), write(1, ...), ecc. non vanno più
sul terminale, ma dentro la pipe

------- fdin fdout, fdpipe0, fdpipe1 fd_in non è “un ingresso” in astratto, è un
handle che punta a un file aperto in modalità lettura. Quindi i byte del file
transitano tramite fd_in quando fai read

fd_out è un file descriptor aperto in scrittura (di solito O_WRONLY | O_CREAT |
O_TRUNC), quindi i byte transitano tramite fd_out quando fai write(fd_out, ...)

fd_pipe[1]: sì, è l’handle con cui scrivi dentro la pipe (buffer in RAM, gestito
dal kernel).  fd_pipe[0]: non scrive su un file esterno. È l’handle con cui
leggi dalla pipe (tiri fuori i byte che qualcuno ha scritto con fd_pipe[1])..  o
ancora meglio fdpipe0 è per leggere i dati che qualcuno ha scritto nella pipe, e
quei dati possono poi essere “comunicati all’esterno” nel senso che un altro
processo li userà (es. li scriverà su file, terminale, ecc.).  write(fd_pipe[1],
...) → mette byte nella pipe read(fd_pipe[0], ...) → prende byte dalla pipe

- EASY Child1: stdin <- infile, stdout -> pipe_write Child2: stdin <- pipe_read,
  stdout -> outfile pipe: pfd[1]=write, pfd[0]=read dup2(old, new) = “new
  diventa old”

l ordine dei due dup2 non conta puche siano fatti prima di execv.

------------------------------------- FLUSSO LOGICO MINIMALE cmd1 < file_in.c |
cmd2 > file_out.c

- pipe(fd_pipe) Ora il parent ha fd_pipe[0] (read) e fd_pipe[1] (write)

- primo fork: creare processo di cmd1(esempio cat)

----------------------------------------------------------- OBIETTIVO : far
funzionare ./pipex file1 "/bin/cat" "/usr/bin/wc" file2 argv0   argv1   argv2
argv3       argv4 senza ancora cercare nel PATH

L'idea e che io ricevo argv2 (esempio "ls -l") come stringa, ma execve vuole un
array di strinhe
{"ls", "-l", NULL}
quindi devo convertire la stringa in char **
int execve(const char *path, char *const argv[], char *const envp[]);
path e percorso eseguibile (esempio /bin/ls)
argv e array di stringhe e termina con NULL: 
usando ft_split(argv[2], ' ') riproduce esattamente il formato ricercato

DISTINZIONE:
1) argv di main
Esempio chiamata:

sh
./pipex file1 "cat" "wc" file2
Dentro main:

argv[0] = "./pipex"
argv[1] = "file1"
argv[2] = "cat"
argv[3] = "wc"
argv[4] = "file2"

2) argv che passi a execve (argomenti del comando)
Esempio per eseguire cat:

tu costruisci un array tipo:
cmd1 = {"cat", NULL}
e chiami:
C
execve("/bin/cat", cmd1, envp);


Chi fa la ricerca nel PATH nel tuo progetto?
La fai tu, con una funzione tipo:

prendi PATH=/usr/local/bin:/usr/bin:/bin:... da envp
per ogni directory, costruisci dir + "/" + cmd
controlli access(candidate, X_OK)
quando trovi quello giusto, lo passi a execve
Per fissarlo: cosa deve fare pipex
Quando l’utente scrive "cat":

tu costruisci cmd_argv = {"cat", NULL}
tu trovi cmd_path = "/bin/cat" (cercando nel PATH)
poi chiami execve(cmd_path, cmd_argv, envp)

Sì, esatto: userai ft_split per due problemi diversi:

Parsing del comando (costruire cmd_argv per execve)
Da "wc -l" → {"wc", "-l", NULL}

Parsing del PATH (ottenere le directory dove cercare l’eseguibile)
Da "/usr/bin:/bin:/usr/local/bin" → {"/usr/bin", "/bin", "/usr/local/bin", NULL}

----------------------
Che cosa fa waitpid(pid, &status, options) waitpid attende che il processo
identificato da pid termini (o cambi stato).  Primo argomento: il pid del
figlio da aspettare.  Secondo argomento: un puntatore a int (es. &status).
waitpid SCRIVE dentro quella variabile delle informazioni codificate sul modo
in cui il figlio è terminato (non è direttamente "il codice di uscita" in forma
semplice).  Terzo argomento: flags/options (0 significa nessuna opzione). NON
ha niente a che vedere con stdout o input/output.  Cosa contiene status dopo
waitpid status è un valore codificato: per estrarre informazioni devi usare le
macro della libreria: WIFEXITED(status) — vero se il figlio è terminato
normalmente con exit().  WEXITSTATUS(status) — il codice passato a exit()
(validamente usabile solo se WIFEXITED è vero).  WIFSIGNALED(status) — vero se
il figlio è stato terminato da un segnale.  WTERMSIG(status) — il numero del
segnale (valido solo se WIFSIGNALED è vero).  Esempio: se il figlio ha fatto
exit(3), dopo waitpid WIFEXITED(status) è vero e WEXITSTATUS(status) == 3.
Quindi NON leggere direttamente status come se fosse il codice di uscita: devi
usare le macro.
