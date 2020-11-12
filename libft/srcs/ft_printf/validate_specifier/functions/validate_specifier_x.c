/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_specifier_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:53:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_x(t_specifier *specif)
{
	if (specif->plus)
		specif->plus = 0;
	if (specif->space)
		specif->space = 0;
	if (specif->zero && specif->minus && specif->width.isgiven)
		specif->zero = 0;
	if (specif->zero && specif->precision.isgiven)
		specif->zero = 0;
	if (specif->length == L)
		return ((errno = EINVAL));
	return (0);
}
