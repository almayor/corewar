/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:17:39 by user              #+#    #+#             */
/*   Updated: 2020/12/01 09:33:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALT_PARSER_H
# define ALT_PARSER_H

# include "asm_struct.h"
# include "libft.h"

# include <stdio.h>

# define ALT_COMMENT	';'
# define NAME_STEP		ft_strlen(NAME_CMD_STRING)
# define COMM_STEP		ft_strlen(COMMENT_CMD_STRING)

# define ALLOC_ERR			"NEW Error: Allocation error"
# define READ_ERR			"NEW Error: failed to read file"
# define UNX_COMM_ERR		"NEW Error: unexpected command"
# define LEN_CMD_ERR		"NEW Error: Command is to long"
# define LEX_ERR			"NEW Error: lexixal error"


void		alt_parsing(t_parser *stor);
int			reader(t_parser *stor);
void		skip_spaces(t_parser *stor);

void		parse_commons(t_parser *stor);
void		get_common(t_parser *stor, int step, int flag, int max);
void		check_common(t_parser *stor, int len, int max);


int			is_op(t_parser *stor, int st, int custom);
int			is_label(t_parser *stor);
int			is_comment(char c);

void		lexical_err(t_token *arg, t_parser *stor);
void		command_err(t_token *arg, t_parser *stor);

#endif