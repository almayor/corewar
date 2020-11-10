/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:43 by user              #+#    #+#             */
/*   Updated: 2020/11/10 20:32:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t	mem_read(int32_t pos, int nbytes)
{
	uint32_t	val;

	pos = pos < 0 ? (pos % MEM_SIZE) + MEM_SIZE : pos % MEM_SIZE;
	val = 0;
	if (nbytes >= 4)
	{
		val |= g_vm.mem[pos++ % MEM_SIZE] << 24;
		val |= g_vm.mem[pos++ % MEM_SIZE] << 16;
	}
	if (nbytes >= 2)
		val |= g_vm.mem[pos++ % MEM_SIZE] << 8;
	if (nbytes >= 1)
		val |= g_vm.mem[pos++ % MEM_SIZE];
	if (nbytes == 4)
		return (*(int32_t *)&val);
	if (nbytes == 2)
		return (*(int16_t *)&val);
	else
		return (*(int8_t *)&val);
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
