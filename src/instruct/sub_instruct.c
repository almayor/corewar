/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/06 14:38:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub_instruct(t_proc *proc)
{
	int32_t	in1;
	int32_t	in2;
	int32_t	out;

	if (get_argument(proc, 0, &in1) ||
		get_argument(proc, 1, &in2))
		return ;
	out = in1 - in2;
	proc->carry = out == 0;
	put_argument(proc, 2, out);
}
