# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 18:11:50 by dverdini          #+#    #+#              #
#    Updated: 2026/02/23 14:49:59 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	 libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c \
	ft_printf_utils.c \
	ft_putchar_fdl.c \
	ft_putstr_fdlsec.c \
	ft_putnbr_fdl.c \
	ft_putuint_fdl.c \
	ft_puthex_fdl.c \
	ft_putptr_fdl.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs	$(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
