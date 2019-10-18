# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 01:08:34 by yjohns            #+#    #+#              #
#    Updated: 2019/10/18 04:18:48 by yjohns           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yjohns.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L $(LIBFT_DIR)
INC = -I$(HEADERS_DIR_DIR) -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR) libft.a
LIBFT_DIR = ./libft/

HEADERS_LIST = filler.h
#HEADERS_DIR = ./includes/
#HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#SRC_DIR = ./source/
SRC_LIST = \
	main.c

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(LIBFT)
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
