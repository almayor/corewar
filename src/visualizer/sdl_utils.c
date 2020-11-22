/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:58:07 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 18:21:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

void		sdl_mark_champ(uint32_t ichamp, size_t nbytes, uint32_t pos)
{
	size_t i;

	i = 0;
	while (i < nbytes)
	{
		g_visu.vmem[pos % MEM_SIZE] = ichamp;
		pos++;
		i++;
	}
}

t_proc		*get_proc(uint32_t index)
{
	t_proc	*tmp;

	tmp = g_vm.procs;
	while (tmp)
	{
		if ((uint32_t)tmp->pc == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

SDL_Color	get_player_color(uint32_t ichamp)
{
	SDL_Color res;

	if (ichamp == 1)
		res = (SDL_Color){240, 240, 0, 255};
	else if (ichamp == 2)
		res = (SDL_Color){255, 30, 30, 255};
	else if (ichamp == 3)
		res = (SDL_Color){0, 190, 150, 255};
	else if (ichamp == 4)
		res = (SDL_Color){20, 110, 250, 255};
	else
		res = (SDL_Color){255, 255, 255, 255};
	return (res);
}
