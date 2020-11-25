# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 11:33:25 by user              #+#    #+#              #
#    Updated: 2020/11/25 20:33:16 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Name -----
NAME 		= ../corewar
HEADER_NAME	= corewar_logs.h corewar_visu.h corewar.h op.h
LIBFT_NAME	= libft.a

# ----- Dir -----
LIBFT_DIR	= ../libft/
LIBFT_INC	= ../libft/includes
SRC_DIR 	= ./src/
OBJ_DIR		= ./obj/
INC_DIR 	= ./includes/

# ----- Lists -----
FUNCS		= 	cycle.c dump.c instruct/add_instruct.c instruct/aff_instruct.c \
				instruct/and_instruct.c instruct/fork_instruct.c \
				instruct/ld_instruct.c instruct/ldi_instruct.c \
				instruct/lfork_instruct.c instruct/live_instruct.c \
				instruct/lld_instruct.c instruct/lldi_instruct.c \
				instruct/or_instruct.c instruct/st_instruct.c \
				instruct/sti_instruct.c instruct/sub_instruct.c \
				instruct/xor_instruct.c instruct/zjmp_instruct.c \
				load.c main.c op.c parse.c run.c utils/argument_utils.c \
				utils/flow_utils.c utils/instruction_utils.c \
				utils/malloc_utils.c utils/memory_utils.c utils/parse_utils.c \
				utils/proc_utils.c

# ----- Visualizer -----

SDL_INFO = $(shell sdl2-config --version > /dev/null 2>&1; echo $$?)

ifeq ($(SDL_INFO), 0)
	FUNCS +=	visualizer/sdl_launch.c visualizer/sdl_utils.c \
				visualizer/sdl_utils_2.c visualizer/sdl_loop.c \
				visualizer/sdl_draw_info.c visualizer/sdl_draw_map.c \
				visualizer/sdl_draw_ratio.c

	CFLAGS +=	-D'SDL_ENTRY=sdl_launch()'
	CFLAGS +=	-D'SDL_MARK_CHAMP=sdl_mark_champ(ichamp, nbytes, pos)'
	CFLAGS +=	-D'SDL_CLEANUP=sdl_quit()'

	LFT +=		-lSDL2 -lSDL2_ttf
else

	CFLAGS +=	-DNO_SDL
	CFLAGS +=	-D'SDL_ENTRY=terminate(SDL_NOT_SUPPORT)'
	CFLAGS +=	-D'SDL_MARK_CHAMP=terminate(SDL_NOT_SUPPORT)'
	CFLAGS +=	-D'SDL_CLEANUP'
endif

# ----- OS -----

ifeq ($(shell uname -s), Linux)
	CFLAGS += -fno-tree-loop-distribute-patterns
endif

# ----- Auto -----

HEADER		= $(addprefix $(INC_DIR), $(HEADER_NAME))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
SRC			= $(addprefix $(SRC_DIR), $(FUNCS))
OBJ			= $(addprefix $(OBJ_DIR), $(FUNCS:.c=.o))

# -------------

INCLUDES	= -I $(INC_DIR) -I $(LIBFT_INC) 

CC			= gcc
CFLAGS		+= -Wall -Wextra -Werror -Wno-unused-value
CFLAGS 		+= -O3 -ffast-math
LFT			+= -L $(LIBFT_DIR) -lft

# --- Colors ---

RED				= "\033[0;31m"
GREEN			= "\033[0;32m"
CYAN			= "\033[0;36m"
YELLOW			= "\033[0;33m"
EOC				= "\033[0m"

# =================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LFT) -o $(NAME)
	@echo $(GREEN) "Program corewar created" $(EOC)

$(OBJ_DIR):
	@mkdir -p ./obj/

FORCE:		;

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo $(CYAN) "Compiling $< into $@"$(EOC)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(YELLOW)"$(NAME):"$(EOC) $(RED)"Object files deleted."$(EOC)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo $(YELLOW)"$(NAME):"$(EOC) $(RED)"Executable file deleted."$(EOC)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
