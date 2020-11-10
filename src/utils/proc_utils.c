/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:16:11 by user              #+#    #+#             */
/*   Updated: 2020/11/10 22:39:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint64_t	iproc = 1;

void	print_proc(const t_proc *proc)
{
	t_arg_type	type;
	int			i;

	ft_printf("P%04lu | %s", proc->iproc, g_op_tab[proc->opcode].name);
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		ft_putchar(' ');
		type = get_arg_type(proc, i);
		if (type == REG_CODE)
			ft_printf("r%u", (uint32_t)proc->args[i]);
		else if (type == IND_CODE)
			ft_printf("%i", proc->args[i]);
		else if (type == DIR_CODE)
			ft_printf("%%%i", proc->args[i]);
		i++;
	}
	ft_printf(" (PC = %i)", proc->pc);
	ft_putchar('\n');
}

void	kill_proc(t_proc *proc)
{
	if ((g_vm.log >> 3) & 1)
		ft_printf("P%04lu | KILLED\n"
			INSTRUCT_PREFIX "process hasn't lived for %u cycles (CTD %ld)\n",
			proc->iproc, proc->cycles_since_live, g_vm.cycles_to_die);
	free(proc);
	g_vm.nprocs--;
}

void	fork_proc(int32_t pos, const t_proc *parent)
{
	t_proc		*proc;

	pos = pos % MEM_SIZE < 0 ? (pos % MEM_SIZE) + MEM_SIZE : pos % MEM_SIZE;
	proc = ft_xcalloc(sizeof(t_proc), 1);
	*proc = *parent;
	proc->iproc = iproc++;
	proc->pc = pos;
	proc->cycles_since_live = 0;
	proc->next = g_vm.procs;
	proc->opcode = g_vm.mem[proc->pc];
	if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
		proc->cycles_busy = g_op_tab[proc->opcode].duration - 1;
	else
		proc->opcode = 0;
	g_vm.procs = proc;
	g_vm.nprocs++;
	if ((g_vm.log >> 3) & 1)
		ft_printf("P%04lu | NEW\n"
			INSTRUCT_PREFIX "PC = %i\n",
			proc->iproc, proc->pc);
}

void	create_proc(uint32_t ichamp, int32_t pos)
{
	t_proc		*proc;

	proc = ft_xcalloc(sizeof(t_proc), 1);
	proc->pc = pos;
	proc->reg[0] = ichamp;
	proc->next = g_vm.procs;
	proc->ichamp = ichamp;
	proc->iproc = iproc++;
	proc->opcode = g_vm.mem[proc->pc];
	if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
		proc->cycles_busy = g_op_tab[proc->opcode].duration;
	else
		proc->opcode = 0;
	g_vm.procs = proc;
	g_vm.nprocs++;
}
