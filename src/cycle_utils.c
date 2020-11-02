#include "corewar.h"

t_arg_type	get_arg_type(t_proc *proc, int n)
{
	uint8_t	octet;

	if (proc->opcode == 1 || proc->opcode == 9 ||
		proc->opcode == 12 || proc->opcode == 15)
		return (DIR_CODE);
	octet = g_vm.mem[(proc->pc + 1) % MEM_SIZE];
	return ((octet >> 2 * n) & 0x3)
}

uint32_t	get_arg_length(t_proc *proc, int n)
{
	t_arg_type	type;

	type = get_arg_type(proc, i);
	if (type == REG_CODE)
		return (REG_SIZE);
	if (type == DIR_CODE && g_opt_tab[proc->opcode].direct_size)
		return (DIR_SIZE / 2);
	if (type == DIR_CODE)
		return (DIR_SIZE);
	if (type == IND_CODE)
		return (IND_SIZE);
}

uint32_t	get_instruction_length(t_proc *proc)
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
