# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 15:43:25 by fallard           #+#    #+#              #
#    Updated: 2020/11/25 19:49:40 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HLIB_NAME = libft.h
HPF_NAME = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = src/lib/
PF_DIR = src/printf/
INC_DIR = includes/

SRC_LIB = ft_atoi.c \
ft_atoi_long.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memalloc.c \
ft_calloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strjoin_free.c \
ft_strjoin_free_2.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_swap.c \
ft_factorial.c \
ft_abs.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
get_next_line.c \
ft_splitdel.c \
ft_isint.c \
ft_iswspace.c \
ft_itoa_base.c \
ft_long_power.c \
ft_lstadd_back.c \
ft_lstinsert_after.c \
ft_lstinsert_before.c \
ft_lstnewset.c \
ft_nbrmax.c \
ft_nbrmin.c \
ft_power.c \
ft_putnbr_color.c \
ft_putstr_color.c \
ft_word_count.c \
get_next_line_clean.c \
ft_strsdup.c \
ft_strrev.c \
ft_str_charcount.c \

SRC_PF = ft_asprintf.c \
ft_dprintf.c \
ft_printf.c \
ft_snprintf.c \
ft_sprintf.c \
ft_vasprintf.c \
ft_vdprintf.c \
ft_vprintf.c \
ft_vsnprintf.c \
ft_vsprintf.c \
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


HEAD_LIB = $(addprefix $(INC_DIR), $(HLIB_NAME))
HEAD_PF = $(addprefix $(INC_DIR), $(HPF_NAME))

TMP_LIB = $(addprefix $(LIB_DIR), $(SRC_LIB:.c=.o))
TMP_PF = $(addprefix $(PF_DIR), $(SRC_PF:.c=.o))

INCLUDES = -I $(INC_DIR)

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

all: $(NAME)

$(NAME): $(TMP_LIB) $(TMP_PF)
	@ar rc $(NAME) $(TMP_LIB) $(TMP_PF)
	@printf "\n$(GR) >> $(NAME) created! <<$(EOC)\n"

%.o:%.c $(HEAD_LIB) $(HEAD_PF)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 
	@printf "$(CN).$(EOC)"

clean:
	@rm -f $(TMP_LIB)
	@rm -f $(TMP_PF)
	@printf "$(YW)libft: $(RD)Object files deleted.$(EOC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YW)libft: $(RD)$(NAME) deleted.$(EOC)\n"

re: fclean all
