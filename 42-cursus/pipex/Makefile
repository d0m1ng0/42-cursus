# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/14 19:55:50 by dverdini          #+#    #+#              #
#    Updated: 2026/05/01 07:30:49 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FT_PRINTF_DIR = ./ft_printf

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

# -----------------------------------------------------------------------
SRCS = src/main.c \
	src/px_init.c \
	src/px_close.c \
	src/px_utils.c \
	src/px_child.c \
	src/px_fork.c \
	src/px_wait.c \
	src/px_errors.c \
	src/px_input_output_files.c \
	src/px_path.c \
	src/px_exec_cmd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o  $@

clean:
	$(RM) $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
