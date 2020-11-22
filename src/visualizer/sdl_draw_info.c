/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:53 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 21:40:25 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

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
	str = ft_strjoin_free(s, ft_ulltoa(n), 2);
	if (!str)
		terminate(MALLOC_ERROR);
	sdl_put_text(str, color, pos);
	ft_memdel((void**)&str);
}

static void	sdl_put_handling(SDL_Rect pos, SDL_Color clr)
{
	pos.y = 30;
	sdl_put_text(USAGE_0, clr, pos);
	pos.y += 30;
	sdl_put_text(USAGE_1, clr, pos);
	pos.y += 15;
	sdl_put_text(USAGE_2, clr, pos);
	pos.y += 15;
	sdl_put_text(USAGE_3, clr, pos);
	pos.x = g_visu.g_x + 1380;
	pos.y = 20;
	pos.h = 100;
	pos.w = 280;
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 255);
	SDL_RenderDrawRect(g_visu.rend, &pos);
}

static void	sdl_put_players(SDL_Rect pos)
{
	SDL_Color	clr;
	char		*player;
	int			i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			clr = get_player_color(g_vm.champs[i].ichamp);
			player = sdl_threejoin(g_vm.champs[i].ichamp,
				g_vm.champs[i].name);
			if (!player)
				terminate(MALLOC_ERROR);
			sdl_put_text(player, clr, pos);
			free(player);
			sdl_put_number(LAST_LIVE, g_vm.champs[i].last_live,
				pos.x + 15, pos.y + 20);
			sdl_put_number(S_CURRLIVE, g_vm.champs[i].curr_nlive,
				pos.x + 15, pos.y + 40);
		}
		i++;
		pos.y += 75;
	}
}

void		sdl_draw_info(void)
{
	SDL_Rect	pos;
	SDL_Color	clr;

	pos.x = g_visu.g_x + 1400;
	pos.y = 150;
	clr = (SDL_Color){255, 255, 255, 255};
	(g_visu.pause) ? sdl_put_text(PAUSED, clr, pos)
		: sdl_put_text(RUNNING, clr, pos);
	pos.y += 40;
	sdl_put_number(S_CYCLE, g_vm.icycle, pos.x, pos.y);
	pos.y += 20;
	sdl_put_number(S_PROC, g_vm.nprocs, pos.x, pos.y);
	pos.y += 40;
	sdl_put_players(pos);
	sdl_put_handling(pos, clr);
	pos.y = pos.y + g_vm.nchamps * 80;
	sdl_put_text(CURR_RATIO, clr, pos);
	pos.y = pos.y + 20;
	sdl_draw_ratio(pos, clr, 1);
	pos.y = pos.y + 30;
	sdl_put_text(PREV_RATIO, clr, pos);
	pos.y = pos.y + 20;
	sdl_draw_ratio(pos, clr, 0);
	sdl_put_number(CYCLE2DIE, g_vm.cycles_to_die, pos.x, pos.y + 50);
}
