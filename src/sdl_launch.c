/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 20:02:04 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//int start_x = 30;
//int start_y = 30;

// void	sdl_draw()
// {
// 	int i;
// 	int j;
// 	SDL_Rect frect;
// 	SDL_Color fcolor;

// 	i = 0;
// 	j = 0;
// 	fcolor = (SDL_Color){255, 255, 255, 1};
// 	frect.y = g_visu.g_y;
// 	while (i < MEM_SIZE)
// 	{
// 		frect.x = g_visu.g_x;
// 		j = 0;
// 		while (j++ < 64)
// 		{
// 			fcolor = get_player_color(g_visu.vmem[i]);
// 			sdl_draw_proc(i, frect.x, frect.y);
// 			draw_hex(g_vm.mem[i], fcolor, frect);
// 			frect.x += 20;
// 			i++;
// 		}
// 		frect.y += 19;
// 	}
// }

void	sdl_init()
{
	int status;

	status = SDL_Init(SDL_INIT_EVERYTHING);
	if (status)
		terminate("Error SDL Init\n");
	status = TTF_Init();
	if (status)
		terminate("Error TTF Init\n");
	g_visu.font = TTF_OpenFont(FONT, 12);
	if (!g_visu.font)
		terminate("Error open font '%s'\n", FONT);
	g_visu.win = SDL_CreateWindow("Corewar",
		POS_X, POS_Y, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!g_visu.win)
		terminate("Error create Window\n");
	g_visu.rend = SDL_CreateRenderer(g_visu.win,
		-1, SDL_RENDERER_ACCELERATED);
	if (!g_visu.rend)
		terminate("Error create render\n");
	g_visu.g_x = 30;
	g_visu.g_y = 30;
}

void	sdl_quit()
{
	SDL_DestroyRenderer(g_visu.rend);
	SDL_DestroyWindow(g_visu.win);
	TTF_CloseFont(g_visu.font);
	//SDL_Quit();
	//TTF_Quit();
}

void	sdl_launch()
{
	sdl_init();
	sdl_loop();
	sdl_quit();
}
