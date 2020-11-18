/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:43 by user              #+#    #+#             */
/*   Updated: 2020/11/19 00:19:20 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t	mem_read(int64_t pos, int nbytes)
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

void	mem_write(uint32_t ichamp, int64_t pos, int32_t val, int nbytes)
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
	ft_printf("MEM WRITING........\n");
	if (g_vm.visu_flag)
		sdl_mark_champ(ichamp, nbytes, pos);
}
