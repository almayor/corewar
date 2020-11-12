/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:20:28 by unite             #+#    #+#             */
/*   Updated: 2020/11/12 21:06:12 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

/*
** @defgroup ft_printf ft_printf() family
** @brief Replicate behaviour of `printf(3)` functions.
** @details
** Support standard field values and combination thereof (where applicable):
** - flags: `#`, `0`, ` `, `-`, `+`
** - width and precision, including `*` options
** - length: `hh`, `h`, `l`, `ll`, `L`, `j`
** - type: `c`, `s`, `p`, `%`, `d`, `i`, `o`, `u`, `x`, `X`, `f`
**
** Custom specifications:
** - `b` type to print in binary format (supports same parameters as `i` type)
** - color support
**     - `cyan`
**     - `red`
**     - `green`
**     - `yellow`
**     - `blue`
**     - `magenta`
**
** @par To print in color
** <code> ft_printf("{red}Color-print. {eoc}Normal print."); </code><br>
**
** @see https://en.wikipedia.org/wiki/Printf_format_string
** @see https://linux.die.net/man/3/printf
*/

int	ft_vasprintf(char **ret, const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
int	ft_vprintf(const char *format, va_list ap);
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int	ft_vsprintf(char *str, const char *format, va_list ap);
int	ft_asprintf(char **ret, const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);
int	ft_snprintf(char *str, size_t size, const char *format, ...);
int	ft_sprintf(char *str, const char *format, ...);

#endif
