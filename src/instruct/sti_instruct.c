/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/18 23:38:31 by fallard          ###   ########.fr       */
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
			LOG_OPER_PREFIX "store at %i + (%i + %i) %% %i = %i\n"
			LOG_OPER_PREFIX "storing %i\n",
			proc->pc, in2, in3, IDX_MOD,
			proc->pc + (in2 + in3) % IDX_MOD, in1);
	mem_write(proc->ichamp, proc->pc + (in2 + in3) % IDX_MOD, in1, 4);
	return (0);
}
