#include "corewar.h"

int	check_octet(uint8_t opcode, uint8_t octet)
{
	int	i;

	i = 0;
	while (i < g_op_tab[opcode].nargs)
	{
		arg_type = 1 << (octet & 0x3);
		if (g_op_tab[opcode].arg_types[i] & arg_type == 0)
			return (1);
		octet >>= 2;
		i++;
	}
	return (0);
}
