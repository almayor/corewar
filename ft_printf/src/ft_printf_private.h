/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:31:07 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:42:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdint.h>
# include "libft.h"

# define BUFFER_SIZE	1024

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"

typedef struct	s_opt
{
	intmax_t		val;
	int				isgiven;
}				t_opt;

typedef enum	e_mode
{
	T_FILE, T_STRING
}				t_mode;

typedef union	u_dest
{
	int				fd;
	char			*str;
}				t_dest;

typedef struct	s_output
{
	t_mode			mode;
	t_dest			dest;
	t_opt			max_size;
}				t_output;

typedef enum	e_length
{
	NONE, h, l, hh, ll, L, j, z
}				t_length;

typedef struct	s_specifier
{
	int				zero;
	int				minus;
	int				space;
	int				hash;
	int				plus;
	t_opt			precision;
	t_opt			width;
	t_length		length;
	unsigned char	formatid;
	size_t			npad_precision;
	size_t			npad_width;
}				t_specifier;

/*
** printf family
*/

int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, const char *format,
							va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

/*
** dispatchers
*/

int				parse_specifier(t_specifier *specif, const char **format,
								va_list ap);

int				validate_specifier(t_specifier *specif);
int				validate_specifier_c(t_specifier *specif);
int				validate_specifier_f(t_specifier *specif);
int				validate_specifier_i(t_specifier *specif);
int				validate_specifier_p(t_specifier *specif);
int				validate_specifier_s(t_specifier *specif);
int				validate_specifier_u(t_specifier *specif);
int				validate_specifier_x(t_specifier *specif);
int				validate_specifier_b(t_specifier *specif);

int				data_specifier(t_specifier *specif, void **data, va_list ap);
int				data_specifier_c(t_specifier *specif, void **data, va_list ap);
int				data_specifier_f(t_specifier *specif, void **data, va_list ap);
int				data_specifier_i(t_specifier *specif, void **data, va_list ap);
int				data_specifier_p(t_specifier *specif, void **data, va_list ap);
int				data_specifier_pc(t_specifier *specif, void **data, va_list ap);
int				data_specifier_s(t_specifier *specif, void **data, va_list ap);
int				data_specifier_u(t_specifier *specif, void **data, va_list ap);

int				complete_specifier(t_specifier *specif, void *data);
int				complete_specifier_c(t_specifier *specif, void *data);
int				complete_specifier_f(t_specifier *specif, void *data);
int				complete_specifier_i(t_specifier *specif, void *data);
int				complete_specifier_o(t_specifier *specif, void *data);
int				complete_specifier_p(t_specifier *specif, void *data);
int				complete_specifier_s(t_specifier *specif, void *data);
int				complete_specifier_u(t_specifier *specif, void *data);
int				complete_specifier_x(t_specifier *specif, void *data);
int				complete_specifier_b(t_specifier *specif, void *data);

int				print_specifier(t_specifier *specif, void *data);
int				print_specifier_c(t_specifier *specif, void *data);
int				print_specifier_f(t_specifier *specif, void *data);
int				print_specifier_i(t_specifier *specif, void *data);
int				print_specifier_o(t_specifier *specif, void *data);
int				print_specifier_p(t_specifier *specif, void *data);
int				print_specifier_s(t_specifier *specif, void *data);
int				print_specifier_u(t_specifier *specif, void *data);
int				print_specifier_x(t_specifier *specif, void *data);
int				print_specifier_xx(t_specifier *specif, void *data);
int				print_specifier_b(t_specifier *specif, void *data);

/*
** printing
*/

int				pf_putchar(char c);
int				pf_puts(const char *str);
int				pf_putnchar(char c, size_t n);
int				pf_putint(intmax_t num, const char *radix);
int				pf_putuint(uintmax_t num, const char *radix);
int				pf_putfloat(long double num, const char *radix,
							size_t precision, int print_dot);

void			set_output(t_mode mode, t_dest dest, t_opt max_size);
void			cleanup(void);
ssize_t			flush_buffer(void);

/*
** utils
*/

size_t			min(size_t a, size_t b);
size_t			get_ndigits_int(intmax_t num, size_t base_len);
size_t			get_ndigits_uint(uintmax_t num, size_t base_len);

#endif
