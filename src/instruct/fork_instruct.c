#include "corewar.h"

void	fork_instruct(t_proc *proc)
{
	t_proc	*new;
	int16_t	in;

	get_argument(proc, 0, &in);
	new = ft_xmalloc(sizeof(t_proc));
	*new = *proc;
	new->pc = (in % IDX_MOD);
	new->next = g_vm.procs;
	g_vm.procs = new;
	g_vm.nprocs++;
}
