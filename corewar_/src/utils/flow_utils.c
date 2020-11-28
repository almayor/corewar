/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <kysgramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:33 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/25 22:54:35 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	free_procs(void)
{
	t_proc	*proc;
	t_proc	*tmp;

	proc = g_vm.procs;
	while (proc)
	{
		tmp = proc->next;
		free(proc);
		proc = tmp;
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
	SDL_CLEANUP;
	exit(EXIT_FAILURE);
}

void		help(void)
{
	ft_printf(
		"Usage:");
	ft_printf(
	"\t./corewar [-n N <file.cor> | -dump N | -log N | -v] <file.cor> <...>\n");
	ft_printf(
		"\t%-20s : Print help and exit\n", "--help");
	ft_printf(
		"\t%-20s : Launch corewar with graphic visualizer\n", "-v");
	ft_printf(
		"\t%-20s : Set player number (N) [1-4]\n", "-n N <file.cor>");
	ft_printf(
		"\t%-20s : Dumps memory after N cycles, then exits\n", "-dump N");
	ft_printf("\t%-20s : Print output from `aff` instructions "
		"(default is to hide it)\n", "-a");
	ft_printf(
		"\t%-20s : Verbosity levels, can be added together to enable several\n",
		"-log N");
	ft_printf("\t\t\t\t- %-2i : %s\n", 0, "only essentials");
	ft_printf("\t\t\t\t- %-2i : %s\n", 1, "lives");
	ft_printf("\t\t\t\t- %-2i : %s\n", 2, "cycles");
	ft_printf("\t\t\t\t- %-2i : %s\n", 4, "operations (incl. parameters)");
	ft_printf("\t\t\t\t- %-2i : %s\n", 8, "creation and removal of processes");
	ft_printf("\t\t\t\t- %-2i : %s\n", 16, "PC movements (except for jumps)");
	exit(EXIT_SUCCESS);
}
