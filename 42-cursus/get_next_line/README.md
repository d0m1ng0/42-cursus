*This project has been created as a part of the 42 curriculum by dverdini*

### Description This projects deals about the management of the stream buffer.
This function, Get Next Line,  is that reads a file descriptor fd, or multiple
fd, line by line.  The main objective is to learn about static variables, file
descriptor, memory allocation and free in C.  The function reads from files and
standard input.

### Instructions
- Create and unce tests files test*.txt: a long file, a short file, empty file.
  cat "example" > test_example.txt << "EOF"
- Installation: clone the repo.
- compilation, even by changing the BUFFER_SIZE cc -Wall -Wextra -Werror -D
  BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
- Execution: valgrind ./a.out

### Resources
- Internet.
- man: read, malloc, free, open.
- youtube.

### Library description The module get_next_line_utils contains the library
used for this project. The functions are taken from my libft library but only
ft_strjoin has been modified in order to avoid any memory leaks.
- ft_strlen: calculates the string length.
- ft_strchr: locates a character in a string.
- ft_substr: extracts a substring in the function created to clean the stash.
- ft_strlcpy: to copy strings safely.

### Algorithm Explanation
The function follows 3 different logical "moments"
1. the creation of the stash: every time read fills buffer with new data we
must keep what we read in the previous calls. Datas are unified in the
stash with a modified version of ft_strjoin.
2. the extraction of the lines: count the characters until the separator and
allocate for those characters + 1 for the separator + for null-terminator.
3. cleaning the stash: to reset the static variable in order it is ready for
the next calling but containing only what has not been already returned.
