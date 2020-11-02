#include "vm.h"

static const t_instruct dispatcher[NUM_INSTRUCT + 1] = { 
	NULL,
	&live_instruct,
	&ld_instruct,
	&st_instruct,
	&add_instruct,
	&sub_instruct,
	&and_instruct,
	&or_instruct,
	&xor_instruct,
	&zjump_instruct,
	&ldi_instruct,
	&sti_instruct,
	&fork_instruct,
	&lld_instruct,
	&lldi_instruct,
	&lfork_instruct,
	&aff_instruct,
}

void	cycle(void)
{
	t_proc	*proc;
	uint8_t	opcode;

	proc = g_vm->procs;
	while (proc)
	{
		proc->cycles_since_live++;
		if (proc->cycles_busy)
			proc->cycles_busy--;
		else
		{
			opcode = g_vm->mem[proc->pc++ % MEM_SIZE];
			if (opcode > 0 && opcode <= NUM_INSTRUCT)
			{
				dispatcher[opcode](proc);
				proc->cycles_busy = g_op_specif[opcode]->duration;
			}
		}
		proc = proc->next;
	}
}
