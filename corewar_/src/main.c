/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:43:48 by user              #+#    #+#             */
/*   Updated: 2020/11/25 22:51:19 by user             ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	if (argc == 1)
		help();
	parse_args(argc, argv);
	load();
	greet();
	if (g_vm.visu_flag)
		SDL_ENTRY;
	else
		run();
	conclude();
	cleanup();
	return (EXIT_SUCCESS);
}
