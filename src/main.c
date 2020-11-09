/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/09 21:16:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	g_vm;

static void	print_usage(void)
{
	ft_printf("usage:\n");
	ft_printf("\t./corewar [-n N <file.cor> | -dump N | -log] <file.cor> <...>\n");
	ft_printf("\t%-20s Set every player his number (N)\n", "-n N <file.cor>");
	ft_printf("\t%-20s Output memory field after N cycles\n", "-dump N");
	ft_printf("\t%-20s Output player actions every cycle\n", "-log"); // ???
}

static void	greet(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			ft_printf("* Player %d, weight %u bytes, \"%s\" (\"%s\") !\n",
			g_vm.champs[i].ichamp, g_vm.champs[i].size, g_vm.champs[i].name,
			g_vm.champs[i].comment);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argс == 1)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	g_vm.cycles_to_die = CYCLE_TO_DIE;
	load(argc, argv);
	greet();
	run();
	cleanup();
	return (0);
}
