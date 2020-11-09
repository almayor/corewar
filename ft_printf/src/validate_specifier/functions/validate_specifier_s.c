/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_specifier_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:54:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_s(t_specifier *specif)
{
	if (specif->plus)
		return ((errno = EINVAL));
	if (specif->space)
		return ((errno = EINVAL));
	if (specif->hash)
		return ((errno = EINVAL));
	if (specif->zero)
		return ((errno = EINVAL));
	if (specif->length != NONE)
		return ((errno = EINVAL));
	return (0);
}
