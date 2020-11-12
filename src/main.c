/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/12 21:25:04 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	g_vm = { .cycles_to_die = CYCLE_TO_DIE, .log = 0 };

static void	conclude(void)
{
	t_champ	champ;

	if (g_vm.last_live_champ == 0)
		ft_printf(NO_LIVE);
	else
	{
		champ = g_vm.champs[g_vm.last_live_champ - 1];
		ft_printf(CHAMP_WON, champ.ichamp, champ.name);
	}
}

static void	greet(void)
{
	int i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < 4)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			g_vm.champs[i].ichamp, g_vm.champs[i].size, g_vm.champs[i].name,
			g_vm.champs[i].comment);
		}
		i++;
	}
}

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("\tcorewar [-n N <file.cor> | -dump N | -log N] <file.cor> <...>\n");
	ft_printf("\t%-20s : Set player number (N)\n", "-n N <file.cor>");
	ft_printf("\t%-20s : Dumps memory after N cycles, then exits\n", "-dump N");
	ft_printf("\t%-20s : Verbosity levels, can be added together to enable several\n", "-log N");
	ft_printf("\t\t- %-2i : %s\n", 0, "only essentials");
	ft_printf("\t\t- %-2i : %s\n", 1, "lives");
	ft_printf("\t\t- %-2i : %s\n", 2, "cycles");
	ft_printf("\t\t- %-2i : %s\n", 4, "operations (incl. parameters)");
	ft_printf("\t\t- %-2i : %s\n", 8, "creation and removal of processes");
	ft_printf("\t\t- %-2i : %s\n", 16, "PC movements (except for jumps)");
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		print_usage();
		exit(EXIT_SUCCESS);
	}
	parse_args(argc, argv);
	load();
	greet();
	run();
	conclude();
	cleanup();
	return (EXIT_SUCCESS);
}
