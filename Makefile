# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 19:36:38 by user              #+#    #+#              #
#    Updated: 2020/11/25 19:42:30 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Dir -----
COREWAR_DIR = ./corewar_
ASM_DIR = ./asm_

# =================

all: asm corewar

corewar:
	@make -C $(COREWAR_DIR)

asm:
	@make -C $(ASM_DIR)

clean:
	@make -C $(ASM_DIR) clean
	@make -C $(COREWAR_DIR) clean

fclean: clean
	@make -C $(ASM_DIR) fclean
	@make -C $(COREWAR_DIR) fclean

re: fclean all

test: asm corewar
	./test/test.sh

.PHONY: all clean fclean re test asm corewar
