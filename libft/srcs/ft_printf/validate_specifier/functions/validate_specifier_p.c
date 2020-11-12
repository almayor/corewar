/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_specifier_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:54 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:55:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_p(t_specifier *specif)
{
	if (specif->plus)
		specif->plus = 0;
	if (specif->space)
		specif->space = 0;
	if (specif->hash)
		return ((errno = EINVAL));
	if (specif->zero && specif->minus && specif->width.isgiven)
		specif->zero = 0;
	if (specif->length != NONE)
		return ((errno = EINVAL));
	if (specif->precision.isgiven)
		specif->precision.isgiven = 0;
	return (0);
}
