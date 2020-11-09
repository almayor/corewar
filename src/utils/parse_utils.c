/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:07:35 by fallard           #+#    #+#             */
/*   Updated: 2020/11/09 19:41:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_contain(int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.args[i].num == n)
			return (1);
		i++;
	}
	return (0);
}

void		init_numbers(void)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		if (g_vm.args[i].num < 0)
		{
			while (j < 4)
			{
				if (!is_contain(j + 1))
					break ;
				j++;
			}
			g_vm.args[i].num = j + 1;
		}
		i++;
	}
}

int			get_nbr_champions(void)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (g_vm.args[i].num > 0)
			count++;
		i++;
	}
	return (count);
}
