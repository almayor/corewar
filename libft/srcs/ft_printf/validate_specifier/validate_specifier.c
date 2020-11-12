/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:00 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:05:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier(t_specifier *specif)
{
	static int	(*const dispatch_table[128])(t_specifier *) = {
		['c'] = &validate_specifier_c,
		['s'] = &validate_specifier_s,
		['i'] = &validate_specifier_i,
		['d'] = &validate_specifier_i,
		['x'] = &validate_specifier_x,
		['X'] = &validate_specifier_x,
		['o'] = &validate_specifier_x,
		['u'] = &validate_specifier_u,
		['f'] = &validate_specifier_f,
		['p'] = &validate_specifier_p,
		['%'] = &validate_specifier_c,
		['b'] = &validate_specifier_b,
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif));
	else
		return ((errno = ENOTSUP));
}
