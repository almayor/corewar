#include "corewar.h"

t_vm	g_vm = {{0}, {NULL}, 0, {NULL}, 0, 0, CYCLE_TO_DIE, 0, 0, 0};

static void	init_proc(void)
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

static 
