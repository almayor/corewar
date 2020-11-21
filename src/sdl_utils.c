/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:58:07 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 22:09:20 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

t_proc	*get_proc(uint32_t index)
{
	t_proc	*tmp;

	tmp = g_vm.procs;
	while (tmp)
	{
		if (tmp->pc == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*hex_num(uint8_t n)
{
	char	*res;
	int		i;

	if (!(res = ft_calloc(1, 3)))
		return (NULL);
	res[0] = '0';
	res[1] = '0';
	i = 1;
	while (n)
	{
		res[i] = HEX[n % 16];
		i--;
		n /= 16;
	}
	return (res);
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
		buf[i] = HEX[n % 16];
		i--;
		n = n / 16;
	}
	sdl_put_text(buf, color, pos);
}

char	*sdl_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len;

	len = ft_strlen(str1);
	if (!(res = ft_calloc(1, len + 4)))
		return (NULL);
	ft_strcpy(res, str1);
	ft_strcpy(res + len, " ");
	ft_strcpy(res + len + 1, str2);
	return (res);
}

char	*ft_ulltoa(uint64_t nbr)
{
	uint64_t	tmp;
	char		*res;
	int			len;
	int			i;

	if (nbr == 0)
		return (ft_strdup("0"));
	tmp = nbr;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (!(res = ft_calloc(1, len + 1)))
		return (NULL);
	i = len - 1;
	while (nbr)
	{
		res[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

SDL_Color	get_player_color(uint32_t ichamp)
{
	SDL_Color res;

	if (ichamp == 1)
		res = (SDL_Color){240, 240, 0, 1};
	else if (ichamp == 2)
		res = (SDL_Color){255, 30, 30, 1};//(SDL_Color){40, 200, 10, 1};
	else if (ichamp == 3)
		res = (SDL_Color){0, 190, 150, 1};
	else if (ichamp == 4)
		res = (SDL_Color){20, 110, 250, 1};
	else
		res = (SDL_Color){255, 255, 255, 1};
	return (res);
}

char	*sdl_threejoin(uint32_t n, char *name)
{
	char	*res;
	int		len;
	char	*c;

	if (n == 1)
		c = "1";
	else if (n == 2)
		c = "2";
	else if (n == 3)
		c = "3";
	else
		c = "4";
	len = ft_strlen(name);
	if (!(res = ft_calloc(1, 6 + 4 + len + 1)))
		return (NULL);
	ft_strcpy(res, "Player ");
	ft_strcpy(res + 7, c);
	ft_strcpy(res + 8, ": ");
	ft_strcpy(res + 10, name);
	return (res);
}
