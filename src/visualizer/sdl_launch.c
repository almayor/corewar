/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 19:55:41 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	sdl_init(void)
{
	int status;

	status = SDL_Init(SDL_INIT_EVERYTHING);
	if (status)
		terminate("Error SDL Init\n");
	SDL_GetCurrentDisplayMode(0, &g_visu.mode);
	status = TTF_Init();
	if (status)
		terminate("Error TTF Init\n");
	g_visu.font = TTF_OpenFont(FONT, 12);
	if (!g_visu.font)
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
	//SDL_Quit();
	//TTF_Quit();
}

void		sdl_launch(void)
{
	sdl_init();
	sdl_loop();
	sdl_quit();
}
