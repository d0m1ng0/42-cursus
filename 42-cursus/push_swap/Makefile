# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 13:34:58 by dverdini          #+#    #+#              #
#    Updated: 2026/04/14 13:32:52 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -I./libft -I./bonus -I./get_next_line

RM = rm -f

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
	src/utils/ps_utils.c \
	src/arbitrage_algorithm/ps_arbitrage_algo.c \
	src/arbitrage_algorithm/ps_arbitrage_algo_settings.c \
	src/arbitrage_algorithm/ps_arbitrage_algo_utils.c \
	src/arbitrage_algorithm/ps_arbitrage_algo_moves.c \
	src/operations/ps_push.c \
	src/operations/ps_reverse_rotate.c \
	src/operations/ps_rotate.c \
	src/operations/ps_swap.c \
	src/parsing/ps_error_and_free_utils.c \
	src/parsing/ps_parse_and_fill_stack.c \
	src/parsing/ps_parsing_utils.c \
	dlist/ft_dlstadd_front.c \
	dlist/ft_dlstadd_back.c \
	dlist/ft_dlstclear.c \
	dlist/ft_dlstdelone.c \
	dlist/ft_dlstlast.c \
	dlist/ft_dlstnew.c \
	dlist/ft_lstsize.c
BONUS_SRCS = bonus/checker.c \
	bonus/ft_strcmp.c \
	src/utils/ps_utils.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	src/operations/ps_push.c \
	src/operations/ps_reverse_rotate.c \
	src/operations/ps_rotate.c \
	src/operations/ps_swap.c \
	src/parsing/ps_error_and_free_utils.c \
	src/parsing/ps_parse_and_fill_stack.c \
	src/parsing/ps_parsing_utils.c \
	dlist/ft_dlstadd_front.c \
	dlist/ft_dlstadd_back.c \
	dlist/ft_dlstclear.c \
	dlist/ft_dlstdelone.c \
	dlist/ft_dlstlast.c \
	dlist/ft_dlstnew.c \
	dlist/ft_lstsize.c

# creation of the same list but with different extension .o
# but just a list
OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# entry point of the Makefile
# make goes to the first rule all which needs NAME, NAME needs OBJS, then
# activate the magic rule
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# --- rule for the bonus: this allow to type "make bonus"
bonus: $(LIBFT) $(BONUS_NAME)
# --- this is the linking of the checker: it uses its objects and the libft
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
# -------------------------------------------------------------------------

$(LIBFT):
	@make -C $(LIBFT_DIR)
# how to create the .o files not in the root but neare their .c files magic
# rule, CONVERSION ENGINE: if you need a file .o in a folder search it in the
# same place but with .c extension compile with flags only (-c) all sources
# ($<) or PREREQUISITES (the .c files) and save the result as (-o) the mane of
# the object correspondent ($@) TARGET
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# -I. means  Include on the current folder "." where make is lauched
