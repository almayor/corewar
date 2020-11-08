/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 11:41:14 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	g_vm;

void	print_args(void)
{
	ft_printf("\n");
	for(int i = 0; i < 4; i++)
	{
		ft_printf("fd: %d, num: %d, name: %s\n", g_vm.args[i].fd,
			g_vm.args[i].num, g_vm.args[i].fname);
	}
}

void	print_logs(void) // DEL
{
	int i;

	i = 0;
	ft_printf("\n");
	while (i < 4)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			ft_printf("   name: %s\n", g_vm.champs[i].name);
			ft_printf("    num: %u\n", g_vm.champs[i].ichamp);
			ft_printf("comment: %s\n", g_vm.champs[i].comment);
			ft_printf("   size: %u\n", g_vm.champs[i].size);
			ft_printf("--------------------------------\n");
		}
		i++;
	}
}

void	print_greeting(void)
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

void	print_usage(void)
{
	ft_printf("usage:\n");
	ft_printf("\t./corewar [-n N <file.cor> | -dump N | -log] <file.cor> <...>\n");
	ft_printf("\t%-20s Set every player his number (N)\n", "-n N <file.cor>");
	ft_printf("\t%-20s Output memory field after N cycles\n", "-dump N");
	ft_printf("\t%-20s Output player actions every cycle\n", "-log"); // ???
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	ft_memset(&g_vm, 0, sizeof(t_vm));
	if (argc > 1)
	{
		read_args(argc, argv);
		load_all_champions();
		//print_args();
		//print_logs();
		print_greeting();
		if (g_vm.dump_flag)
			print_dump();
	}
	else
		print_usage();
	return (0);
}
