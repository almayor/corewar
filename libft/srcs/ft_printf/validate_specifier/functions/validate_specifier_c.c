/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_specifier_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:56:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_c(t_specifier *specif)
{
	if (specif->plus)
		return ((errno = EINVAL));
	if (specif->space)
		specif->space = 0;
	if (specif->hash)
		return ((errno = EINVAL));
	if (specif->zero)
		return ((errno = EINVAL));
	if (specif->length != NONE)
		return ((errno = EINVAL));
	if (specif->precision.isgiven)
		specif->precision.isgiven = 0;
	return (0);
}
