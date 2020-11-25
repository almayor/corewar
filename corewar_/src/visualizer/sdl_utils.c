/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:58:07 by fallard           #+#    #+#             */
/*   Updated: 2020/11/25 19:52:24 by user             ###   ########.fr       */
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

void		sdl_init_pmem(void)
{
	t_proc *tmp;

	ft_memset(g_visu.pmem, 0, sizeof(uint8_t) * MEM_SIZE);
	tmp = g_vm.procs;
	while (tmp)
	{
		g_visu.pmem[tmp->pc] = tmp->ichamp;
		tmp = tmp->next;
	}
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

void		sdl_put_text(const char *word, SDL_Color color, SDL_Rect pos)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	surface = TTF_RenderText_Blended(g_visu.font, word, color);
	if (!surface)
		terminate(SURFACE);
	texture = SDL_CreateTextureFromSurface(g_visu.rend, surface);
	if (!texture)
	{
		SDL_FreeSurface(surface);
		terminate(TEXTURE);
	}
	pos.h = surface->h;
	pos.w = surface->w;
	SDL_RenderCopy(g_visu.rend, texture, NULL, &pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void		sdl_put_number(char *s, uint64_t n, int x, int y)
{
	char		*str;
	SDL_Color	color;
	SDL_Rect	pos;

	color = (SDL_Color){255, 255, 255, 255};
	pos.x = x;
	pos.y = y;
	str = ft_strjoin_free_2(s, ft_ulltoa(n), 2);
	if (!str)
		terminate(MALLOC_ERROR);
	sdl_put_text(str, color, pos);
	ft_memdel((void**)&str);
}
