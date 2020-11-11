/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:12:17 by user              #+#    #+#             */
/*   Updated: 2020/11/11 17:00:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_instruct	dispatcher[NUM_INSTRUCT + 1] = {
	NULL,
	live_instruct,
	ld_instruct,
	st_instruct,
	add_instruct,
	sub_instruct,
	and_instruct,
	or_instruct,
	xor_instruct,
	zjmp_instruct,
	ldi_instruct,
	sti_instruct,
	fork_instruct,
	lld_instruct,
	lldi_instruct,
	lfork_instruct,
	aff_instruct,
};

void				dispatch(t_proc *proc)
{
	int	ret;

	if ((g_vm.log >> 2) & 1)
		print_proc(proc);
	ret = dispatcher[proc->opcode](proc);
	if ((g_vm.log >> 2) & 1)
		ft_printf(INSTRUCT_PREFIX "%s\n", ret ? "FAIL" : "OK");
}
