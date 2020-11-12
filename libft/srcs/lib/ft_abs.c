/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:24:28 by fallard           #+#    #+#             */
/*   Updated: 2020/11/12 21:05:56 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

long		ft_labs(long nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

long long	ft_llabs(long long nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
