*This project has been created as [art pf the 42 curriculum by dverdini.*

# ft_printf

## Description
This project recodes the standard C printf function.  This projects mimics the
original behaviour of printf for a specific set of conversions:
- Characters.
- Strings.
- Decimal numbers.
- Unsigned int.
- Hexadecimals.
- Pointers.

## Instruction
- Compilation:
	- to compilee the library libftprintf.a run in the root directory
		make
	- compile the code with the library
		cc -Wall -Werror -Wextra main.c libftprintf.a
## Algorith and Data Structure
1. Data Structure: I used t_printf_data structure to store the total lenght
printed bytes. This will be heltful to implement the bonus in the future.
2. Algorithm:  Recursion for numeric conversions (%d, %u, %x, %p).  Each conversion
has its own specialized function, making the code modular and easy to implement.

## Resources
- Internet.
- Peer exchanging.
- Youtube.
