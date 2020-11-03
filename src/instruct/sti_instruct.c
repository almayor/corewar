#include "corewar.h"

void	sti_instruct(t_proc *proc)
{
	uint32_t	in1;
	int32_t		in2;
	int32_t		in3;

	if (get_argument(proc, 0, &in1) ||
		get_argument(proc, 1, &in2) ||
		get_argument(proc, 2, &in3))
		return ;
	proc->carry = in1 != 0;
	write_32bit(proc + (in2 + in3) % IDX_MOD, in1);
}
