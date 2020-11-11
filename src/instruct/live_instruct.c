/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/11 16:37:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		live_instruct(t_proc *proc)
{
	int32_t	n;

	g_vm.curr_nlive++;
	proc->cycles_since_live = 0;
	n = -mem_read(proc->pc + 1, 4);
	if (n > 0 && n <= MAX_PLAYERS && g_vm.champs[n - 1].ichamp > 0)
	{
		g_vm.champs[n - 1].curr_nlive++;
		g_vm.last_live_champ = n;
		if (g_vm.log & 1)
			ft_printf(CHAMP_ALIVE, n, g_vm.champs[n - 1].name);
		return (0);
	}
	return (1);
}
