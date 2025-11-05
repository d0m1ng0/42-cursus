# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 20:27:14 by kdonlon           #+#    #+#              #
#    Updated: 2025/08/24 20:27:23 by kdonlon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rush-02
CC=cc
CFLAGS=-Wall -Wextra -Werror
INCLUDE=-I./inc

# SRC_DIR=src
OBJ_DIR=obj

# SRC_FILES:=$(SRC_DIR)/*.c
# OBJ_FILES := ${SRC_FILES:.c=.o}


SRCDIR   = src
OBJDIR   = obj
# BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
# INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(NAME): main.o $(OBJECTS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_DIR)/*.o -o $(NAME)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
# @echo "Compiled "$<" successfully!"

%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(OBJ_DIR)/$@

utils:


clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)
