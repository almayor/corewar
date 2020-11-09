/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/09 20:55:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	save_player(int num, const char *name, char *snum, t_args *args)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (i > 3)
		terminate(MANY_PLAYERS);
	else
	{
		while (j < 4)
		{
			if (g_vm.args[j].num > 0 && g_vm.args[j].num == num)
				terminate(PROG_NUM_USED, NULL, snum);
			j++;
		}
		g_vm.args[i].num = num;
		g_vm.args[i].fname = name;
		i++;
	}
}

static void	validate_n(int argc, char **argv, int *i, t_args *args)
{
	int num;

	if (*i + 2 > argc - 1)
		terminate(NOT_ENOUGH_N);
	(*i)++;
	if (ft_strlen(argv[*i]) > 1 || !ft_isdigit(argv[*i][0]))
		terminate(BAD_N_FORMAT, argv[*i]);
	num = ft_atoi(argv[*i]);
	if (num > 4 || num < 1)
		terminate(N_OUT_OF_RANGE);
	save_player(num, argv[(*i) + 1], argv[*i], args);
	(*i)++;
}

static void	read_keys(int argc, char **argv, int *i, t_args *args)
{
	if (!ft_strcmp("-n", argv[*i]))
		validate_n(argc, argv, i, args);
	else if (!ft_strcmp(argv[*i], "-dump"))
		validate_dump(argc, argv, i);
	else
		terminate(INVALID_KEY, argv[*i]);
}

void		read_args(int argc, char **argv, t_args *args)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			read_keys(argc, argv, &i, args);
		else
			save_player(-1, argv[i], NULL, args);
		i++;
	}
	init_numbers();
}
