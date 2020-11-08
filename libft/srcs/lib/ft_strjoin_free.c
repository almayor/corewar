/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:46:23 by fallard           #+#    #+#             */
/*   Updated: 2020/08/17 19:40:28 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *str1, char *str2, int flag)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(res = ft_calloc(len, sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		res[j++] = str1[i++];
	i = 0;
	while (str2[i])
		res[j++] = str2[i++];
	if (flag == 1)
		free(str1);
	else
		free(str2);
	return (res);
}
