#include "corewar.h"

void	zjump_instruct(t_proc *proc)
{
	int16_t	dest;

	if (!proc->carry)
		return ;
	dest = read_16bit(proc->pc + 1);
	proc->pc = (proc + dest) % MEM_SIZE;
}
