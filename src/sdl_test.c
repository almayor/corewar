/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/19 01:43:20 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int start_x = 30;
int start_y = 40;

// static int	get_base_size(uintmax_t n, int base)
// {
// 	int i;

// 	i = 0;
// 	while (n)
// 	{
// 		n = n / base;
// 		i++;
// 	}
// 	return (i);
// }

// char		*ft_itoa_base(uintmax_t n, int hex_up, int base)
// {
// 	char	*hex;
// 	char	*res;
// 	int		i;
// 	int		len;

// 	if (hex_up)
// 		hex = "0123456789ABCDEF";
// 	else
// 		hex = "0123456789abcdef";
// 	len = get_base_size(n, base);
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	if (!(res = ft_calloc(1, len + 1)))
// 		return (NULL);
// 	i = len - 1;
// 	while (n)
// 	{
// 		res[i] = hex[n % base];
// 		n = n / base;
// 		i--;
// 	}
// 	return (res);
// }

SDL_Color get_player_color(uint32_t ichamp)
{
	SDL_Color res;

	if (ichamp == 1)
		res = (SDL_Color){240, 240, 0, 1};
	else if (ichamp == 2)
		res = (SDL_Color){40, 200, 10, 1};
	else if (ichamp == 3)
		res = (SDL_Color){10, 220, 160, 1};
	else if (ichamp == 4)
		res = (SDL_Color){10, 100, 220, 1};
	else
		res = (SDL_Color){255, 255, 255, 1};
	return (res);
}

void	sdl_mark_champ(uint32_t ichamp, size_t nbytes, uint32_t pos)
{
	int i;

	i = 0;
	while (i < nbytes)
	{
		g_visu.vmem[pos % MEM_SIZE] = ichamp;
		pos++;
		i++;
	}
}

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
	g_visu.font = TTF_OpenFont(FONT, 14);
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
			start_y = (start_y >= 20) ? start_y : start_y + 40; //up
		else
			start_y = (start_y <= -500) ? start_y : start_y - 40; // down
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
		g_visu.click = 1;
	if (event.type == SDL_MOUSEBUTTONUP)
		g_visu.click = 0;
	SDL_GetMouseState(&g_visu.x, &g_visu.y);
	if (g_visu.click)
	{
		if (event.button.x - g_visu.x > 0)
			start_x = (start_x > - 500) ? start_x - 20 : start_x;
		if (event.button.x - g_visu.x < 0)
			start_x = (start_x < 20) ? start_x + 20 : start_x;
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
			ft_printf("Pause: %d\n", g_visu.pause);
		}
		if (!g_visu.pause)
		{
			end = run_once();
			if (!end)
				exit(0);
		}
	
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

void	sdl_draw_border()
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

void	sdl_put_params()
{
	SDL_Rect params;
	SDL_Color color;

	params.x = start_x + 1350;
	params.y = start_y + 0;
	color = (SDL_Color){255, 255, 255, 1};
	if (g_visu.pause)
		sdl_put_text(PAUSED, color, params);
	else
		sdl_put_text(RUNNING, color, params);
}

void	draw_hex(uint8_t n, SDL_Color color, SDL_Rect pos)
{
	char	buf[3];
	char	*hex;
	int		i;

	ft_memset(buf, '0', 2);
	buf[2] = '\0';
	i = 1;
	while (n)
	{
		buf[i]= HEX[n % 16];
		i--;
		n = n / 16;
	}
	sdl_put_text(buf, color, pos);
}

int	get_proc(uint32_t ichamp)
{
	t_proc	*tmp;

	tmp = g_vm.procs;
	while (tmp)
	{
		if (tmp->ichamp == ichamp)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sdl_draw_proc(uint32_t ichamp, SDL_Color color, int x, int y)
{
	SDL_Rect	cube;

	if (get_proc(ichamp) == 1)
	{
		cube.h = 1; // 17
		cube.w = 1; // 17
		cube.x = x;
		cube.y = y;
		SDL_SetRenderDrawColor(g_visu.rend, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(g_visu.rend, &cube);
		ft_printf("WRITE PROC!!!\n");
	}
}

void	sdl_draw()
{
	int i;
	int j;
	int shift;
	SDL_Rect frect;
	SDL_Color fcolor;
	char *hex;

	i = 0;
	j = 0;
	shift = 0;
	
	fcolor = (SDL_Color){255, 255, 255, 1};
	frect.y = start_y;
	while (i < MEM_SIZE)
	{
		frect.x = start_x;
		j = 0;
		while (j++ < 64)
		{
			fcolor = get_player_color(g_visu.vmem[i]);
			sdl_draw_proc(g_visu.vmem[i], fcolor, frect.x, frect.y);
			draw_hex(g_vm.mem[i], fcolor, frect);
			frect.x += 20;
			i++;
		}
		shift = shift + 64;
		frect.y += 19;
	}
}

void	sdl_launch()
{
	sdl_init();
	sdl_loop();
}
