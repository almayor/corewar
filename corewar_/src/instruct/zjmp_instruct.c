/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/11 20:16:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		zjmp_instruct(t_proc *proc)
{
	int16_t	in;

	if (proc->carry)
	{
		in = mem_read(proc->pc + 1, 2);
		if ((g_vm.log >> 2) & 1)
			ft_printf(LOG_OPER_PREFIX "%i + (%i %% %i) = %i\n",
				proc->pc, in, IDX_MOD, (proc->pc + (in % IDX_MOD)) % MEM_SIZE);
		proc->pc = proc->pc + (in % IDX_MOD);
		proc->pc %= MEM_SIZE;
		proc->pc = proc->pc < 0 ? proc->pc + MEM_SIZE : proc->pc;
		return (0);
	}
	else if ((g_vm.log >> 2) & 1)
		ft_printf(LOG_OPER_PREFIX "ignored as carry = 0\n");
	return (1);
}
