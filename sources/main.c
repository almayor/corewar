/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:14:21 by user              #+#    #+#             */
/*   Updated: 2020/11/16 04:00:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"


int		main()
{
	t_parser	*stor;

	stor = ft_calloc(1, sizeof(t_parser));
	mock_read(stor);	
	print_tokens(stor);

	// t_ops		op = op_tmpl[LLD];
	// printf("op_code = %d  args_num = %d  is_arg_code = %d  dir_size = %d\n", op.op_code, op.args_num, op.is_arg_code, op.dir_size);
	// printf("args types = %d  %d  %d\n", op.args_types[0], op.args_types[1], op.args_types[2]);

	// translation(stor);
	core_free(stor);
	return (0);
}