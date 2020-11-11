/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/11 20:16:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		fork_instruct(t_proc *proc)
{
	int32_t	in;

	if (load_argument(proc, 0, &in))
		return (1);
	if ((g_vm.log >> 2) & 1)
		ft_printf(LOG_OPER_PREFIX "%i + (%i %% %i) = %i\n",
			proc->pc, in, IDX_MOD, (proc->pc + (in % IDX_MOD)) % MEM_SIZE);
	fork_proc((proc->pc + (in % IDX_MOD)) % MEM_SIZE, proc);
	return (0);
}
