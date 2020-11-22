/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:47 by user              #+#    #+#             */
/*   Updated: 2020/11/22 14:34:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

const t_op	g_op_tab[NUM_INSTRUCT + 1] =
{
	{NULL, 0, {0, 0, 0}, 0, 0, NULL, 0, 0, 0, 0},
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0, 1, 1},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0, 1, 1},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0, 1},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "subtraction", 1, 0, 0, 1},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"and (r1 & r2 -> r3", 1, 0, 1, 1},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"or  (r1 | r2 -> r3", 1, 0, 1, 1},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"xor (r1 ^ r2 -> r3", 1, 0, 1, 1},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1, 0, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1, 1, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0, 0, 1},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 0, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1, 0, 0},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "displayed a char", 1, 0, 0, 1},
};
