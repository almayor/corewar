/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:21:50 by user              #+#    #+#             */
/*   Updated: 2020/11/16 13:12:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASM_STRUCT_H_
# define _ASM_STRUCT_H_

# define NAME_FLAG 1
# define COMMENT_FLAG 0

# define OPEN_COR_ERR	"Error: can't open file .cor"

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
}					t_type;

typedef union		u_four
{
	unsigned		val;
	struct			s_fr
	{
		unsigned char	c1:8;
		unsigned char	c2:8;
		unsigned char	c3:8;
		unsigned char	c4:8;
	}				t_fr;
}					t_four;

typedef union		u_two
{
	unsigned short	val;
	struct			s_tw
	{
		unsigned char	c1:8;
		unsigned char	c2:8;
	}				t_tw;
}					t_two;


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
	t_point			*point;
	t_token			*tokens;
	t_label			*labels;
	int				x_read;
	int				fd_cor;
	int				fd_s;
	int				code_total_size;
	char			*file_name;
	char			*name;
	char			*comment;
}					t_parser;

#endif
