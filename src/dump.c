/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:35:24 by fallard           #+#    #+#             */
/*   Updated: 2020/11/12 18:14:17 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_number(const char *string)
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

void		validate_dump(int argc, char **argv, int *i)
{
	int j;
	int digit;

	if (*i + 1 > argc - 1)
		terminate(NOT_ENOUGH, "-dump");
	(*i)++;
	if (is_number(argv[*i]))
		terminate(DUMP_INVALID, argv[*i]);
	j = 0;
	while (ft_isdigit(argv[*i][j]))
	{
		digit = argv[*i][j] - '0';
		if (g_vm.dump_ncycles > (ULONG_MAX - digit) / 10)
			terminate(DUMP_INVALID, argv[*i]);
		g_vm.dump_ncycles = (g_vm.dump_ncycles * 10) + digit;
		j++;
	}
	g_vm.dump_flag = 1;
}

void		dump(void)
{
	int i;
	int j;
	int shift;

	i = 0;
	j = 0;
	shift = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x :", shift);
		j = 0;
		while (j++ < 64)
			ft_printf(" %02x", g_vm.mem[i++]);
		ft_printf("\n");
		shift = shift + 64;
	}
	cleanup();
	exit(EXIT_SUCCESS);
}
