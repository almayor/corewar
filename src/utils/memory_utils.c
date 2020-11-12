/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:43 by user              #+#    #+#             */
/*   Updated: 2020/11/12 16:16:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t	mem_read(int32_t pos, int nbytes)
{
	t_int	val;

	pos = pos < 0 ? (pos % MEM_SIZE) + MEM_SIZE : pos % MEM_SIZE;
	val.uint32 = 0;
	if (nbytes >= 4)
	{
		val.uint32 |= g_vm.mem[pos++ % MEM_SIZE] << 24;
		val.uint32 |= g_vm.mem[pos++ % MEM_SIZE] << 16;
	}
	if (nbytes >= 2)
		val.uint32 |= g_vm.mem[pos++ % MEM_SIZE] << 8;
	if (nbytes >= 1)
		val.uint32 |= g_vm.mem[pos++ % MEM_SIZE];
	if (nbytes == 4)
		return (val.int32);
	if (nbytes == 2)
		return (val.int16);
	else
		return (val.int8);
}

void	mem_write(int32_t pos, int32_t val, int nbytes)
{
	pos = pos < 0 ? (pos % MEM_SIZE) + MEM_SIZE : pos % MEM_SIZE;
	if (nbytes >= 4)
	{
		g_vm.mem[pos++ % MEM_SIZE] = val >> 24;
		g_vm.mem[pos++ % MEM_SIZE] = val >> 16;
	}
	if (nbytes >= 2)
		g_vm.mem[pos++ % MEM_SIZE] = val >> 8;
	if (nbytes >= 1)
		g_vm.mem[pos++ % MEM_SIZE] = val;
}
