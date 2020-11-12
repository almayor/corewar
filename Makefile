# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 18:17:42 by unite             #+#    #+#              #
#    Updated: 2020/11/12 18:30:38 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_NAME = \
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

################################################################################

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
WT = \033[037m
EOC = \033[0m

################################################################################

PATHS = src
PATHO = obj
PATHI = includes libft/includes ft_printf
PATHPRINTF = ft_printf

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
CFLAGS += -Werror -Wall -Wextra
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI), -I$(path))

LINK = $(CC)
LFLAGS += -lftprintf -L .

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

$(NAME) : $(OBJ)
	@$(LINK) $^ -o $@ $(LFLAGS)
	@printf "\n$(GR)>> Program $(NAME) created! <<\n$(EOC)"

$(PATHO)/%.o : $(PATHS)/%.c
	@$(MKDIR) -p $(@D)
	@$(COMPILE) $(CFLAGS) $< -o $@
	@printf "$(CN).$(EOC)"

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re libftprintf

all : libftprintf $(NAME)

fclean : clean
	@-$(RM) $(NAME) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)program deleted\n$(EOC)" || true
	@$(MAKE) -C $(PATHPRINTF) fclean

clean :
	@-$(RM) -r $(PATHO) 2>/dev/null && \
		printf "$(YW)$(NAME): $(RD)object files deleted\n$(EOC)" || true
	@$(MAKE) -C $(PATHPRINTF) clean

re : fclean all

libftprintf :
	@$(MAKE) -C $(PATHPRINTF)

################################################################################

