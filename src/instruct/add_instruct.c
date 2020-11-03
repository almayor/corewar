#include "corewar.h"

void	add_instruct(t_proc *proc)
{
	int32_t	in1;
	int32_t	in2;
	int32_t	out;

	if (get_argument(proc, 0, &in1) ||
		get_argument(proc, 1, &in2))
		return ;
	out = in1 + in2;
	proc->carry = out != 0;
	put_argument(proc, 2, out);
}
