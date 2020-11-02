/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2020/11/02 20:42:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op    g_op_tab[NUM_INSTRUCT + 1] =
{
	NULL,
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, DIR_SIZE},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, DIR_SIZE},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, DIR_SIZE},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, DIR_SIZE},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, DIR_SIZE},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, DIR_SIZE},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, DIR_SIZE},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, DIR_SIZE},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, DIR_SIZE / 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, DIR_SIZE / 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, DIR_SIZE / 2},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, DIR_SIZE / 2},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, DIR_SIZE},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, DIR_SIZE / 2},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, DIR_SIZE / 2},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, DIR_SIZE},
};
