/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:48:47 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 21:39:29 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

void	sdl_draw_proc(uint32_t index, int x, int y)
{
	SDL_Color	color;
	SDL_Rect	cube;
	t_proc		*tmp;

	if ((tmp = get_proc(index)))
	{
		cube.h = 18;
		cube.w = 20;
		cube.x = x - 3;
		cube.y = y - 1;
		color = get_player_color(tmp->ichamp);
		SDL_SetRenderDrawColor(g_visu.rend,
			color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(g_visu.rend, &cube);
		cube.x = x - 4;
		cube.y = y - 2;
		cube.h = cube.h + 2;
		cube.w = cube.w + 2;
		SDL_RenderDrawRect(g_visu.rend, &cube);
	}
}

void	sdl_draw_map_2(t_vmap *m)
{
	while (m->j < 63 && g_visu.vmem[m->i] == g_visu.vmem[m->i + 1])
	{
		if (!(m->next = hex_num(g_vm.mem[m->i + 1])))
		{
			ft_memdel((void**)&m->join);
			terminate(MALLOC_ERROR);
		}
		m->tmp = m->join;
		if (!(m->join = sdl_strjoin(m->join, m->next)))
		{
			ft_memdel((void**)&m->tmp);
			ft_memdel((void**)&m->next);
			terminate(MALLOC_ERROR);
		}
		ft_memdel((void**)&m->tmp);
		ft_memdel((void**)&m->next);
		sdl_draw_proc(m->i, g_visu.g_x + (m->i % 64) * 21, m->pos.y);
		m->i = m->i + 1;
		m->j = m->j + 1;
	}
	if (g_visu.vmem[m->i] != g_visu.vmem[m->i + 1])
		sdl_draw_proc(m->i, g_visu.g_x + (m->i % 64) * 21, m->pos.y);
}

void	sdl_draw_map(void)
{
	t_vmap	m;

	ft_memset(&m, 0, sizeof(m));
	m.pos.y = g_visu.g_y;
	while (m.i < MEM_SIZE)
	{
		m.pos.x = g_visu.g_x;
		m.j = 0;
		while (m.j < 64)
		{
			if (!m.join)
			{
				if (!(m.join = hex_num(g_vm.mem[m.i])))
					terminate(MALLOC_ERROR);
			}
			m.clr = get_player_color(g_visu.vmem[m.i]);
			sdl_draw_map_2(&m);
			sdl_put_text(m.join, m.clr, m.pos);
			m.pos.x += ft_strlen(m.join) * 7 + 7;
			ft_memdel((void**)&m.join);
			m.j = m.j + 1;
			m.i = m.i + 1;
		}
		m.pos.y += 19;
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
	SDL_SetRenderDrawColor(g_visu.rend, 255, 255, 255, 255);
	SDL_RenderFillRect(g_visu.rend, &line_x);
	SDL_RenderFillRect(g_visu.rend, &line_y);
	line_x.y = g_visu.g_y + 1221;
	SDL_RenderFillRect(g_visu.rend, &line_x);
	line_y.x = g_visu.g_x - 20;
	SDL_RenderFillRect(g_visu.rend, &line_y);
}
