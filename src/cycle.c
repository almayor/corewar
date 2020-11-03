#include "corewar.h"

static g_instruct	dispatcher[NUM_INSTRUCT + 1] = {
	NULL,
	live_instruct,
	ld_instruct,
	st_instruct,
	add_instruct,
	sub_instruct,
	and_instruct,
	or_instruct,
	xor_instruct,
	zjmp_instruct,
	ldi_instruct,
	sti_instruct,
	fork_instruct,
	lld_instruct,
	lldi_instruct,
	lfork_instruct,
	aff_instruct,
}

static int			check_instruction(t_proc *proc)
{
	t_arg_type	arg_type;
	int			i;

	if (proc->opcode == 0 || proc->opcode > NUM_INSTRUCT)
		return (0);
	if (proc->opcode == 1 || proc->opcode == 9 ||
		proc->opcode == 12 || proc->opcode == 15)
		return (1);
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		arg_type = get_arg_type(proc, i);
		if (1 << arg_type & g_op_tab[proc->opcode].type_mask[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static uint32_t		get_instruction_length(t_proc *proc)
{
	uint32_t	length;
	int			i;

	if (proc->opcode == 0 && proc->opcode > NUM_INSTRUCT)
		return (1);
	length = 1;
	if (proc->opcode != 1 && proc->opcode != 9 &&
		proc->opcode != 12 && proc->opcode != 15)
		length++;
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		length += get_arg_length(proc, i);
		i++;
	}
	return (length);
}

static void 		advance(t_proc *proc)
{
	proc->pc = (proc->pc + get_instruction_length(proc)) % MEM_SIZE;
	proc->opcode = g_vm.mem[proc->pc];
	if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
		proc->cycles_busy = g_op_tab[proc->opcode].duration;
	else
		proc->opcode = 0;
}

void				cycle(void)
{
	t_proc	*proc;

	proc = g_vm->procs;
	while (proc)
	{
		proc->cycles_since_live++;
		if (proc->cycles_busy)
			proc->cycles_busy--;
		else
		{
			if (check_instruction(proc) == 0)
				dispatcher[proc->opcode](proc);
			advance(proc);
		}
		proc = proc->next;
	}
}
