/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/10 00:56:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	save_player(int num, const char *name, char *snum)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (i > MAX_PLAYERS - 1)
		terminate(MANY_PLAYERS);
	else
	{
		while (j < MAX_PLAYERS)
		{
			if (g_vm.args[j].num > 0 && g_vm.args[j].num == num)
				terminate(PROG_NUM_USED, NULL, snum);
			j++;
		}
		g_vm.args[i].num = num;
		g_vm.args[i].fname = name;
		g_vm.nchamps++;
		i++;
	}
}

static void	validate_n(int argc, char **argv, int *i)
{
	int num;

	if (*i + 2 > argc - 1)
		terminate(NOT_ENOUGH_N);
	(*i)++;
	if (ft_strlen(argv[*i]) > 1 || !ft_isdigit(argv[*i][0]))
		terminate(BAD_N_FORMAT, argv[*i]);
	num = ft_atoi(argv[*i]);
	if (num > MAX_PLAYERS || num < 1)
		terminate(N_OUT_OF_RANGE);
	save_player(num, argv[(*i) + 1], argv[*i]);
	(*i)++;
}

static void	read_keys(int argc, char **argv, int *i)
{
	if (!ft_strcmp("-n", argv[*i]))
		validate_n(argc, argv, i);
	else if (!ft_strcmp(argv[*i], "-dump"))
		validate_dump(argc, argv, i);
	else
		terminate(INVALID_KEY, argv[*i]);
}

void		parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			read_keys(argc, argv, &i);
		else
			save_player(-1, argv[i], NULL);
		i++;
	}
	init_numbers();
}
