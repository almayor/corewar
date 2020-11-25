/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_pc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:04:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_pc(t_specifier *specif, void **data, va_list ap)
{
	(void)ap;
	(void)specif;
	if (!(*data = malloc(sizeof(char))))
		return ((errno = ENOMEM));
	*(char *)*data = '%';
	return (0);
}
