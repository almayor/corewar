/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:46 by user              #+#    #+#             */
/*   Updated: 2020/11/18 19:12:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRANSLATION_H_
# define _TRANSLATION_H_

# include <stdio.h>		// for printf - DELETE

# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "asm_struct.h"

/*
**	Translation to byte code
*/

void		translation(t_parser *stor);
void		translate_commons(t_parser *stor);

void		write_name_or_comment(t_parser *stor, int len, int kind);
void		int_writer(t_parser *stor, unsigned int data);
int			byte_writer(t_parser *stor, unsigned char c);
void		short_writer(t_parser *stor, short data);

void		enrich_data(t_parser *stor);
int			enrich_row(t_parser *stor, t_token *token);
int			op_args(t_parser *stor, t_token *token, int name);
int			get_arg(t_parser *stor, t_token *arg, int name, int shift);
t_token		*get_token(t_token *token, int len);

int			find_label_value(t_parser *stor, t_token *dst, int dst_size);
t_token		*get_start_token(t_parser *stor, t_label *label);
t_label		*get_label(t_parser *stor, char *name);
int			calc_value(t_token *start, t_token *dst, int arg_line_size);

void		translate_exec_code(t_parser *stor);
int			translate_exec_row(t_parser *stor, t_token *token);
void		translate_arg(t_parser *stor, t_token *token, int size);

/*
**	Utils to handle error cases and memory management
*/

void		core_error(t_parser *stor, char *message);
void		core_free(t_parser *stor);
void		free_parser(t_parser *stor);
void		free_tokens(t_parser *stor);
void		free_labels(t_parser *stor);



// TMP UTILS - DELETE

void	mock_read_(t_parser *stor);
void	print_tokens_(t_parser *stor);
void	print_labels_(t_parser *stor);
void	simple_tokens_print_(t_parser *stor);
void	simple_parser_print_(t_parser *stor);
void	test_label_value_(t_parser *stor);

#endif
