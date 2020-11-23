# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 21:03:45 by fallard           #+#    #+#              #
#    Updated: 2020/11/23 17:24:11 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS += -Wall -Wextra -Werror -Wno-unused-result
CFLAGS += -MMD

ifeq ($(DEBUG), 1)
	CFLAGS += -g
else
	CFLAGS += -O3 -ffast-math
endif

ifeq ($(shell uname -s), Linux)
	CFLAGS += -fno-tree-loop-distribute-patterns
endif

################################################################################

NAME = corewar
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes $(LIB_DIR)/includes
LIB_DIR = libft

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

SDL_INFO = $(shell sdl2-config --version > /dev/null 2>&1; echo $$?)

ifeq ($(SDL_INFO), 0)
	SRC += \
	visualizer/sdl_launch.c \
	visualizer/sdl_utils.c \
	visualizer/sdl_utils_2.c \
	visualizer/sdl_loop.c \
	visualizer/sdl_draw_info.c \
	visualizer/sdl_draw_map.c \
	visualizer/sdl_draw_ratio.c
	CFLAGS += -D'SDL_ENTRY=sdl_launch()'
	CFLAGS += -D'SDL_MARK_CHAMP=sdl_mark_champ(ichamp, nbytes, pos)'
	LIB = -L $(LIB_DIR) -lft -lSDL2 -lSDL2_ttf
else
	CFLAGS += -DNO_SDL
	CFLAGS += -D'SDL_ENTRY=terminate(SDL_NOT_SUPPORT)'
	CFLAGS += -D'SDL_MARK_CHAMP=terminate(SDL_NOT_SUPPORT)'
	LIB = -L $(LIB_DIR) -lft
endif

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))
INC = $(addprefix -I , $(INC_DIR))

-include $(DEP)

################################################################################

LIBFT = $(addprefix $(LIB_DIR)/, libft.a)

FT_SRC_DIR = $(addprefix $(LIB_DIR)/, src)
FT_OBJ_DIR = $(addprefix $(LIB_DIR)/, obj)
FT_INC_DIR = $(addprefix $(LIB_DIR)/, includes src/ft_printf)

FT_SRC = \
lib/ft_abs.c \
lib/ft_atoi.c \
lib/ft_bzero.c \
lib/ft_calloc.c \
lib/ft_factorial.c \
lib/ft_isalnum.c \
lib/ft_isalpha.c \
lib/ft_isascii.c \
lib/ft_isdigit.c \
lib/ft_isprint.c \
lib/ft_itoa.c \
lib/ft_lstadd.c \
lib/ft_lstdel.c \
lib/ft_lstdelone.c \
lib/ft_lstiter.c \
lib/ft_lstmap.c \
lib/ft_lstnew.c \
lib/ft_memalloc.c \
lib/ft_memccpy.c \
lib/ft_memchr.c \
lib/ft_memcmp.c \
lib/ft_memcpy.c \
lib/ft_memdel.c \
lib/ft_memmove.c \
lib/ft_memset.c \
lib/ft_putchar.c \
lib/ft_putchar_fd.c \
lib/ft_putendl.c \
lib/ft_putendl_fd.c \
lib/ft_putnbr.c \
lib/ft_putnbr_fd.c \
lib/ft_putstr.c \
lib/ft_putstr_fd.c \
lib/ft_quick_sort.c \
lib/ft_splitdel.c \
lib/ft_strcat.c \
lib/ft_strchr.c \
lib/ft_strclr.c \
lib/ft_strcmp.c \
lib/ft_strcpy.c \
lib/ft_strdel.c \
lib/ft_strdup.c \
lib/ft_strequ.c \
lib/ft_striter.c \
lib/ft_striteri.c \
lib/ft_strjoin.c \
lib/ft_strjoin_free.c \
lib/ft_strlcat.c \
lib/ft_strlen.c \
lib/ft_strmap.c \
lib/ft_strmapi.c \
lib/ft_strncat.c \
lib/ft_strncmp.c \
lib/ft_strncpy.c \
lib/ft_strnequ.c \
lib/ft_strnew.c \
lib/ft_strnstr.c \
lib/ft_strrchr.c \
lib/ft_strsplit.c \
lib/ft_strstr.c \
lib/ft_strsub.c \
lib/ft_strtrim.c \
lib/ft_swap.c \
lib/ft_tolower.c \
lib/ft_toupper.c \
lib/get_next_line.c \

