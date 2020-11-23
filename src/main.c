/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:43:48 by user              #+#    #+#             */
/*   Updated: 2020/11/23 18:14:08 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	g_vm = { .cycles_to_die = CYCLE_TO_DIE, .log = 0 };

static void	conclude(void)
{
	t_champ	champ;

	champ = g_vm.champs[g_vm.last_live_champ - 1];
	ft_printf(CHAMP_WON, champ.ichamp, champ.name);
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
	ft_printf(
		"Usage:");
	ft_printf(
		"\t./corewar [-n N <file.cor> | -dump N | -log N | -v] <file.cor> <...>\n");
	ft_printf(
		"\t%-20s : Launch corewar with graphic visualizer\n", "-v");
	ft_printf(
		"\t%-20s : Set player number (N) [1-4]\n", "-n N <file.cor>");
	ft_printf(
		"\t%-20s : Dumps memory after N cycles, then exits\n", "-dump N");
	ft_printf(
		"\t%-20s : Verbosity levels, can be added together to enable several\n",
		"-log N");
	ft_printf("\t%-20s : Print output from `aff` instructions "
		"(default is to hide it)\n", "");
	
	ft_printf("\t\t\t\t- %-2i : %s\n", 0, "only essentials");
	ft_printf("\t\t\t\t- %-2i : %s\n", 1, "lives");
	ft_printf("\t\t\t\t- %-2i : %s\n", 2, "cycles");
	ft_printf("\t\t\t\t- %-2i : %s\n", 4, "operations (incl. parameters)");
	ft_printf("\t\t\t\t- %-2i : %s\n", 8, "creation and removal of processes");
	ft_printf("\t\t\t\t- %-2i : %s\n", 16, "PC movements (except for jumps)");
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
	ft_printf("nchamps: %d", g_vm.nchamps);
	if (g_vm.visu_flag)
		SDL_ENTRY;
	else
		run();
	//ft_printf("cycle: %llu\n", g_vm.icycle);
	conclude();
	cleanup();
	return (EXIT_SUCCESS);
}
