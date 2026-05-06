1. I "Prerequisiti" (Filtro iniziale)Prima di entrare nel codice, controlla la
forma. Se uno di questi fallisce, la correzione finisce subito a 0.

Makefile:
Digita make. Poi digita make di nuovo. Se ricompila qualcosa (re-link), è un
errore.

Norminette: Un classico. Se vedi errori di Norm, il voto è 0.

Funzioni proibite: Fatti mostrare il codice o usa nm ./pipex. Se vedi funzioni non
autorizzate dal subject (es. system, popen), non puoi passare il progetto.

2. Test Obbligatori (Il confronto con la Shell)
Il segreto è testare sempre il comando reale e confrontarlo con ./pipex.

Test	Comando Shell	Comando Pipex Cosa controllare
Standard	`< infile cat	wc -l > outfile`	./pipex infile cat "wc -l" outfile
Errore Infile	`< non_esistente catwc > outfile`	./pipex non_esistente cat wc outfile
Errore Cmd	`< infile cmd_falsowc > outfile`	./pipex infile cmd_falso  wc outfile
Permessi	`< infile catwc > no_permessi`		./pipex infile cat wc no_permessi

3. Analisi del Codice (Domande "Scomode")
Mentre lo studente ti spiega il codice, cerca di capire se ha capito o se ha copiato.
Le Fork: Quante fork() fa? Se ne fa solo una, come gestisce i due comandi?
(Idealmente dovrebbe farne due per farli correre in parallelo).
I Close: Questa è la parte più importante. Chiedigli: "Dove chiudi i File
Descriptor della pipe nel processo padre?". Se non li chiude nel padre, il
programma resterà appeso (il secondo comando non riceverà mai l'EOF).
Wait: Chiedigli come evita i processi "zombie".
Deve esserci almeno una wait o waitpid.

4. Bonus (Se applicabile)Se la parte
obbligatoria è perfetta, passa ai bonus:Multiple Pipes: Prova ./pipex file1
cmd1 cmd2 cmd3 cmd4 file2. Deve funzionare con un numero infinito di
comandi.Here_doc: Prova ./pipex here_doc LIMITER cmd1 cmd2 file. Deve leggere
dal terminale finché non scrivi LIMITER. In questo caso l'output deve essere in
append (>>), quindi controlla se ha usato O_APPEND nella open.

# ----------------------------------------------------------------------------------
1. Repo / compile / no relink
norminette > /tmp/norm.log && echo "NORM OK" || (echo "NORM KO"; grep -v ": OK!" /tmp/norm.log)

Poi:

make fclean
make
make

Atteso importante:

make: Nothing to be done for 'all'.

o equivalente al secondo make.

2. Test base equivalente shell

Prepara input:

printf "hello\nworld\nhello again\n42 Paris\npipex test\n" > infile

Test:

./pipex infile "cat" "wc -l" outfile
< infile cat | wc -l > expected
diff outfile expected
echo "diff exit: $?"
cat outfile

Atteso:

diff exit: 0
5
3. Comando con argomento
./pipex infile "grep hello" "wc -l" outfile
< infile grep hello | wc -l > expected
diff outfile expected
echo "diff exit: $?"
cat outfile

Atteso:

diff exit: 0
2
4. Infile inesistente
./pipex nofile "cat" "wc -l" outfile
echo "pipex exit: $?"
cat outfile

< nofile cat | wc -l > expected
echo "shell exit: $?"
cat expected

diff outfile expected
echo "diff exit: $?"

Atteso importante:

pipex exit: 0
shell exit: 0
diff exit: 0

outfile dovrebbe contenere:

0
5. Outfile impossibile
./pipex infile "cat" "wc -l" no_such_dir/outfile
echo "pipex exit: $?"

Atteso:

pipex exit: 1

Nessun crash.

6. Cmd1 inesistente
./pipex infile "wrongcmd" "wc -l" outfile
echo "pipex exit: $?"
cat outfile

< infile wrongcmd | wc -l > expected
echo "shell exit: $?"
cat expected

diff outfile expected
echo "diff exit: $?"

Atteso:

pipex exit: 0
shell exit: 0
diff exit: 0

outfile:

0
7. Cmd2 inesistente
./pipex infile "cat" "wrongcmd" outfile
echo "pipex exit: $?"

Atteso:

pipex: wrongcmd: command not found
pipex exit: 127
8. Path assoluti
./pipex infile "/bin/cat" "/usr/bin/wc -l" outfile
< infile /bin/cat | /usr/bin/wc -l > expected
diff outfile expected
echo "diff exit: $?"
cat outfile

Atteso:

diff exit: 0
5
9. File grande / pipe non bloccata
seq 1 100000 > bigfile
./pipex bigfile "cat" "wc -l" outfile
< bigfile cat | wc -l > expected
diff outfile expected
echo "diff exit: $?"
cat outfile

Atteso:

diff exit: 0
100000
10. Valgrind rapido
valgrind --leak-check=full --track-fds=yes ./pipex infile "cat" "wrongcmd" outfile

Atteso:

All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts

Se questi passano, davanti a un peer puoi dire tranquillamente: mandatory OK.
