/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/06 14:38:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_instruct(t_proc *proc)
{
	uint32_t	ichamp;

	ichamp = read_32bit(proc + 1);
	if (ichamp < MAX_PLAYERS)
	{
		proc->cycles_since_live = 0;
		g_vm.champs[ichamp - 1].curr_nlive++;
		g_vm.curr_nlive++;
		g_vm.last_live_champ = ichamp;
		ft_printf(PLAYER_ALIVE, ichamp, g_vm.champs[ichamp - 1].name);
	}
}
