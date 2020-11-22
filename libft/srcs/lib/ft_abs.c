/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:24:28 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 18:23:31 by user             ###   ########.fr       */
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
