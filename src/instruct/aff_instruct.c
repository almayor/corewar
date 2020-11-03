#include "corewar.h"

void	aff_instruct(t_proc *proc)
{
	uint32_t	in;

	if (get_argument(proc, 0, &in))
		return ;
	proc->carry = in == 0;
	ft_printf("%c", in % 256);
}
