/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:30 by user              #+#    #+#             */
/*   Updated: 2020/11/12 20:54:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_instruct	dispatcher[NUM_INSTRUCT + 1] = {
	NULL,
	live_instruct,
	ld_instruct,
	st_instruct,
	add_instruct,
	sub_instruct,
	and_instruct,
	or_instruct,
	xor_instruct,
	zjmp_instruct,
	ldi_instruct,
	sti_instruct,
	fork_instruct,
	lld_instruct,
	lldi_instruct,
	lfork_instruct,
	aff_instruct,
};

static void		advance_log(const t_proc *proc)
{
	uint32_t	len;
	uint32_t	i;

	if (proc->opcode == 9 && proc->carry == 1)
		return ;
	len = get_instruction_length(proc);
	ft_printf(LOG_ADV_PREFIX_P "ADV %u (0x%.4x -> 0x%.4x)\n" LOG_ADV_PREFIX,
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
		proc->pc = (proc->pc + get_instruction_length(proc)) % MEM_SIZE;
}

static int		dispatch(t_proc *proc)
{
	int	ret;

	if ((g_vm.log >> 2) & 1)
		print_proc(proc);
	ret = dispatcher[proc->opcode](proc);
	if ((g_vm.log >> 2) & 1)
		ft_printf(LOG_OPER_PREFIX "%s\n", ret ? "FAIL" : "OK");
	return (ret);
}

void			cycle(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		proc->cycles_since_live++;
		if (proc->cycles_busy == 0)
		{
			read_instruction(proc);
			if (check_instruction(proc) == 0)
			{
				dispatch(proc);
				if (((g_vm.log >> 4) & 1))
					advance_log(proc);
			}
			advance(proc);
		}
		proc = proc->next;
	}
}
