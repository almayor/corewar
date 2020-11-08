# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 21:03:45 by fallard           #+#    #+#              #
#    Updated: 2020/11/06 04:55:07 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

HEAD_NAME = corewar.h
LIB_NAME = libft.a

CC = gcc -g
CFLAGS = #-Wall -Wextra -Werror

SRC_DIR = sources/
INC_DIR = includes/
LIB_DIR = libft/

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

SRC = main.c \
arguments_parser.c \
load_champion.c \
dump.c

TMP = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))
LIBFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

all: $(NAME) 

$(NAME): $(TMP)
	@$(CC) -o $(NAME) $(TMP) $(INCLUDES) -L $(LIB_DIR) -lft
	@printf "$(GR)>> Program $(NAME) created <<\n$(EOC)"

$(LIBFT):
	@make -C $(LIB_DIR)

%.o:%.c $(HEADER)
	@$(CC) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(TMP)
	#@make clean -C $(LIB_DIR)
	@printf "$(YW)$(NAME): $(RD)Object files deleted.\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	#@make fclean -C $(LIB_DIR)
	@printf "$(YW)$(NAME): $(RD)Program $(NAME) deleted.\n$(EOC)"

re: fclean all
