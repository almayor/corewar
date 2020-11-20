/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:47 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 19:51:45 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	sdl_draw_proc(uint32_t index, int x, int y)
{
	SDL_Color	color;
	SDL_Rect	cube;
	t_proc		*tmp;

	if (tmp = get_proc(index))
	{
		cube.h = 18;
		cube.w = 20;
		cube.x = x - 2;
		cube.y = y + 1;
		color = get_player_color(tmp->ichamp);
		SDL_SetRenderDrawColor(g_visu.rend,
			color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(g_visu.rend, &cube);
		cube.x = x - 3;	
		cube.y = y;
		cube.h = cube.h + 2;
		cube.w = cube.w + 2;
		SDL_RenderDrawRect(g_visu.rend, &cube);
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
	frect.y = g_visu.g_y;
	while (i < MEM_SIZE)
	{
		frect.x = g_visu.g_x;
		j = 0;
		while (j < 64)
		{
			if (!join)
				join = hex_num(g_vm.mem[i]);
			fcolor = get_player_color(g_visu.vmem[i]);
			while (j < 63 && g_visu.vmem[i] == g_visu.vmem[i + 1])
			{
				tmp2 = hex_num(g_vm.mem[i + 1]);
				tmp = join;
				join = sdl_strjoin(join, tmp2);
				free(tmp); tmp = NULL;
				free(tmp2); tmp2 = NULL;
				i++;
				j++;
			}
			j++;
			sdl_put_text(join, fcolor, frect);
			frect.x += ft_strlen(join) * 7 + 7;
			free(join); join = NULL;
			i++;
		}
		frect.y += 19;
	}
}

void	sdl_draw_border(void)
{
	SDL_Rect line_x;
	SDL_Rect line_y;

	line_x.h = 6;
	line_x.w = 1376;
	line_x.x = g_visu.g_x - 20;
	line_x.y = g_visu.g_y - 15;

	line_y.h = 1230;
	line_y.w = 6;
	line_y.x = g_visu.g_x + 1350;
	line_y.y = g_visu.g_y - 9; 
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 1);
	SDL_RenderFillRect(g_visu.rend, &line_x);
	SDL_RenderFillRect(g_visu.rend, &line_y);

	line_x.y = g_visu.g_y + 1221;
	SDL_RenderFillRect(g_visu.rend, &line_x);
	line_y.x = g_visu.g_x - 20;
	SDL_RenderFillRect(g_visu.rend, &line_y);
}
