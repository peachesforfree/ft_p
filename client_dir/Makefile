#!/usr/bin/make -f

NAME = ../client
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	client
SRC_DIR = ./sources/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ../libft/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
OBJ_FILES = $(SRCS:%=%.o)
SRC_FILES = $(SRCS:%=%.c)

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	gcc -g -Wall -Werror -Wextra -c -I $(LIBFT_DIR)libft.h -I includes  -o $@ -c $<

$(NAME): $(OBJ)
	gcc -g -shared -ldl $(LIBFT) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
