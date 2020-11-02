#include "corewar.h"

void decimate(void)
{
	t_proc	*proc_curr;
	t_proc	*proc_next;

	while ((proc_curr = g_vm->procs) &&
			proc_curr->cycles_since_live > g_vm->cycles_to_die)
	{
		g_vm->procs = g_vm->next;
		free(proc_curr);
		g_vm->nprocs--;
	}
	while (proc_curr && proc_curr->next)
	{
		proc_next = proc_curr->next;
		if (proc_next->cycles_since_live > g_gm->cycles_to_die)
		{
			proc_curr->next = proc_next->next;
			free(proc_next);
			g_vm->nprocs--;
		}
		else
			proc_curr = proc_next;
	}
}
