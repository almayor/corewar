/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:42:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/23 17:06:20 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

void	sdl_loop(void)
{
	SDL_Event	event;

	g_visu.finish = 1;
	g_visu.quit = 1;
	g_visu.keyboard = SDL_GetKeyboardState(NULL);
	g_visu.pause = 1;
	while (g_visu.quit)
	{
		SDL_SetRenderDrawColor(g_visu.rend, 0, 0, 0, 255);
		SDL_RenderClear(g_visu.rend);
		while (SDL_PollEvent(&event))
		{
			sdl_mouse_event(event);
			sdl_pause_event(event);
		}
		if (!g_visu.pause && g_visu.finish)
			g_visu.finish = run_once();
		sdl_init_pmem();
		sdl_draw_map();
		sdl_draw_info();
		sdl_draw_border();
		SDL_RenderPresent(g_visu.rend);
	}
}

void	sdl_mouse_event(SDL_Event event)
{
	SDL_GetMouseState(&g_visu.m_x, &g_visu.m_y);
	if (event.type == SDL_QUIT || g_visu.keyboard[SDL_SCANCODE_ESCAPE])
		g_visu.quit = 0;
	if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			g_visu.g_y = (g_visu.g_y >= 20) ? g_visu.g_y : g_visu.g_y + 30;
		else
			g_visu.g_y = (g_visu.g_y < (-1300 + g_visu.mode.h)) ?
				g_visu.g_y : g_visu.g_y - 30;
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
		g_visu.click = 1;
	if (event.type == SDL_MOUSEBUTTONUP)
		g_visu.click = 0;
	if (g_visu.click)
	{
		if (event.button.x - g_visu.m_x > 0)
			g_visu.g_x = (g_visu.g_x > (-1820 + g_visu.mode.w)) ?
				g_visu.g_x - 30 : g_visu.g_x;
		if (event.button.x - g_visu.m_x < 0)
			g_visu.g_x = (g_visu.g_x < 30) ? g_visu.g_x + 30 : g_visu.g_x;
	}
}

void	sdl_pause_event(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		g_visu.pause_flag = 1;
	if (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_SPACE && g_visu.pause_flag)
	{
		g_visu.pause = g_visu.pause ? 0 : 1;
		g_visu.pause_flag = g_visu.pause_flag ? 0 : 1;
	}
}
