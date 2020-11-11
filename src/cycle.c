/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:30 by user              #+#    #+#             */
/*   Updated: 2020/11/11 18:04:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		advance_log(const t_proc *proc)
{
	uint32_t	len;
	uint32_t	i;

	len = get_instruction_length(proc);
	ft_printf("P%04lu > ADV %u (0x%.4x -> 0x%.4x)\n" ADVANCE_PREFIX,
		proc->iproc, len, proc->pc, (proc->pc + len) % MEM_SIZE);
	i = 0;
	while (i < len)
	{
		ft_printf("%.2x%c", g_vm.mem[(proc->pc + i) % MEM_SIZE],
			i == len - 1 ? '\n' : ' ');
		i++;
	}
}

static void 	advance(t_proc *proc)
{
	if (proc->opcode != 9 || proc->carry == 0)
	{
		if (((g_vm.log >> 4) & 1) &&
			proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
			advance_log(proc);
		proc->pc = (proc->pc + get_instruction_length(proc)) % MEM_SIZE;
	}
	proc->opcode = g_vm.mem[proc->pc];
	if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
		proc->cycles_busy = g_op_tab[proc->opcode].duration - 1;
	else
		proc->opcode = 0;
}

void			cycle(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		proc->cycles_since_live++;
		if (proc->cycles_busy)
			proc->cycles_busy--;
		else
		{
			read_instruction(proc);
			if (check_instruction(proc) == 0)
				dispatch(proc);
			advance(proc);
		}
		proc = proc->next;
	}
}
