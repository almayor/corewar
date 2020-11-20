/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_put_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:53 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 02:28:10 by fallard          ###   ########.fr       */
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

void	sdl_put_number(char *s, uint64_t n, int x, int y)
{
	char		*str;
	SDL_Color	color;
	SDL_Rect	pos;

	color = (SDL_Color){255, 255, 255, 1};
	pos.x = x;
	pos.y = y;
	str = ft_strjoin_free(s, ft_ulltoa(n), 2);
	if (!str)
		terminate(MALLOC_ERROR);
	sdl_put_text(str, color, pos);
	ft_memdel((void**)&str);
}

void	sdl_put_handling(SDL_Rect pos, SDL_Color clr)
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
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 1);
	SDL_RenderDrawRect(g_visu.rend, &pos);
}

char *get_hz(size_t n)
{
	char *res;

	res = ft_calloc(1, n + 1);
	ft_memset(res, '0', n);
	return (res);
}

void	sdl_put_hz(SDL_Rect pos, SDL_Color clr)
{
	SDL_Color	champ;
	int			i;
	
	pos.y = pos.y + g_vm.nchamps * 90;
	sdl_put_text(HZ, clr, pos);
	i = 0;
	pos.x += 7;
	while (i < MAX_PLAYERS)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			double s = (g_vm.curr_nlive) ? g_vm.champs[i].curr_nlive / (double)g_vm.curr_nlive : 0;
			printf("%.1f - %.3f - (%u)\n", 50.0 * s, s, g_vm.curr_nlive);
			champ = get_player_color(g_vm.champs[i].ichamp);
			char *str = get_hz(50.0 * s);
			if (ft_strlen(str) > 0)
			{
				sdl_put_text(str, champ, pos);
				pos.x = pos.x + (int)(50.0 * s) * 7;
			}
			free(str);
		}
		i++;
	}
	ft_printf("\n");
}

void	sdl_put_params(void)
{
	SDL_Rect	pos;
	SDL_Color	clr;

	pos.x = g_visu.g_x + 1400;
	pos.y = 150;
	clr = (SDL_Color){255, 255, 255, 1};
	if (g_visu.pause)
		sdl_put_text(PAUSED, clr, pos);
	else
		sdl_put_text(RUNNING, clr, pos);
	pos.y += 40;
	sdl_put_number(S_CYCLE, g_vm.icycle, pos.x, pos.y);
	pos.y += 20;
	sdl_put_number(S_PROC, g_vm.nprocs, pos.x, pos.y);
	pos.y += 40;
	sdl_put_players(pos);
	sdl_put_handling(pos, clr);
	sdl_put_hz(pos, clr);
}
