#include "corewar.h"

void	lld_instruct(t_proc *proc)
{
	uint32_t	in;

	if (get_argument(proc, 0, &in))
		return ;
	proc->carry = in != 0;
	put_argument(proc, 1, in);
}
