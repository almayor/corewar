/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:53 by fallard           #+#    #+#             */
/*   Updated: 2020/11/26 00:57:13 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

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
	pos.y += 15;
	sdl_put_text(USAGE_4, clr, pos);
	pos.x = g_visu.g_x + 1380;
	pos.y = 20;
	pos.h = 110;
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
			pos.y += 70;
		}
		i++;
	}
}

static void	sdl_draw_info_2(SDL_Rect pos, SDL_Color clr)
{
	pos.y += 40;
	sdl_put_number(S_CYCLE, g_vm.icycle, pos.x, pos.y);
	pos.y += 20;
	sdl_put_number(S_PROC, g_vm.nprocs, pos.x, pos.y);
	pos.y += 40;
	sdl_put_players(pos);
	pos.y = pos.y + g_vm.nchamps * 75;
	sdl_put_text(CURR_RATIO, clr, pos);
	pos.y = pos.y + 20;
	sdl_draw_ratio(pos, clr, 1);
	pos.y = pos.y + 30;
	sdl_put_text(PREV_RATIO, clr, pos);
	pos.y = pos.y + 20;
	sdl_draw_ratio(pos, clr, 0);
	g_visu.ctd_copy = (g_vm.cycles_to_die < 0) ? 0 : g_vm.cycles_to_die;
	sdl_put_number(V_CYCDIE, g_visu.ctd_copy, pos.x, pos.y + 40);
	sdl_put_number(V_CECDELTA, CYCLE_DELTA, pos.x, pos.y + 60);
	sdl_put_number(V_NBR_LIVE, NBR_LIVE, pos.x, pos.y + 80);
	sdl_put_number(V_MAXCHECK, MAX_CHECKS, pos.x, pos.y + 100);
}

void		sdl_draw_info(void)
{
	SDL_Rect	pos;
	SDL_Color	clr;

	pos.x = g_visu.g_x + 1400;
	pos.y = 150;
	clr = (SDL_Color){255, 255, 255, 255};
	sdl_put_handling(pos, clr);
	if (!g_visu.finish)
		sdl_put_text(FINISH, clr, pos);
	else
	{
		if (g_visu.pause)
			sdl_put_text(PAUSED, clr, pos);
		else
			sdl_put_text(RUNNING, clr, pos);
	}
	sdl_draw_info_2(pos, clr);
}
