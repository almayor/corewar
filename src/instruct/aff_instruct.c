/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/17 03:13:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff_instruct(t_proc *proc)
{
	uint32_t	in;

	if (load_argument(proc, 0, (int32_t *)&in))
		return (1);
	// proc->carry = (in == 0);
	if (g_vm.aff_flag)
		ft_printf("%c", (char)(in % 256));
	// if ((g_vm.log >> 2) & 1)
	// 	ft_printf(INSTRUCT_PREFIX "(carry = %i)\n", proc->carry);
	return (0);
}
