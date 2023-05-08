# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makurz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 09:04:17 by makurz            #+#    #+#              #
#    Updated: 2023/05/08 12:00:09 by makurz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the name of the executable
NAME	:= FdF

# Define the name of the submodule
LIBFT_NAME := lib/Libft/lib/libft.a

# Set compiler and debugger according to OS
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CC := gcc
	DB := gdb
	CFLAGS ?= -Wextra -Wall -Wunreachable-code -Ofast -g
else ifeq ($(UNAME), Darwin)
	CC := cc
	DB := lldb
	CFLAGS ?= -Wextra -Wall -Wunreachable-code -Ofast -g
else
	$(error Unsupported operating system: $(UNAME))
endif

# Add path for the source files
VPATH := src/

# Add the remove command
RM := rm -f

# Define the including libraries
LIBMLX := ./lib/MLX42
LIBFT := ./lib/Libft

# Specify the header files
HEADERS := -I./includes -I$(LIBMLX)/include/MLX42 -I$(LIBFT)/header

# Specify the libraries to include
LIBS :=	\
			$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm	\
			$(LIBFT)/lib/libft.a

# Name all source files
SRCS := \
			exits.c fdf.c init.c parse_map.c draw.c to_delete.c	\
			project.c rotate.c


# Define a directory for object files
OBJ_DIR := ./_obj

# Substitute the suffix .c with .o for the object files
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# Define colors for the printing
Y := "\033[33m"
R := "\033[31m"
G := "\033[32m"
X := "\033[0m"
UP := "\033[A"
CUT := "\033[K"

all: $(NAME)

# create a rule to compile the FdF main program
$(NAME): $(OBJS) $(LIBFT_NAME) libmlx
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@printf $(UP)$(CUT)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo $(G)Finished"  "[$(NAME)]...$(X)

# Define a rule to compile my own Libft
$(LIBFT_NAME):
	@make -C ./lib/Libft/

# Define a rule to compile the MLX42
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Define a static rule for compiling the object files
$(OBJ_DIR)/%.o: %.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p _obj
	@$(CC) $(CFLAGS) -MMD -MP -c $< $(HEADERS) -o $@

# Define a rule for cleaning the object files
clean:
	@echo $(R)Cleaning"  "[$(OBJ_DIR)]...$(X);
	@make -C ./lib/Libft/ clean
	@printf $(UP)$(CUT)
	@if [ -d "${OBJ_DIR}" ]; then \
		echo $(R)Cleaning"  "[$(OBJ_DIR)]...$(X); \
		rm -r ${OBJ_DIR}; \
		echo $(G)Cleaned!$(X); \
	fi

# Define a rule for cleaning objects and executables
fclean: clean
	@echo $(R)Cleaning executables...
	@make -C ./lib/Libft/ fclean
	@printf $(UP)$(CUT)
	@if [ -f "$(NAME)" ]; then \
		echo $(R)Cleaning"  "[$(NAME)]...$(X); \
		rm -r $(NAME); \
		echo $(G)Cleaned!$(X); \
	fi
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
