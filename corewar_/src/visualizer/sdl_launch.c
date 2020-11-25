/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/23 18:33:36 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_visu		g_visu;

static void	sdl_init(void)
{
	int status;

	if ((status = SDL_Init(SDL_INIT_EVERYTHING)))
		terminate("Error SDL Init\n");
	SDL_GetCurrentDisplayMode(0, &g_visu.mode);
	g_visu.mode.w = (g_visu.mode.w > 1870) ? 1870 : g_visu.mode.w;
	if ((status = TTF_Init()))
		terminate("Error TTF Init\n");
	if (!(g_visu.font = TTF_OpenFont(FONT, 12)))
		terminate("Error open font '%s'\n", FONT);
	g_visu.win = SDL_CreateWindow("Corewar",
		POS_X, POS_Y, g_visu.mode.w - 30, g_visu.mode.h - 70, SDL_WINDOW_SHOWN);
	if (!g_visu.win)
		terminate("Error create Window\n");
	g_visu.rend = SDL_CreateRenderer(g_visu.win,
		-1, SDL_RENDERER_ACCELERATED);
	if (!g_visu.rend)
		terminate("Error create render\n");
	g_visu.g_x = 30;
	g_visu.g_y = 30;
}

void		sdl_quit(void)
{
	SDL_DestroyRenderer(g_visu.rend);
	SDL_DestroyWindow(g_visu.win);
	TTF_CloseFont(g_visu.font);
	SDL_Quit();
	TTF_Quit();
}

void		sdl_launch(void)
{
	sdl_init();
	sdl_loop();
	sdl_quit();
}