FT_SRC += \
ft_printf/complete_specifier/functions/complete_specifier_b.c \
ft_printf/complete_specifier/functions/complete_specifier_c.c \
ft_printf/complete_specifier/functions/complete_specifier_f.c \
ft_printf/complete_specifier/functions/complete_specifier_i.c \
ft_printf/complete_specifier/functions/complete_specifier_o.c \
ft_printf/complete_specifier/functions/complete_specifier_p.c \
ft_printf/complete_specifier/functions/complete_specifier_s.c \
ft_printf/complete_specifier/functions/complete_specifier_u.c \
ft_printf/complete_specifier/functions/complete_specifier_x.c \
ft_printf/complete_specifier/complete_specifier.c \
ft_printf/data_specifier/functions/data_specifier_c.c \
ft_printf/data_specifier/functions/data_specifier_f.c \
ft_printf/data_specifier/functions/data_specifier_i.c \
ft_printf/data_specifier/functions/data_specifier_p.c \
ft_printf/data_specifier/functions/data_specifier_pc.c \
ft_printf/data_specifier/functions/data_specifier_s.c \
ft_printf/data_specifier/functions/data_specifier_u.c \
ft_printf/data_specifier/data_specifier.c \
ft_printf/parse_specifier/parse_specifier.c \
ft_printf/print_specifier/functions/print_specifier_b.c \
ft_printf/print_specifier/functions/print_specifier_c.c \
ft_printf/print_specifier/functions/print_specifier_f.c \
ft_printf/print_specifier/functions/print_specifier_i.c \
ft_printf/print_specifier/functions/print_specifier_o.c \
ft_printf/print_specifier/functions/print_specifier_p.c \
ft_printf/print_specifier/functions/print_specifier_s.c \
ft_printf/print_specifier/functions/print_specifier_u.c \
ft_printf/print_specifier/functions/print_specifier_x.c \
ft_printf/print_specifier/functions/print_specifier_xx.c \
ft_printf/print_specifier/print_specifier.c \
ft_printf/utils/printing/pf_putchar.c \
ft_printf/utils/printing/pf_putfloat.c \
ft_printf/utils/printing/pf_putint.c \
ft_printf/utils/printing/pf_putnchar.c \
ft_printf/utils/printing/pf_puts.c \
ft_printf/utils/printing/pf_putuint.c \
ft_printf/utils/get_ndigits_int.c \
ft_printf/utils/get_ndigits_uint.c \
ft_printf/utils/min.c \
ft_printf/validate_specifier/functions/validate_specifier_b.c \
ft_printf/validate_specifier/functions/validate_specifier_c.c \
ft_printf/validate_specifier/functions/validate_specifier_f.c \
ft_printf/validate_specifier/functions/validate_specifier_i.c \
ft_printf/validate_specifier/functions/validate_specifier_p.c \
ft_printf/validate_specifier/functions/validate_specifier_s.c \
ft_printf/validate_specifier/functions/validate_specifier_u.c \
ft_printf/validate_specifier/functions/validate_specifier_x.c \
ft_printf/validate_specifier/validate_specifier.c \
ft_printf/ft_asprintf.c \
ft_printf/ft_dprintf.c \
ft_printf/ft_printf.c \
ft_printf/ft_snprintf.c \
ft_printf/ft_sprintf.c \
ft_printf/ft_vasprintf.c \
ft_printf/ft_vdprintf.c \
ft_printf/ft_vprintf.c \
ft_printf/ft_vsnprintf.c \
ft_printf/ft_vsprintf.c \

FT_OBJ = $(addprefix $(FT_OBJ_DIR)/, $(FT_SRC:.c=.o))
FT_DEP = $(addprefix $(FT_OBJ_DIR)/, $(FT_SRC:.c=.d))
FT_INC = $(addprefix -I , $(FT_INC_DIR))

-include $(FT_DEP)

################################################################################

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@printf "$(GR)>> Program $(NAME) created <<\n$(EOC)"

$(LIBFT): $(FT_OBJ)
	@ar rc $(LIBFT) $^
	@printf "\n$(GR)>> libft created! <<$(EOC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(CN)* Compile $(YW)$< $(CN)to $(YW)$@$(EOC)\n"

$(FT_OBJ_DIR)/%.o: $(FT_SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(FT_INC) -c $< -o $@
	@printf "$(CN).$(EOC)"

clean:
	@-rm -r $(FT_OBJ_DIR) 2>/dev/null && \
		printf "$(YW)libft: $(RD)object files deleted$(EOC)\n" || true
	@-rm -r $(OBJ_DIR) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)object files deleted\n$(EOC)" || \
		true

fclean: clean
	@-rm $(LIBFT) 2>/dev/null && \
		printf "$(YW)libft: $(RD)$(NAME) deleted$(EOC)\n" || true
	@-rm $(NAME) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)program $(NAME) deleted\n$(EOC)" || \
		true

re: fclean all

test: all
	@test/test.sh
