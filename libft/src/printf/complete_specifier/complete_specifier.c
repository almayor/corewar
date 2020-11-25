/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:03:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier(t_specifier *specif, void *data)
{
	static int	(*const dispatch_table[128])(t_specifier *, void *) = {
		['c'] = &complete_specifier_c,
		['s'] = &complete_specifier_s,
		['i'] = &complete_specifier_i,
		['d'] = &complete_specifier_i,
		['x'] = &complete_specifier_x,
		['X'] = &complete_specifier_x,
		['o'] = &complete_specifier_o,
		['u'] = &complete_specifier_u,
		['f'] = &complete_specifier_f,
		['p'] = &complete_specifier_p,
		['%'] = &complete_specifier_c,
		['b'] = &complete_specifier_b,
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data));
	else
		return ((errno = ENOTSUP));
}
