/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/10 23:25:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ldi_instruct(t_proc *proc)
{
	int32_t	in1;
	int32_t	in2;
	int32_t	out;

	if (load_argument(proc, 0, &in1) ||
		load_argument(proc, 1, &in2))
		return (1);
	out = mem_read(proc->pc + ((in1 + in2) % IDX_MOD), 4);
	proc->carry = (out == 0);
	if ((g_vm.log >> 2) & 1)
		ft_printf(
			INSTRUCT_PREFIX "load from %i + ((%i + %i) %% %i) = %i\n"
			INSTRUCT_PREFIX "loaded %i (carry = %i)\n",
			proc->pc, in1, in2, IDX_MOD,
			(proc->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE,
			out, proc->carry);
	return (put_argument(proc, 2, out));
}
