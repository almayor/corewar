# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/11/12 16:33:58 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

################################################################################

SRC_NAME = \
complete_specifier/complete_specifier.c \
complete_specifier/functions/complete_specifier_b.c \
complete_specifier/functions/complete_specifier_c.c \
complete_specifier/functions/complete_specifier_f.c \
complete_specifier/functions/complete_specifier_i.c \
complete_specifier/functions/complete_specifier_o.c \
complete_specifier/functions/complete_specifier_p.c \
complete_specifier/functions/complete_specifier_s.c \
complete_specifier/functions/complete_specifier_u.c \
complete_specifier/functions/complete_specifier_x.c \
data_specifier/data_specifier.c \
data_specifier/functions/data_specifier_c.c \
data_specifier/functions/data_specifier_f.c \
data_specifier/functions/data_specifier_i.c \
data_specifier/functions/data_specifier_p.c \
data_specifier/functions/data_specifier_pc.c \
data_specifier/functions/data_specifier_s.c \
data_specifier/functions/data_specifier_u.c \
ft_asprintf.c \
ft_dprintf.c \
ft_printf.c \
ft_snprintf.c \
ft_sprintf.c \
ft_vasprintf.c \
ft_vdprintf.c \
ft_vprintf.c \
ft_vsnprintf.c \
ft_vsprintf.c \
parse_specifier/parse_specifier.c \
print_specifier/functions/print_specifier_b.c \
print_specifier/functions/print_specifier_c.c \
print_specifier/functions/print_specifier_f.c \
print_specifier/functions/print_specifier_i.c \
print_specifier/functions/print_specifier_o.c \
print_specifier/functions/print_specifier_p.c \
print_specifier/functions/print_specifier_s.c \
print_specifier/functions/print_specifier_u.c \
print_specifier/functions/print_specifier_x.c \
print_specifier/functions/print_specifier_xx.c \
print_specifier/print_specifier.c \
utils/get_ndigits_int.c \
utils/get_ndigits_uint.c \
utils/min.c \
utils/printing/pf_putchar.c \
utils/printing/pf_putfloat.c \
utils/printing/pf_putint.c \
utils/printing/pf_putnchar.c \
utils/printing/pf_puts.c \
utils/printing/pf_putuint.c \
validate_specifier/functions/validate_specifier_b.c \
validate_specifier/functions/validate_specifier_c.c \
validate_specifier/functions/validate_specifier_f.c \
validate_specifier/functions/validate_specifier_i.c \
validate_specifier/functions/validate_specifier_p.c \
validate_specifier/functions/validate_specifier_s.c \
validate_specifier/functions/validate_specifier_u.c \
validate_specifier/functions/validate_specifier_x.c \
validate_specifier/validate_specifier.c \

################################################################################

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

################################################################################

PATHI = src
PATHS = src
PATHO = obj

PATHFT = ../libft
PATHFTA = $(PATHFT)/libft.a

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS = -Wall -Wextra -Werror -Wno-unused-result
CFLAGS += -I$(PATHI) -I$(PATHFT)/includes
CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

################################################################################

ifeq ($(DEBUG), 1)
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))


$(NAME) : $(PATHFT)/libft.a $(OBJ)
	@cp $(PATHFTA) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n$(GR)>> libftprintf.a created! <<$(EOC)\n"

$(PATHO)/%.o : $(PATHS)/%.c
	@mkdir -p $(@D)
	@$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@
	@printf "$(CN).$(EOC)"

################################################################################

.PHONY : all clean fclean re libft

all : libft $(NAME)

fclean : clean
	@-rm $(NAME) 2>/dev/null && \
		printf "$(YW)ft_printf: $(RD)libftprintf.a deleted$(EOC)\n" || true
	@$(MAKE) -C $(PATHFT) fclean

clean :
	@-rm -r $(PATHO) 2>/dev/null && \
		printf "$(YW)ft_printf: $(RD)object files deleted$(EOC)\n" || true
	@$(MAKE) -C $(PATHFT) clean

re : fclean all

$(PATHFT)/libft.a : libft

libft :
	@-$(MAKE) -C $(PATHFT)

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################
