#include "corewar.h"

t_arg_type	get_arg_type(t_proc *proc, int n)
{
	uint8_t	octet;

	if (proc->opcode == 1 || proc->opcode == 9 ||
		proc->opcode == 12 || proc->opcode == 15)
		return (DIR_CODE);
	octet = g_vm.mem[(proc->pc + 1) % MEM_SIZE];
	return ((octet >> (2 * n)) & 0x3)
}

uint32_t	get_arg_length(t_proc *proc, int n)
{
	t_arg_type	type;

	type = get_arg_type(proc, n);
	if (type == REG_CODE)
		return (REG_SIZE);
	if (type == DIR_CODE && g_opt_tab[proc->opcode].direct_size)
		return (DIR_SIZE / 2);
	if (type == DIR_CODE)
		return (DIR_SIZE);
	if (type == IND_CODE)
		return (IND_SIZE);
}

uint32_t	get_argument_literal(t_proc *proc, int n, t_arg_type type)
{
	int			type_octet;

	if (proc->opcode != 1 && proc->opcode != 9 &&
		proc->opcode != 12 && proc->opcode != 15)
		type_octet = 1;
	else
		type_octet = 0;
	if (type == REG_CODE)
		return (mem_read_8bit(proc->pc + 1 + type_octet + n));
	if (type == DIR_CODE && g_opt_tab[proc->opcode].direct_size)
		return (mem_read_16bit(proc->pc + 1 + type_octet + n));
	if (type == DIR_CODE)
		return (mem_read_32bit(proc->pc + 1 + type_octet + n));
	if (type == IND_CODE)
		return (mem_read_16bit(proc->pc + 1 + type_octet + n));
}

int			get_argument(t_proc *proc, int n, uint32_t *arg)
{
	t_arg_type	type;
	uint32_t	lit;

	type = get_arg_type(proc, n);
	lit = get_argument_literal(proc, n, type);
	if (type == REG_CODE && lit >= REG_NUMBER)
		return (1);
	else if (type = REG_CODE)
		*arg = proc->reg[lit];
	else if (type == IND_CODE && g_op_tab[proc->opcode].addr_restrict)
		*arg = mem_read_32bit(proc->pc + (lit % IDX_MOD));
	else if (type == IND_CODE)
		*arg = mem_read_32bit(proc->pc + lit);
	else
		*arg = lit;
	return (0);
}

int			put_argument(t_proc *proc, int n, uint32_t val)
{
	t_arg_type	type;
	uint32_t	lit;

	type = get_arg_type(proc, n);
	lit = get_argument_literal(proc, n, type);
	if (type == REG_CODE && lit >= REG_NUMBER)
		return (1);
	else if (type == REG_CODE)
		proc->reg[lit] = val;
	else if (type == IND_CODE && g_op_tab[proc->opcode].addr_restrict)
		mem_write_32bit(proc->pc + (lit % IDX_MOD));
	else
		mem_write_32bit(proc->pc + lit);
	return (0);
}
