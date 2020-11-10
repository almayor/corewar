/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/11 00:11:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	sti_instruct(t_proc *proc)
{
	int32_t		in1;
	int32_t		in2;
	int32_t		in3;

	if (load_argument(proc, 0, &in1) ||
		load_argument(proc, 1, &in2) ||
		load_argument(proc, 2, &in3))
		return (1);
	// proc->carry = (in1 == 0);
	if ((g_vm.log >> 2) & 1)
		ft_printf(
			INSTRUCT_PREFIX "store at %i + (%i + %i) %% %i = %i\n"
			INSTRUCT_PREFIX "storing %i\n",
			proc->pc, in2, in3, IDX_MOD,
			proc->pc + (in2 + in3) % IDX_MOD, in1);
	mem_write(proc->pc + (in2 + in3) % IDX_MOD, in1, 4);
	return (0);
}
