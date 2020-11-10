/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:36 by user              #+#    #+#             */
/*   Updated: 2020/11/11 00:53:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


uint32_t	get_instruction_length(const t_proc *proc)
{
	uint32_t	length;
	int			i;

	if (proc->opcode == 0 || proc->opcode > NUM_INSTRUCT)
		return (1);
	length = 1;
	if (proc->opcode != 1 && proc->opcode != 9 &&
		proc->opcode != 12 && proc->opcode != 15)
		length++;
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

