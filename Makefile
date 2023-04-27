# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makurz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 09:04:17 by makurz            #+#    #+#              #
#    Updated: 2023/04/27 11:56:45 by makurz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= Game
CFLAGS	:= -Wextra -Wall -Wunreachable-code -Ofast -g
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
SRCS	:= ./learning_mlx/starting.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f ./learning_mlx/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX)/build

re: clean all

.PHONY: all, clean, fclean, re, libmlx
