/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_ratio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:40:03 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 23:19:37 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

static char	*get_ratio_text(size_t n)
{
	char *res;

	res = ft_calloc(1, n + 1);
	if (!res)
		return (NULL);
	ft_memset(res, '#', n);
	return (res);
}

static int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

static void	draw_ratio(int *width, int *player, SDL_Rect pos)
{
	SDL_Color	clr;
	char		*str;
	int			i;

	i = 0;
	while (i < 4)
	{
		if (width[i] > 0)
		{
			clr = get_player_color(player[i]);
			if (!(str = get_ratio_text(width[i])))
				terminate(MALLOC_ERROR);
			sdl_put_text(str, clr, pos);
			pos.x = pos.x + ft_strlen(str) * 7;
			free(str);
		}
		i++;
	}
}

static void	calculate_diff(int *player, int *width, SDL_Rect pos)
{
	int diff;
	int max;
	int	sum;
	int i;

	sum = width[0] + width[1] + width[2] + width[3];
	diff = sum - 50;
	max = ft_max(width[0], ft_max(width[1], ft_max(width[2], width[3])));
	i = 0;
	while (i < 4)
	{
		if (width[i] == max)
			break ;
		i++;
	}
	width[i] = width[i] - diff;
	draw_ratio(width, player, pos);
}

void		sdl_draw_ratio(SDL_Rect pos, SDL_Color clr, int flag)
{
	int			i;
	int			j;
	int			width[4];
	int			player[4];

	ft_memset(width, 0, sizeof(int) * 4);
	ft_memset(player, 0, sizeof(int) * 4);
	sdl_put_text(EMPTY_LINE, clr, pos);
	pos.x += 7;
	if (!(flag ? g_vm.curr_nlive : g_vm.prev_nlive))
		return (sdl_put_text(FILL_LINE, clr, pos));
	i = 0;
	j = 0;
	while (i < MAX_PLAYERS)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			width[j] = 50.0 *
			((flag ? g_vm.champs[i].curr_nlive : g_vm.champs[i].prev_nlive)
			/ (flag ? (double)g_vm.curr_nlive : (double)g_vm.prev_nlive)) + 0.5;
			player[j++] = g_vm.champs[i].ichamp;
		}
		i++;
	}
	calculate_diff(player, width, pos);
}
