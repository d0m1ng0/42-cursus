# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 09:43:36 by dverdini          #+#    #+#              #
#    Updated: 2026/05/04 12:35:47 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FT_PRINTF_DIR = ./ft_printf

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

# ----------------------- MINI-LIBX ---------------------------------------
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# ------------------------------------------------------------------------
CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

RM = rm -f

# ------------------------------------------------------------------------

SRCS = src/main.c \
	src/init.c \
	src/events.c \
	src/cleanup.c \
	src/render.c \
	src/utils_str.c \
	src/fractals.c \
	src/colors.c \
	src/parse.c \
	src/utils_math.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o  $@

clean:
	$(RM) $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

