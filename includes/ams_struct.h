/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ams_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:08:25 by user              #+#    #+#             */
/*   Updated: 2020/11/10 02:11:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASM_STRUCT_H_
# define _ASM_STRUCT_H_

/*
	Struct to store the operation after lexical analiz
	
	stores like:
Example operation 

loop:
        sti r1, %:live, %1

node # 1: sti r1, %:label, %1
	list_index = 0;
	byte_size = 0;
	name = "sti"
	op_code = 11
	arg_code = 1
	arg1 = "01r1"
	arg2 = "10label" // // need to discuss how to store labels
	arg3 = "101"
	dir_size = 2


*/

typedef	struct		s_ops
{
	int				list_index;	// here is just the index of node in list
	int				byte_size;	// 0 on parser. I'll set in on translation
	char	*name;
	int				op_code;
	int				arg_code;	// 1 or 0 - in case of arg_code for this operation exist or not
	unsigned char	arg1;		// stores like "01arg" where 01 is the code of ard type. REG_type = 01 | DIR_type = 10 | IND_type = 11
	unsigned char	arg2;		// stores the same way
	unsigned char	arg3;		// stores the same way
	// label (need to discuss how to store it). May be the good idea is to use t_point struct
	int				dir_size;
	struct s_ops	*next;
}					t_ops;


/*
	main struct to store all data
*/

typedef	struct		s_parser
{
	char			*read_file_name;
	int				write_file_fd;
	t_ops			*ops;
	char			*champ_name;
	char			*champ_comment;
	// smth else

}					t_parser;

#endif
