/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:33 by user              #+#    #+#             */
/*   Updated: 2020/11/09 22:42:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	free_procs(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		free(proc);
		proc = proc->next;
	}
}

void		cleanup(void)
{
	free_procs();
}

void		terminate(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_vdprintf(STDERR_FILENO, format, ap);
	va_end(ap);
	cleanup();
	exit(EXIT_FAILURE);
}
