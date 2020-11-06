/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/06 15:23:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	zjump_log(t_proc *proc)
{
	ft_printf(
		"Process at PC = %u, "
		"created by champion %i (%s), "
		"has executed `zjump`\n",
		proc->pc, proc->ichamp, g_vm.champs[proc->ichamp - 1].name
	);
}

void		zjump_instruct(t_proc *proc)
{
	int16_t	dest;

	if (!proc->carry)
		return ;
	if (g_vm.log_flag == LOG_EXTRA)
		zjump_log(proc);
	dest = read_16bit(proc->pc + 1);
	proc->pc = (proc + dest) % MEM_SIZE;
}
