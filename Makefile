# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 21:03:45 by fallard           #+#    #+#              #
#    Updated: 2020/11/12 21:43:05 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

HEAD_NAME = corewar.h corewar_logs.h op.h
LIB_NAME = libft.a

CC = gcc -g
CFLAGS = -Wno-pointer-sign -Wall #-Wextra -Werror

SRC_DIR = src/
INC_DIR = includes/
LIB_DIR = libft/

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
load.c \
main.c \
op.c \
parse.c \
run.c \
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
instruct/zjmp_instruct.c \
utils/flow_utils.c \
utils/instruction_utils.c \
utils/argument_utils.c \
utils/malloc_utils.c \
utils/memory_utils.c \
utils/parse_utils.c \
utils/proc_utils.c \

TMP = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))
LIBFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

all: $(NAME) 

$(NAME): $(LIBFT) $(TMP)
	@$(CC) $(CFLAGS) -o $(NAME) $(TMP) $(INCLUDES) -L $(LIB_DIR) -lft
	@printf "$(GR)>> Program $(NAME) created <<\n$(EOC)"

FORCE:		;

$(LIBFT): FORCE
	@make -C $(LIB_DIR)

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CN)* Compile $(YW)$< $(CN)to $(YW)$@$(EOC)\n"

clean:
	@rm -f $(TMP)
	@make clean -C $(LIB_DIR)
	@printf "$(YW)$(NAME): $(RD)Object files deleted.\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@printf "$(YW)$(NAME): $(RD)Program $(NAME) deleted.\n$(EOC)"

re: fclean all
