# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 21:03:45 by fallard           #+#    #+#              #
#    Updated: 2020/11/17 22:50:06 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

HEAD_NAME = corewar.h corewar_logs.h op.h
LIB_NAME = libft.a

CC = gcc -g
CFLAGS = #-Wall -Wextra -Werror
CFLAGS += -MMD

# ifeq ($(DEBUG), 1) 
# 	CFLAGS += -g
# else
# 	CFLAGS += -DNDEBUG
# 	CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
# endif

SRC_DIR = src/
OBJ_DIR = obj/
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
sdl_test.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.c=.d))
HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))
LIBFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)
INCLUDES += -lSDL2 -lSDL2_image -lSDL2_ttf		# tmp

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) -L $(LIB_DIR) -lft
	@printf "$(GR)>> Program $(NAME) created <<\n$(EOC)"

FORCE:		;

$(LIBFT): FORCE
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CN)* Compile $(YW)$< $(CN)to $(YW)$@$(EOC)\n"

clean:
	@make clean -C $(LIB_DIR)
	@-rm -r $(OBJ_DIR) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)Object files deleted\n$(EOC)" || \
		true

fclean: clean
	@make fclean -C $(LIB_DIR)
	@-rm $(NAME) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)Program $(NAME) deleted\n$(EOC)" || \
		true

re: fclean all

test: all
	@test/test.sh

################################################################################
