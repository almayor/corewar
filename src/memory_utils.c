/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:18:21 by user              #+#    #+#             */
/*   Updated: 2020/11/03 13:24:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int16_t	mem_read_16bit(uint32_t pos)
{
	int16_t	val;

	val = 0;
	val |= g_vm[pos++ % MEM_SIZE] << 8;
	val |= g_vm[pos++ % MEM_SIZE];
	return (val); 
}

int32_t	mem_read_32bit(uint32_t pos)
{
	int32_t	val;

	val = 0;
	val |= g_vm[pos++ % MEM_SIZE] << 24;
	val |= g_vm[pos++ % MEM_SIZE] << 16;
	val |= g_vm[pos++ % MEM_SIZE] << 8;
	val |= g_vm[pos++ % MEM_SIZE];
	return (val); 
}

int8_t	mem_read_8bit(uint32_t pos)
{
	return (g_vm[pos % MEM_SIZE]); 
}

void	mem_write_16bit(uint32_t pos, int16_t val)
{
	g_vm[pos++ % MEM_SIZE] = val >> 8;
	g_vm[pos++ % MEM_SIZE] = val;
}

void	mem_write_32bit(uint32_t pos, int32_t val)
{
	g_vm[pos++ % MEM_SIZE] = val >> 24;
	g_vm[pos++ % MEM_SIZE] = val >> 16;
	g_vm[pos++ % MEM_SIZE] = val >> 8;
	g_vm[pos++ % MEM_SIZE] = val;
}

void	mem_write_8bit(uint32_t pos, int8_t val)
{
	g_vm[pos % MEM_SIZE] = val;
}
