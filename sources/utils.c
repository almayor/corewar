/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:07:35 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 12:35:02 by fallard          ###   ########.fr       */
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

int			close_all_fd(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.args[i].fd > 0)
			close(g_vm.args[i].fd);
		i++;
	}
	return (1);
}

void		put_error(char *format, char *file, char *error)
{
	close_all_fd();
	if (file)
		ft_printf(format, file, error);
	else
		ft_printf(format, error);
	exit(EXIT_FAILURE);
}
