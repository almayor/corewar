/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/11 20:16:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	lldi_instruct(t_proc *proc)
{
	int32_t	in1;
	int32_t	in2;
	int32_t	out;

	if (load_argument(proc, 0, &in1) ||
		load_argument(proc, 1, &in2))
		return (1);
	out = in1 + in2;
	proc->carry = (out == 0);
	if ((g_vm.log >> 2) & 1)
		ft_printf(LOG_OPER_PREFIX "%i + %i = %i (carry = %i)\n",
			in1, in2, out, proc->carry);
	return (put_argument(proc, 2, out));
}
