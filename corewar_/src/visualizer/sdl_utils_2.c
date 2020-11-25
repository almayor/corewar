/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:12:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 23:19:05 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visu.h"

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
