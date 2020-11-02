#include "corewar.h"

void	live_instruct(t_proc *proc)
{
	uint8_t			octet;
	uint32_t		ichamp;
	t_arg_type		arg_type;

	octet = g_vm->mem[proc->pc++ % MEM_SIZE];
	arg_type = 1 << (octet & 0x3);
	if (arg_type == DIR_CODE)
	{
		ichamp = *(uint32_t *)(g_vm->mem + proc->pc % MEM_SIZE);
		if (ichamp < MAX_PLAYERS && g_vm->champs[ichamp])
		{
			proc->cycles_since_live = 0;
			g_vm->curr_nlive++;
			g_vm->champs[ichamp]->curr_nlive++;
		}
		proc->pc = proc->pc + 
	}
}

