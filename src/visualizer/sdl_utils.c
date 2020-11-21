/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:58:07 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 23:42:59 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

void		sdl_mark_champ(uint32_t ichamp, size_t nbytes, uint32_t pos)
{
	int i;

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
		if (tmp->pc == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

SDL_Color	get_player_color(uint32_t ichamp)
{
	SDL_Color res;

	if (ichamp == 1)
		res = (SDL_Color){240, 240, 0, 1};
	else if (ichamp == 2)
		res = (SDL_Color){255, 30, 30, 1};
	else if (ichamp == 3)
		res = (SDL_Color){0, 190, 150, 1};
	else if (ichamp == 4)
		res = (SDL_Color){20, 110, 250, 1};
	else
		res = (SDL_Color){255, 255, 255, 1};
	return (res);
}
