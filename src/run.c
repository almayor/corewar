/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:50 by user              #+#    #+#             */
/*   Updated: 2020/11/18 15:15:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void decimate(void)
{
	t_proc	*proc_curr;
	t_proc	*proc_next;

	while ((proc_curr = g_vm.procs) &&
			proc_curr->cycles_since_live >= g_vm.cycles_to_die)
	{
		g_vm.procs = proc_curr->next;
		kill_proc(proc_curr);
	}
	while (proc_curr && proc_curr->next)
	{
		proc_next = proc_curr->next;
		if (proc_next->cycles_since_live >= g_vm.cycles_to_die)
		{
			proc_curr->next = proc_next->next;
			kill_proc(proc_next);
		}
		else
			proc_curr = proc_next;
	}
}

// static void update_opcodes(void)
// {
// 	t_proc	*proc;

// 	proc = g_vm.procs;
// 	while (proc)
// 	{
// 		if (proc->cycles_busy)
// 			proc->cycles_busy--;
// 		else
// 		{
// 			proc->opcode = g_vm.mem[proc->pc];
// 			if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
// 				proc->cycles_busy = g_op_tab[proc->opcode].duration - 1;
// 			else
// 				proc->opcode = 0;
// 		}
// 		proc = proc->next;
// 	}
// }

static void	update_champs(void)
{
	int		ichamp;
	t_champ	champ;

	ichamp = 0;
	while (ichamp < MAX_PLAYERS)
	{
		champ = g_vm.champs[ichamp];
		if (champ.ichamp > 0)
		{
			champ.prev_nlive = champ.curr_nlive;
			champ.curr_nlive = 0;
		}
		ichamp++;
	}
}

static void	update_ctd(void)
{
	if (g_vm.curr_nlive >= NBR_LIVE ||
		g_vm.checks_since_change >= MAX_CHECKS)
	{
		g_vm.cycles_to_die -= CYCLE_DELTA;
		g_vm.checks_since_change = 0;
		if ((g_vm.log >> 1) & 1)
			ft_printf("Cycle to die is now %li\n", g_vm.cycles_to_die);
	}
}

int			run_once(void)
{
	if (g_vm.nprocs == 0)
		return (0);
	++g_vm.icycle;
	if (g_vm.log >> 1 & 1)
		ft_printf("It is now cycle %lu\n", g_vm.icycle);
	// update_opcodes();
	cycle();
	if (g_vm.dump_flag && g_vm.dump_ncycles <= g_vm.icycle)
		dump();
	++g_vm.cycles_since_die;
	if (g_vm.cycles_to_die <= 0 ||
		g_vm.cycles_since_die == g_vm.cycles_to_die)
	{
		decimate();
		update_champs();
		update_ctd();
		g_vm.cycles_since_die = 0;
		g_vm.checks_since_change++;
		g_vm.prev_nlive = g_vm.curr_nlive;
		g_vm.curr_nlive = 0;
	}
	return (1);
}

void 		run(void)
{
	while (run_once())
		continue ;	
}
