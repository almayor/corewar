/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:07:35 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 14:14:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_contain(int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.temp[i].num == n)
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
		if (g_vm.temp[i].num < 0)
		{
			while (j < 4)
			{
				if (!is_contain(j + 1))
					break ;
				j++;
			}
			g_vm.temp[i].num = j + 1;
		}
		i++;
	}
}

int			is_number(const char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (1);
		i++;
	}
	return (0);
}
