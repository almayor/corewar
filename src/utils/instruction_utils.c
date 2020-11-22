/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:36 by user              #+#    #+#             */
/*   Updated: 2020/11/22 14:13:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint32_t	get_instruction_length(const t_proc *proc)
{
	uint32_t	length;
	int			i;

	if (proc->opcode == 0 || proc->opcode > NUM_INSTRUCT)
		return (1);
	length = 1 + g_op_tab[proc->opcode].type_octet;
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		length += get_arg_length(proc, i);
		i++;
	}
	return (length);
}

int			check_instruction(const t_proc *proc)
{
	t_arg_type	arg_type;
	int			i;

	if (proc->opcode == 0 || proc->opcode > NUM_INSTRUCT)
		return (1);
	if (g_op_tab[proc->opcode].type_octet == 0)
		return (0);
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		arg_type = get_arg_type(proc, i);
		if (((1 << (arg_type - 1)) & g_op_tab[proc->opcode].type_mask[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void		read_instruction(t_proc *proc)
{
	int			len;
	int32_t		pc;
	int			i;

	pc = proc->pc + 1;
	if (g_op_tab[proc->opcode].type_octet)
		proc->type_octet = mem_read(pc++, 1);
	else
		proc->type_octet = 0;
	ft_memset(proc->args, 0, sizeof(int32_t) * 3);
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		len = get_arg_length(proc, i);
		proc->args[i] = mem_read(pc, len);
		pc = (pc + len) % MEM_SIZE;
		i++;
	}
}
