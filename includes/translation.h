/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:46 by user              #+#    #+#             */
/*   Updated: 2020/11/16 13:13:55 by user             ###   ########.fr       */
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


/*
**	Utils to handle error cases and memory management
*/

void		core_error(t_parser *stor, char *message);
void		core_free(t_parser *stor);
void		free_parser(t_parser *stor);
void		free_tokens(t_parser *stor);




// TMP UTILS - DELETE

void	mock_read(t_parser *stor);
void	print_tokens(t_parser *stor);
void	print_labels(t_parser *stor);


#endif