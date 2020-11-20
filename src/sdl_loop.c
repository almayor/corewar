/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:42:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 20:26:25 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sdl_loop(void)
{
	SDL_Event	event;
	int			end;

	end = 1;
	g_visu.quit = 1;
	g_visu.keyboard = SDL_GetKeyboardState(NULL);
	while (g_visu.quit)
	{
		SDL_SetRenderDrawColor(g_visu.rend, 0, 0, 0, 1);
		SDL_RenderClear(g_visu.rend);
		while (SDL_PollEvent(&event))
		{
			sdl_mouse_event(event);
			sdl_pause_event(event);
		}
		if (!g_visu.pause && end)
			end = run_once();
		sdl_new_draw();
		sdl_put_params();
		sdl_draw_border();
		SDL_RenderPresent(g_visu.rend);
	}
}

void	sdl_mouse_event(SDL_Event event)
{
	SDL_GetMouseState(&g_visu.x, &g_visu.y);
	if (event.type == SDL_QUIT || g_visu.keyboard[SDL_SCANCODE_ESCAPE])
		g_visu.quit = 0;
	if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			g_visu.g_y = (g_visu.g_y >= 20) ? g_visu.g_y : g_visu.g_y + 35;
		else
			g_visu.g_y = (g_visu.g_y <= -500) ? g_visu.g_y : g_visu.g_y - 35;
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
		g_visu.click = 1;
	if (event.type == SDL_MOUSEBUTTONUP)
		g_visu.click = 0;
	if (g_visu.click)
	{
		if (event.button.x - g_visu.x > 0)
			g_visu.g_x = (g_visu.g_x > -250) ? g_visu.g_x - 10 : g_visu.g_x;
		if (event.button.x - g_visu.x < 0)
			g_visu.g_x = (g_visu.g_x < 30) ? g_visu.g_x + 10 : g_visu.g_x;
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
