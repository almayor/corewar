/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_put_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:53 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 19:49:51 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sdl_put_players(SDL_Rect pos)
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
			sdl_put_number(LAST_LIVE, g_vm.champs[i].last_live,
				pos.x + 15, pos.y + 20);
			sdl_put_number(S_CURRLIVE, g_vm.champs[i].curr_nlive,
				pos.x + 15, pos.y + 40);
			free(player);
		}
		i++;
		pos.y += 90;
	}
}

void	sdl_put_text(const char *word, SDL_Color color, SDL_Rect pos)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	surface = TTF_RenderText_Blended(g_visu.font, word, color);
	if (!surface)
		terminate("Error sdl surface\n");
	texture = SDL_CreateTextureFromSurface(g_visu.rend, surface);
	if (!texture)
		terminate("Error create text from surface\n");
	pos.h = surface->h;
	pos.w = surface->w;
	SDL_RenderCopy(g_visu.rend, texture, NULL, &pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}


void	sdl_put_number(char *s, uint64_t n, int x, int y)
{
	char		*str;
	SDL_Color	color;
	SDL_Rect	pos;

	color = (SDL_Color){255, 255, 255, 1};
	pos.x = x;
	pos.y = y;
	str = ft_strjoin_free(s, ft_ulltoa(n), 2);

	sdl_put_text(str, color, pos);
	free (str);
}

void	sdl_put_params()
{
	SDL_Rect	params;
	SDL_Color	color;

	params.x = g_visu.g_x + 1400;
	params.y = 150;
	color = (SDL_Color){255, 255, 255, 1};
	if (g_visu.pause)
		sdl_put_text(PAUSED, color, params);
	else
		sdl_put_text(RUNNING, color, params);
	params.y += 40;
	sdl_put_number(S_CYCLE, g_vm.icycle, params.x, params.y);
	params.y += 20;
	sdl_put_number(S_PROC, g_vm.nprocs, params.x, params.y);
	params.y += 40;
	sdl_put_players(params);

	params.y = 30;
	sdl_put_text(USAGE_0, color, params);
	params.y += 30;
	sdl_put_text(USAGE_1, color, params);
	params.y += 15;
	sdl_put_text(USAGE_2, color, params);
	params.y += 15;
	sdl_put_text(USAGE_3, color, params);
	params.x = g_visu.g_x + 1380;
	params.y = 20;
	params.h = 100;
	params.w = 280;
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 1);
	SDL_RenderDrawRect(g_visu.rend, &params);
}
