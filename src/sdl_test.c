/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:32 by fallard           #+#    #+#             */
/*   Updated: 2020/11/17 18:20:53 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
# include <SDL2/SDL_ttf.h>

int start_x = 20;
int start_y = 20;

static int	get_base_size(uintmax_t n, int base)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(uintmax_t n, int hex_up, int base)
{
	char	*hex;
	char	*res;
	int		i;
	int		len;

	if (hex_up)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = get_base_size(n, base);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(res = ft_calloc(1, len + 1)))
		return (NULL);
	i = len - 1;
	while (n)
	{
		res[i] = hex[n % base];
		n = n / base;
		i--;
	}
	return (res);
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
	g_vm.visual.win = SDL_CreateWindow("Corewar",
		POS_X, POS_Y, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!g_vm.visual.win)
		terminate("Error create Window\n");
	g_vm.visual.rend = SDL_CreateRenderer(g_vm.visual.win,
		-1, SDL_RENDERER_ACCELERATED);
	if (!g_vm.visual.rend)
		terminate("Error create render\n");
	g_vm.visual.font = TTF_OpenFont(FONT, 14);
	if (!g_vm.visual.font)
		terminate("Error open font '%s'\n", FONT);
}

void sdl_loop()
{
	SDL_Event		event;
	const uint8_t	*keyboard;
	int				quit;
	int click = 0;
	int x, y;
	quit = 1;
	keyboard = SDL_GetKeyboardState(NULL);
	while (quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || keyboard[SDL_SCANCODE_ESCAPE])
				quit = 0;
			if (event.type == SDL_MOUSEWHEEL)
			{
				if (event.wheel.y > 0)
					start_y = (start_y >= 20) ? start_y : start_y + 40; //up
				else
					start_y = (start_y <= -500) ? start_y : start_y - 40; // down
			}

			if (event.type == SDL_MOUSEBUTTONDOWN)
				click = 1;
			if (event.type == SDL_MOUSEBUTTONUP)
				click = 0;
			
			ft_printf("click: %u\n", click);
			ft_printf("x: %d, y: %d\n", event.button.x, event.button.y);
			SDL_GetMouseState(&x, &y);
			ft_printf("state: x = %d,y = %d\n", x, y);
			if (!click)
			{
				x = event.button.x;
				y = event.button.y;
			}
			
			if (click)
			{
				
				ft_printf("diff x = %d\n", event.button.x - x);
				ft_printf("diff y = %d\n", event.button.y - y);
				if (event.button.x - x > 0)
					start_x = (start_x > - 500) ? start_x - 20 : start_x;
				if (event.button.x - x < 0)
					start_x = (start_x < 20) ? start_x + 20 : start_x;
			}
			if (keyboard[SDL_SCANCODE_RIGHT])
				start_x = (start_x > - 1200) ? start_x - 30 : start_x;
			if (keyboard[SDL_SCANCODE_LEFT])
				start_x = (start_x < 20) ? start_x + 30 : start_x;
			ft_printf("x: %d | y: %d\n", start_x, start_y);
		}
		sdl_draw();
		SDL_RenderPresent(g_vm.visual.rend);
		//SDL_SetRenderDrawColor(g_vm.visual.rend, 0, 75, 140, 1);
		SDL_RenderClear(g_vm.visual.rend);
	}
}

void	sdl_put_text(const char *word, SDL_Color color, SDL_Rect pos)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	surface = TTF_RenderText_Blended(g_vm.visual.font, word, color);
	if (!surface)
		terminate("Error sdl surface\n");
	texture = SDL_CreateTextureFromSurface(g_vm.visual.rend, surface);
	if (!texture)
		terminate("Error create text from surface\n");
	pos.h = surface->h;
	pos.w = surface->w;
	SDL_RenderCopy(g_vm.visual.rend, texture, NULL, &pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
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
	
	fcolor = (SDL_Color){230, 230, 0, 1};
	frect.y = start_y;
	while (i < MEM_SIZE)
	{
		frect.x = start_x;
		j = 0;
		while (j++ < 64)
		{
			draw_hex(g_vm.mem[i], fcolor, frect);
			frect.x += 20;
			i++;
		}
		shift = shift + 64;
		frect.y += 19;
	}
	//SDL_FreeSurface(fsurf);
	//SDL_DestroyTexture(ftext);
}

void	sdl_launch()
{
	sdl_init();
	SDL_SetRenderDrawColor(g_vm.visual.rend, 0, 0, 0, 1);
	SDL_RenderClear(g_vm.visual.rend);
	g_vm.visual.rect.h = 15;
	g_vm.visual.rect.w = 15;
	g_vm.visual.rect.x = 30;
	g_vm.visual.rect.y = 30;
	sdl_loop();
	
}
