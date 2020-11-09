/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 01:54:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	formatted_print(const char **format, va_list ap)
{
	t_specifier	specif;
	void		*data;
	int			rc;

	data = NULL;
	ft_memset(&specif, 0, sizeof(t_specifier));
	rc = parse_specifier(&specif, format, ap) ||
		validate_specifier(&specif) ||
		data_specifier(&specif, &data, ap) ||
		complete_specifier(&specif, data) ||
		print_specifier(&specif, data);
	free(data);
	return (rc);
}

static int	colors_print(const char **format, va_list ap)
{
	(void)ap;
	if (ft_strnequ(*format, "{eoc}", 5))
		pf_puts(KNRM);
	else if (ft_strnequ(*format, "{cyan}", 6))
		pf_puts(KCYN);
	else if (ft_strnequ(*format, "{red}", 5))
		pf_puts(KRED);
	else if (ft_strnequ(*format, "{green}", 7))
		pf_puts(KGRN);
	else if (ft_strnequ(*format, "{yellow}", 8))
		pf_puts(KYEL);
	else if (ft_strnequ(*format, "{blue}", 6))
		pf_puts(KBLU);
	else if (ft_strnequ(*format, "{magenta}", 9))
		pf_puts(KMAG);
	else
		return ((errno = ENOTSUP));
	while (**format != '}')
		*format += 1;
	*format += 1;
	return (0);
}

static void	simple_print(const char **format)
{
	pf_putchar(**format);
	*format += 1;
}

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vprintf(3)`.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ap A variable used by `stdarg(3)` to step through a list of
** variadic arguments.
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported) or other values set by `write(2)` (e.g. due to an
** invalid file descriiptor).
*/

int			ft_vprintf(const char *format, va_list ap)
{
	size_t		nprinted;
	static int	(*const dispatch_table[128])(const char **, va_list) = {
		['%'] = &formatted_print,
		['{'] = &colors_print,
	};

	while (*format)
	{
		if (*format < 0 || !dispatch_table[(unsigned char)*format])
			simple_print(&format);
		else if (dispatch_table[(unsigned char)*format](&format, ap))
		{
			cleanup();
			return (-1);
		}
	}
	nprinted = flush_buffer();
	cleanup();
	return (nprinted);
}
