*This project has been created as a part of the 42 curriculum by dverdini*


### Description
Pipex is a project that focuses on the knowledge of Unix systems concerning the
pipe mechanism. The program simulates the shell command:
   < infile cmd1 | cmd2 > outfile  

The main goal is to manage correctly the communication between processes (IPC),
the stream addressing (stdin, stdout), and the execution of system binaries
using environmental variables (envp).

### Instructions
- Installation: clone the repo.
- MANDATORY PART:
    make
    make clean
    male fclean
    make re

    ./pipex infile "cmd1" "cmd2" outfile

    - EXAMPLE
    ./pipex input.txt "cat -e" "grep hello" output.txt

### Resources
- man 2 pipe
- man 2 fork
- man 2 dup2
- man 2 execve
- Internet.

