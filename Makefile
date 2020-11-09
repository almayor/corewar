# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 21:03:45 by fallard           #+#    #+#              #
#    Updated: 2020/11/09 21:37:51 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

HEAD_NAME = corewar.h corewar_logs.h op.h utils.h libft.h ft_printf.h
LIB_NAME = libftprintf.a

CC = gcc -g
CFLAGS = #-Wall -Wextra -Werror

SRC_DIR = src/
INC_DIR = includes/ libft/includes/ ft_printf/
LIB_DIR = libft/
PRINTF_DIR = ft_printf/

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

SRC = \
cycle.c \
dump.c \
instruct/add_instruct.c \
instruct/aff_instruct.c \
instruct/and_instruct.c \
instruct/fork_instruct.c \
instruct/ld_instruct.c \
instruct/ldi_instruct.c \
instruct/lfork_instruct.c \
instruct/live_instruct.c \
instruct/lld_instruct.c \
instruct/lldi_instruct.c \
instruct/or_instruct.c \
instruct/st_instruct.c \
instruct/sti_instruct.c \
instruct/sub_instruct.c \
instruct/xor_instruct.c \
instruct/zjump_instruct.c \
load.c \
main.c \
op.c \
parser.c \
run.c \
utils/flow_utils.c \
utils/ft_xcalloc.c \
utils/ft_xmalloc.c \
utils/instruct_utils.c \
utils/memory_utils.c \
utils/parser_utils.c \
utils/proc_utils.c \

TMP = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))
LIBFTPRINTF = $(LIB_NAME)

INCLUDES = $(addprefix "-I", $(INC_DIR))

all: $(NAME) 

$(NAME): $(LIBFTPRINTF) $(TMP)
	@$(CC) -o $(NAME) $(TMP) $(INCLUDES) -L $(LIB_DIR) -lft
	@printf "$(GR)>> Program $(NAME) created <<\n$(EOC)"

$(LIBFTPRINTF):
	@make -C $(PRINTF_DIR)

%.o:%.c $(HEADER)
	@$(CC) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(TMP)
	@make clean -C $(PRINTF_DIR)
	@printf "$(YW)$(NAME): $(RD)Object files deleted.\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@printf "$(YW)$(NAME): $(RD)Program $(NAME) deleted.\n$(EOC)"

re: fclean all
