/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/10 20:10:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	st_instruct(t_proc *proc)
{
	int32_t	in;

	if (load_argument(proc, 0, &in))
		return (1);
	proc->carry = (in == 0);
	return (put_argument(proc, 1, in));
}
