/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct_new.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:21:50 by user              #+#    #+#             */
/*   Updated: 2020/11/11 22:31:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASM_STRUCT_NEW_H_
# define _ASM_STRUCT_NEW_H_

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
	int				x;
	int				y;
}					t_point;

typedef struct		s_token
{
	int				type;
	char			*content;
	t_point			point;
	int				size;
	unsigned char	op_code;
	unsigned char	arg_code;
	int				dir_size;
	struct s_token	*next;
}					t_token;


typedef struct		s_frame
{
	char			*line;
	t_point			point;
	t_token			*token;
	int				fd_cor;
	int				ft_s;
	char			*file_name;
	char			*name;
	char			*comment;
}					t_frame;

#endif