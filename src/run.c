#include "corewar.h"

static void decimate(void)
{
	t_proc	*proc_curr;
	t_proc	*proc_next;

	while ((proc_curr = g_vm->procs) &&
			proc_curr->cycles_since_live >= g_vm->cycles_to_die)
	{
		g_vm->procs = g_vm->next;
		free(proc_curr);
		g_vm->nprocs--;
	}
	while (proc_curr && proc_curr->next)
	{
		proc_next = proc_curr->next;
		if (proc_next->cycles_since_live >= g_gm->cycles_to_die)
		{
			proc_curr->next = proc_next->next;
			free(proc_next);
			g_vm->nprocs--;
		}
		else
			proc_curr = proc_next;
	}
}

static void	update_champs(void)
{
	int		ichamp;
	t_champ	champ;

	ichamp = 1;
	while (ichamp <= MAX_PLAYERS)
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

int 		run(void)
{
	while (g_vm.nprocs)
	{
		if (g_vm.key_dump && g_vm.dump_ncycles-- > 0)
			dump();
		cycle();
		g_vm.cycles_since_die++;
		g_vm.cycles_since_change++;
		if (g_vm.cycles_since_die == g_vm.cycles_to_die)
		{
			if (g_vm.curr_nlive >= NBR_LIVE ||
				g_vm.cycles_since_change >= MAX_CHECKS)
			{
				g_vm.cycles_to_die -= CYCLE_DELTA;
				g_vm.cycles_since_change = 0;
			}
			decimate();
			g_vm.curr_nlive = 0;
			update_champs();
		}
	}	
}
