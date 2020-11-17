# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 13:04:05 by kysgramo          #+#    #+#              #
#    Updated: 2020/06/29 13:04:08 by kysgramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	asm
INC_NAME		=	op.h asm.h

LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/
LIB_NAME		=	libft.a

SRC_PATH		=	sources/asm/
INC_PATH		=	includes/
OBJ_PATH		=	sources/obj/

SRC_NAME		=	asm_main.c asm.c init_structs.c parsing.c parsing2.c parse_command.c coords.c is_functions.c

SRC				=	$(addprefix $(SRC_PATH), $(SRC_NAME))
INC				=	$(addprefix $(INC_PATH), $(INC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror 
IFLAGS			=	-I $(INC_PATH). -I $(LIB_PATH).
LFLAGS			=	-L $(LIB_PATH) -lft

LIB				=	make -C $(LIB_PATH)

.PHONY:	all clean fclean re lib

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c $(INC)
					@mkdir -p $(OBJ_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

all:				$(NAME)

$(NAME):			$(OBJ)

					$(LIB)
					$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)

clean:
					make clean -C $(LIB_PATH)
					rm -rf $(OBJ_PATH)

fclean:				clean
					make fclean -C $(LIB_PATH)
					rm -f $(NAME)

re:					fclean all
