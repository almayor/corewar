/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:02:40 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 02:03:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	parse_flags(t_specifier *specif, const char **format, va_list ap)
{
	(void)ap;
	while (ft_strchr("#0- +", **format))
	{
		if (**format == '#')
			specif->hash = 1;
		else if (**format == '0')
			specif->zero = 1;
		else if (**format == '-')
			specif->minus = 1;
		else if (**format == ' ')
			specif->space = 1;
		else if (**format == '+')
			specif->plus = 1;
		(*format)++;
	}
}

static void	parse_width(t_specifier *specif, const char **format, va_list ap)
{
	if (**format == '*')
	{
		specif->width.isgiven = 1;
		specif->width.val = (va_arg(ap, int));
		*format += 1;
	}
	else if (ft_isdigit(**format))
	{
		specif->width.isgiven = 1;
		specif->width.val = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format += 1;
	}
}

static void	parse_precision(t_specifier *specif, const char **format,
							va_list ap)
{
	if (**format != '.')
		return ;
	specif->precision.isgiven = 1;
	*format += 1;
	if (**format == '*')
	{
		specif->precision.val = (va_arg(ap, int));
		*format += 1;
	}
	else if (ft_isdigit(**format))
	{
		specif->precision.val = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format += 1;
	}
	else
	{
		specif->precision.val = 0;
	}
}

static void	parse_length(t_specifier *specif, const char **format, va_list ap)
{
	(void)ap;
	if (ft_strnequ(*format, "hh", 2))
		specif->length = hh;
	else if (ft_strnequ(*format, "ll", 2))
		specif->length = ll;
	else if (ft_strnequ(*format, "h", 1))
		specif->length = h;
	else if (ft_strnequ(*format, "l", 1))
		specif->length = l;
	else if (ft_strnequ(*format, "L", 1))
		specif->length = L;
	else if (ft_strnequ(*format, "j", 1))
		specif->length = j;
	else
		specif->length = NONE;
	if (specif->length == h || specif->length == l ||
		specif->length == L || specif->length == z || specif->length == j)
		*format += 1;
	else if (specif->length == ll || specif->length == hh)
		*format += 2;
}

int			parse_specifier(t_specifier *specif, const char **format,
							va_list ap)
{
	*format += 1;
	parse_flags(specif, format, ap);
	parse_width(specif, format, ap);
	parse_precision(specif, format, ap);
	parse_length(specif, format, ap);
	specif->formatid = **format;
	*format += 1;
	return (0);
}
