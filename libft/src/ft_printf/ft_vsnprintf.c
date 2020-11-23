/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:26:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vsnprintf(3)`.
** @param[in] str String where to print output.
** @param[in] size Size of the string (at most `size - 1` characters are
** printed and, unless `size` is `0`, the string is always null-terminated).
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ap A variable used by `stdarg(3)` to step through a list of
** variadic arguments.
** @return Number of characters printed if `size` were unlimited (not
** including the final `\0`) or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported).
*/

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	set_output(T_STRING, (t_dest)str, (t_opt){size, 1});
	return (ft_vprintf(format, ap));
}
