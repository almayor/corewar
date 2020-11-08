/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 12:36:27 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	save_player(int num, char *name, char *snum)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (i > 3)
		put_error("%s\n", NULL, MANY_PLAYERS);
	else
	{
		while (j < 4)
		{
			if (g_vm.args[j].num > 0 && g_vm.args[j].num == num)
				put_error(PROG_NUM_USED, NULL, snum);
			j++;
		}
		g_vm.args[i].num = num;
		g_vm.args[i].fname = name;
		i++;
	}
}

static void	validate_n(int argc, char **argv, int *i)
{
	int num;

	if (*i + 2 > argc - 1)
		put_error("%s\n", NULL, NOT_ENOUGH_N);
	(*i)++;
	if (ft_strlen(argv[*i]) > 1 || !ft_isdigit(argv[*i][0]))
		put_error(BAD_N_FORMAT, NULL, argv[*i]);
	num = ft_atoi(argv[*i]);
	if (num > 4 || num < 1)
		put_error("%s\n", NULL, OUT_OF_RANGE);
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
		put_error("Invalid key: %s\n", NULL, argv[*i]);
}

void		read_args(int argc, char **argv)
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
