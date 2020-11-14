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
	COMMAND,
	LABEL_TYPE,
	DELIM_TYPE,
	OP_TYPE,
	REG_ARG_TYPE,
	DIR_ARG_TYPE,
	DIR_LABL_ARG_TYPE,
	IND_ARG_TYPE,
	IND_LABL_ARG_TYPE,
	END_FILE,
}					t_type;


typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_token
{
	int				type;
	char			*content;
	t_point			*point;
	int				size;
	unsigned char	*op_code;
	int				is_arg_code;
	unsigned char	*arg_code;
	int				dir_size;
	struct s_token	*next;
}					t_token;
/*
typedef struct			s_mention
{
	unsigned			x_read;
	unsigned			y_read;
	int32_t				x_write;
	int32_t				y_write;
	size_t				size;
	struct s_mention	*next;
}						t_mention;

typedef struct			s_label
{
	char				*name;
	int32_t				op_pos;
	t_mention			*mentions;
	struct s_label		*next;
}						t_label;
*/

typedef struct		s_parser
{
	t_point			*point;
	t_token			*tokens;
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
void			parsing(t_parser *parser);
t_token			*init_token(t_parser *parser, t_type type);
void			parse_symbols(t_parser *parser, char *row, unsigned y_start,
t_token *token);

# define ERR_OPEN_FILE		"Error: can not open file"
# define ERR_PARSER_INIT	"Error: can not initiate parsing of this file"
# define ERR_LABEL_INIT		"Error: can not initiate a label"
# define ERR_STR_INIT		"Error: can not initiate name of label"
# define ERR_READING		"Error: read the lines of .s file"
# define ERR_TOKEN_INIT		"Error: can not initiate a token"
# define ERR_POINT_INIT		"Error: can not initiate point structure"

#endif
