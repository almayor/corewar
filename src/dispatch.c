/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:12:17 by user              #+#    #+#             */
/*   Updated: 2020/11/10 20:55:04 by user             ###   ########.fr       */
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

static void 		read_arguments(t_proc *proc)
{
	int			len;
	int32_t		pc;
	int			i;

	ft_memset(proc->args, 0, sizeof(int32_t) * 3);
	pc = proc->pc + 1 + g_op_tab[proc->opcode].type_octet;
	i = 0;
	while (i < g_op_tab[proc->opcode].nargs)
	{
		len = get_arg_length(proc, i);
		proc->args[i] = mem_read(pc, len);
		pc = (pc + len) % MEM_SIZE;
		i++;
	}
}

void				dispatch(t_proc *proc)
{
	int	ret;

	read_arguments(proc);
	if ((g_vm.log >> 2) & 1)
		print_proc(proc);
	ret = dispatcher[proc->opcode](proc);
	if ((g_vm.log >> 2) & 1)
		ft_printf(INSTRUCT_PREFIX "%s\n", ret ? "FAIL" : "OK");
}
