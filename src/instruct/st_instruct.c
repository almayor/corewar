/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:07 by user              #+#    #+#             */
/*   Updated: 2020/11/13 10:42:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	st_instruct(t_proc *proc)
{
	int32_t		in;
	t_arg_type	type;

	if (load_argument(proc, 0, &in))
		return (1);
	type = get_arg_type(proc, 1);
	if ((g_vm.log >> 2) & 1)
	{
		if (type == T_IND)
			ft_printf(LOG_OPER_PREFIX "store at %i + (%i %% %i) = %i\n",
				proc->pc, proc->args[1], IDX_MOD,
				proc->pc + (proc->args[1] % IDX_MOD));
		else
			ft_printf(LOG_OPER_PREFIX "store at r%i\n", proc->args[1]);
		ft_printf(LOG_OPER_PREFIX "storing %i\n", in);
	}
	return (put_argument(proc, 1, in));
}
