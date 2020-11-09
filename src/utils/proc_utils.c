/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:16:11 by user              #+#    #+#             */
/*   Updated: 2020/11/09 21:16:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_procs(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		proc->opcode = g_vm.mem[proc->pc];
		if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
			proc->cycles_busy = g_op_tab[proc->opcode].duration;
		else
			proc->opcode = 0;
		proc = proc->next;
	}
}

void	create_proc(uint32_t ichamp, uint32_t pos)
{
	t_proc	*proc;

	proc = ft_xcalloc(sizeof(t_proc), 1);
	proc->pc = pos;
	proc->reg[0] = ichamp;
	proc->next = g_vm.procs;
	g_vm.procs = proc;
}
