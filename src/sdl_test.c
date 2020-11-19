/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 00:42:24 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_visu.h"

int start_x = 30;
int start_y = 30;

void	sdl_init()
{
	int status;

	status = SDL_Init(SDL_INIT_EVERYTHING);
	if (status)
		terminate("Error SDL Init\n");
	status = TTF_Init();
	if (status)
		terminate("Error TTF Init\n");
	g_visu.win = SDL_CreateWindow("Corewar",
		POS_X, POS_Y, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!g_visu.win)
		terminate("Error create Window\n");
	g_visu.rend = SDL_CreateRenderer(g_visu.win,
		-1, SDL_RENDERER_ACCELERATED);
	if (!g_visu.rend)
		terminate("Error create render\n");
	g_visu.font = TTF_OpenFont(FONT, 12);
	if (!g_visu.font)
		terminate("Error open font '%s'\n", FONT);
}

void	sdl_loop_event(SDL_Event event)
{
	if (event.type == SDL_QUIT || g_visu.keyboard[SDL_SCANCODE_ESCAPE])
		g_visu.quit = 0;
	if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			start_y = (start_y >= 20) ? start_y : start_y + 35; //up
		else
			start_y = (start_y <= -500) ? start_y : start_y - 35; // down
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
		g_visu.click = 1;
	if (event.type == SDL_MOUSEBUTTONUP)
		g_visu.click = 0;
	SDL_GetMouseState(&g_visu.x, &g_visu.y);
	if (g_visu.click)
	{
		if (event.button.x - g_visu.x > 0)
			start_x = (start_x > - 250) ? start_x - 10 : start_x;
		if (event.button.x - g_visu.x < 0)
			start_x = (start_x < 30) ? start_x + 10 : start_x;
	}
	//ft_printf("x: %d | y: %d\n", start_x, start_y);
}

void sdl_loop()
{
	SDL_Event		event;
	int end;

	end = 0;
	g_visu.quit = 1;
	g_visu.keyboard = SDL_GetKeyboardState(NULL);
	while (g_visu.quit)
	{
		while (SDL_PollEvent(&event))
		{
			sdl_loop_event(event);
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
				g_visu.pause_flag = 1;
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && g_visu.pause_flag)
			{
				g_visu.pause = g_visu.pause ? 0 : 1;
				g_visu.pause_flag = g_visu.pause_flag ? 0 : 1;
			}
			//ft_printf("Pause: %d\n", g_visu.pause);
		}
		if (!g_visu.pause)
		{
			end = run_once();
			if (!end)
				exit(0);
		}

		//sdl_new_draw();
		sdl_draw();
		sdl_put_params();
		sdl_draw_border();
		SDL_RenderPresent(g_visu.rend);

		SDL_SetRenderDrawColor(g_visu.rend, 0, 0, 0, 1);
		SDL_RenderClear(g_visu.rend);
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

void	sdl_draw_border(void)
{
	SDL_Rect line_x;
	SDL_Rect line_y;

	line_x.h = 8;
	line_x.w = 1317;
	line_x.x = start_x - 20;
	line_x.y = start_y - 13;

	line_y.h = 1230;
	line_y.w = 8;
	line_y.x = start_x + 1289;
	line_y.y = start_y - 5; 
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 1);
	SDL_RenderFillRect(g_visu.rend, &line_x);
	SDL_RenderFillRect(g_visu.rend, &line_y);

	line_x.y = start_y + 1225;
	SDL_RenderFillRect(g_visu.rend, &line_x);
	line_y.x = start_x - 20;
	SDL_RenderFillRect(g_visu.rend, &line_y);
}

