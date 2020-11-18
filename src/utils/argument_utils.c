/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:20:55 by user              #+#    #+#             */
/*   Updated: 2020/11/18 23:39:16 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_arg_type	get_arg_type(const t_proc *proc, int n)
{
	if (g_op_tab[proc->opcode].type_octet == 0)
		return (DIR_CODE);
	return ((proc->type_octet >> (2 * (3 - n))) & 0x3);
}

int			get_arg_length(const t_proc *proc, int n)
{
	t_arg_type	type;

	type = get_arg_type(proc, n);
	if (type == REG_CODE)
		return (1);
	if (type == DIR_CODE && g_op_tab[proc->opcode].direct_size)
		return (DIR_SIZE / 2);
	if (type == DIR_CODE)
		return (DIR_SIZE);
	if (type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

int			load_argument(const t_proc *proc, int n, int32_t *val)
{
	t_arg_type	type;

	type = get_arg_type(proc, n);
	if (type == REG_CODE && (proc->args[n] < 1 || proc->args[n] > REG_NUMBER))
		return (1);
	else if (type == REG_CODE)
		*val = proc->reg[proc->args[n] - 1];
	else if (type == IND_CODE && proc->opcode == 13)
		*val = mem_read(proc->pc + proc->args[n], 2); // !!!
	else if (type == IND_CODE && proc->opcode == 14)
		*val = mem_read(proc->pc + (proc->args[n] % IDX_MOD), 4); // !!!
	else if (type == IND_CODE && g_op_tab[proc->opcode].addr_restrict)
		*val = mem_read(proc->pc + (proc->args[n] % IDX_MOD), 4);
	else if (type == IND_CODE)
		*val = mem_read(proc->pc + proc->args[n], 4);
	else
		*val = proc->args[n];
	return (0);
}

int			put_argument(t_proc *proc, int n, int32_t val)
{
	t_arg_type	type;

	type = get_arg_type(proc, n);
	if (type == REG_CODE && (proc->args[n] < 1 || proc->args[n] > REG_NUMBER))
		return (1);
	else if (type == REG_CODE)
		proc->reg[proc->args[n] - 1] = val;
	else if (type == IND_CODE && g_op_tab[proc->opcode].addr_restrict)
		mem_write(proc->ichamp, proc->pc + (proc->args[n] % IDX_MOD), val, 8);
	else
		mem_write(proc->ichamp, proc->pc + proc->args[n], val, 8);
	return (0);
}
