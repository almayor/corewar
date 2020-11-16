/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:46 by user              #+#    #+#             */
/*   Updated: 2020/11/16 22:44:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRANSLATION_H_
# define _TRANSLATION_H_

# include <stdio.h>

# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "asm_struct.h"
# include "op.h"
# include "operations.h"

/*
**	Translation to byte code
*/

void		translation(t_parser *stor);
void		translate_commons(t_parser *stor);

void		write_name_or_comment(t_parser *stor, int len, int kind);
void		translate_exec_code(t_parser *stor);

int			get_code_size(t_token *token);

void		string_writer(int fd, char *data, int len);
void		int_writer(t_parser *stor, unsigned int data);


void		enrich_data(t_parser *stor);
t_token		*get_token(t_token *token, int len);
int			prepare_arg(t_parser *stor, t_token *dst, int name, int shift);


//			short version
int			enrich_line(t_parser *stor, t_token *token);
int			op_two_args(t_parser *stor, t_token *token, int name);
int			op_three_args(t_parser *stor, t_token *token, int name);
int			op_reg_reg_reg(t_parser *stor, t_token *token, int name);
int			op_dir(t_parser *stor, t_token *token, int name);
int			op_reg(t_parser *stor, t_token *token, int name);

// //			wide version
// int			enrich_line_wide(t_parser *stor, t_token *token);
// int			op_dir(t_parser *stor, t_token *token, int name);
// int			op_dirind_reg(t_parser *stor, t_token *token, int name);
// int			op_reg_regind(t_parser *stor, t_token *token, int name);
// int			op_reg_reg_reg(t_parser *stor, t_token *token, int name);
// int			op_regdirind_regdirind_reg(t_parser *stor, t_token *token, int name);
// int			op_regdirind_regdir_reg(t_parser *stor, t_token *token, int name);
// int			op_reg_regdirint_regdir(t_parser *stor, t_token *token, int name);
// int			op_reg(t_parser *stor, t_token *token, int name);


/*
**	Utils to handle error cases and memory management
*/

void		core_error(t_parser *stor, char *message);
void		core_free(t_parser *stor);
void		free_parser(t_parser *stor);
void		free_tokens(t_parser *stor);
void		free_labels(t_parser *stor);




// TMP UTILS - DELETE

void	mock_read(t_parser *stor);
void	print_tokens(t_parser *stor);
void	print_labels(t_parser *stor);
void	simple_token_print(t_parser *stor);
void	simple_parser_print(t_parser *stor);


#endif