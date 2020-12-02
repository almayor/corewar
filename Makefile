# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 19:36:38 by user              #+#    #+#              #
#    Updated: 2020/12/02 16:57:18 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Dir -----
COREWAR_DIR = ./corewar_
ASM_DIR = ./asm_
TEST_DIR = ./test
TEST_FUNCTIONAL_DIR = $(TEST_DIR)/functional
TEST_EVIL_DIR = $(TEST_DIR)/evil

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
	-$(TEST_FUNCTIONAL_DIR)/test.sh

test-evil: asm corewar
	-$(TEST_EVIL_DIR)/eviltester.sh

test-full: test test-evil

.PHONY: all clean fclean re test test-evil test-full asm corewar
