/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:43:25 by user              #+#    #+#             */
/*   Updated: 2020/11/17 22:34:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The assembler header file
*/

#ifndef ASM_H

# define ASM_H
# include "asm_struct.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0
# define ALT_COMMENT_CHAR  ';'

# define ERR_OPEN_FILE			"Error: can not open file"
# define ERR_PARSER_INIT		"Error: can not initiate parsing of this file"
# define ERR_LABEL_INIT			"Error: can not initiate a label"
# define ERR_STR_INIT			"Error: can not initiate name of label"
# define ERR_READING			"Error: read the lines of .s file"
# define ERR_TOKEN_INIT			"Error: can not initiate a token"
# define ERR_POINT_INIT			"Error: can not initiate point structure"
# define ERR_COMMAND			"Error: non-existing command"
# define ERR_NO_NAME			"Error: no champion name"
# define ERR_NO_COMMENT			"Error: no champion comment"
# define ERR_TOO_LONG_NAME		"Error: too long name"
# define ERR_TOO_LONG_COMMENT	"Error: too long comment"
# define ERR_ESCAPE				"Error: escape missed"

void			terminate(char *s);
void			assembler(char *filename);
t_parser		*init_asm_parser(void);
void			parsing(t_parser *parser, int tok_len);
t_token			*init_token(t_parser *parser, t_type type);
void			parse_alpha(t_parser *parser, char *row, int y_start,
t_token *token);
void			parse_command(t_parser *parser, char **row, int start);
void			add_token(t_token **tokens, t_token *token);
void			trim_from_comments_spaces(t_parser *parser, char *row);
int				read_row(int fd, char **row, t_parser *parser);
char			*get_token_content(t_parser *parser, char *row, int start);
t_label			*init_label(char *content, int row_num, int token_num,
t_parser *parser);
void			parse_digit(t_parser *parser, char *row, int start,
t_token *token);
void			add_label(t_label **labels, t_label *label);
void			coords_and_labels(t_parser *parser, t_token *tokens, int tok_num);
void			improve_coords(t_token *tokens);
void			print_tokens(t_token *tokens);
void			print_labels(t_label *labels);
void			validate_commands(t_parser *parser);
int				is_register(t_token *token);
int				is_operation(t_token *token);
int				is_delimiter(int c);
void			trim_from_comments_spaces(t_parser *parser, char *row);
void		    lexical_error(t_parser *parser);
void			core_error(t_parser *stor, char *message);

#endif
