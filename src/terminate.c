#include "corewar.h"

static void	free_procs(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		free(proc);
		proc = proc->next;
	}
}

void		terminate(int ret)
{
	free_procs();
	exit(ret);
}