void	sdl_put_players(void)
{
	SDL_Color clr;
	SDL_Rect rect;
	char *player;
	int i;

	i = 0;
	rect.x = start_x + 1330;
	rect.y = 100;
	while (i < MAX_PLAYERS)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			clr = get_player_color(g_vm.champs[i].ichamp);
			player = sdl_threejoin(g_vm.champs[i].ichamp,
				g_vm.champs[i].name);
			sdl_put_text(player, clr, rect);
			sdl_put_number(LAST_LIVE, g_vm.champs[i].prev_nlive,
				rect.x + 10, rect.y + 20);
			sdl_put_number(S_CURRLIVE, g_vm.champs[i].curr_nlive,
				rect.x + 10, rect.y + 40);
			free(player);
		}
		i++;
		rect.y += 100;
	}
	
	i = 0;
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
	SDL_Rect params;
	SDL_Color color;

	params.x = start_x + 1400;
	params.y = 20;
	color = (SDL_Color){255, 255, 255, 1};
	if (g_visu.pause)
		sdl_put_text(PAUSED, color, params);
	else
		sdl_put_text(RUNNING, color, params);
	sdl_put_number(S_CYCLE, g_vm.icycle, start_x + 1330, 50);
	sdl_put_number(S_PROC, g_vm.nprocs, start_x + 1330, 70);
	sdl_put_players();
}


void	sdl_draw_proc(uint32_t index, int x, int y)
{
	SDL_Color	color;
	SDL_Rect	cube;
	t_proc		*tmp;

	if (tmp = get_proc(index))
	{
		cube.h = 18; // 17
		cube.w = 20; // 17
		cube.x = x - 2;
		cube.y = y + 1;
		color = get_player_color(tmp->ichamp);
		SDL_SetRenderDrawColor(g_visu.rend, color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(g_visu.rend, &cube);
		cube.x = x - 3;	
		cube.y = y;
		cube.h = cube.h + 2;
		cube.w = cube.w + 2;
		SDL_RenderDrawRect(g_visu.rend, &cube);
		
		//ft_printf("WRITE PROC!!!\n");
	}
}

void	sdl_new_draw(void)
{
	int			i;
	int			j;
	SDL_Rect	frect;
	SDL_Color	fcolor;
	char		*join = NULL;
	char		*tmp;
	char		*tmp2;
	i = 0;
	j = 0;
	fcolor = (SDL_Color){255, 255, 255, 1};
	frect.y = start_y;
	while (i < MEM_SIZE)
	{
		frect.x = start_x;
		j = 0;
		while (j < 64)
		{
			while (j < 63 && g_visu.vmem[i] == g_visu.vmem[i + 1])
			{
				//ft_printf("(%d): %u - %u\n", i, g_visu.vmem[i], g_visu.vmem[i + 1]);
				//if (j == 62)
				//	ft_printf("MEM\n");
				if (!join)
					join = hex_num(g_vm.mem[i]);
				tmp2 = hex_num(g_vm.mem[i + 1]);
				tmp = join;
				join = sdl_strjoin(join, tmp2);
				free(tmp); tmp = NULL;
				free(tmp2); tmp2 = NULL;
				i++;
				j++;
			}
			j++;
			//fcolor = get_player_color(g_visu.vmem[i]);
			//sdl_draw_proc(i, frect.x, frect.y);
			//draw_hex(g_vm.mem[i], fcolor, frect);
			//ft_printf("%s\n", join);
			sdl_put_text(join, fcolor, frect);
			free(join); join = NULL;
			frect.x += 20;
			i++;
		}
		frect.y += 19;
	}
}

void	sdl_draw()
{
	int i;
	int j;
	SDL_Rect frect;
	SDL_Color fcolor;

	i = 0;
	j = 0;
	fcolor = (SDL_Color){255, 255, 255, 1};
	frect.y = start_y;
	while (i < MEM_SIZE)
	{
		frect.x = start_x;
		j = 0;
		while (j++ < 64)
		{
			fcolor = get_player_color(g_visu.vmem[i]);
			sdl_draw_proc(i, frect.x, frect.y);
			draw_hex(g_vm.mem[i], fcolor, frect);
			frect.x += 20;
			i++;
		}
		frect.y += 19;
	}
}

void	sdl_launch()
{
	sdl_init();
	sdl_loop();
}
