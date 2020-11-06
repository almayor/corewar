/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:54 by user              #+#    #+#             */
/*   Updated: 2020/11/06 14:37:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atou2(const char *str, uint64_t *res)
{
	int	digit;

	while (ft_isspace(*str))
		str++;
	*res = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (*res > (ULONG_MAX - digit) / 10)
			return (1);
		*res = (*res * 10) + digit;
		str++;
	}
	return (0);
}
