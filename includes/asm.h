/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:25:01 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/08 19:25:05 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The assembler header file
*/
#ifndef ASM_H

# define ASM_H
# include "op.h"
# include "operations.h"
# include "../libft/ft_printf/inc/ft_printf.h"
# include "../libft/libft.h"
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

typedef enum
{
	NEW_LINE_TYPE,
	LABEL_TYPE,
	DELIM_TYPE,
	OP_TYPE,
	REG_ARG_TYPE,
	DIR_ARG_TYPE,
	DIR_LABL_ARG_TYPE,
	IND_ARG_TYPE,
	IND_LABL_ARG_TYPE,
	END_FILE,
	UNKNOWN,
}						t_type;

// when we dont know type yet, let's use as default  
// OP_TYPE as the most frequent type for string starting with LABEL_CHARS


typedef struct		s_point
{
	int				token;
	int				row;
}					t_point;

typedef struct		s_label
{
	char			*content;
	t_point			point;
	struct s_label	*next;
}					t_label;

typedef struct		s_token
{
	int				type;
	char			*content;
	t_point			point;
	int				size;
	unsigned char	*op_code;
	int				is_arg_code;
	unsigned char	*arg_code;
	int				dir_size;
	struct s_token	*next;
}					t_token;

typedef struct		s_parser
{
	t_point			point;
	t_token			*tokens;
	t_label			*labels;
	int				x_read;
	int				y_read;
	int				tok_len;
	int				fd_cor;
	int				fd_s;
	int				code_total_size;
	char			*file_name;
	char			*name;
	char			*comment;
}					t_parser;

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
int				read_row(int fd, char **row);
char			*get_token_content(t_parser *parser, char *row, int start);
t_label			*init_label(char *content, int row_num, int token_num);
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
int				read_row(int fd, char **row);

# define ERR_OPEN_FILE		"Error: can not open file"
# define ERR_PARSER_INIT	"Error: can not initiate parsing of this file"
# define ERR_LABEL_INIT		"Error: can not initiate a label"
# define ERR_STR_INIT		"Error: can not initiate name of label"
# define ERR_READING		"Error: read the lines of .s file"
# define ERR_TOKEN_INIT		"Error: can not initiate a token"
# define ERR_POINT_INIT		"Error: can not initiate point structure"
# define ERR_COMMAND		"Error: non-existing command"
# define ERR_NO_NAME		"Error: no champion name"
# define ERR_NO_COMMENT		"Error: no champion comment"
# define ERR_TOO_LONG_NAME		"Error: too long name"
# define ERR_TOO_LONG_COMMENT	"Error: too long comment"

#endif
