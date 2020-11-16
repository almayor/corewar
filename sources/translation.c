/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:34:55 by user              #+#    #+#             */
/*   Updated: 2020/11/16 22:48:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

void		translate_exec_code(t_parser *stor)
{
	
	return ;
}

void		enrich_data(t_parser *stor)
{
	int		len;

	len = 0;
	while (stor->tokens)
	{
		len = enrich_line(stor, stor->tokens);
		while (len)
		{
			stor->tokens = stor->tokens->next;
			len--;
		}
	}
	stor->tokens = stor->tokens_head;
}

void		translate_commons(t_parser *stor)
{
	int_writer(stor, COREWAR_EXEC_MAGIC);
	write_name_or_comment(stor, PROG_NAME_LENGTH, NAME_FLAG);
	int_writer(stor, stor->code_total_size); 

	write_name_or_comment(stor, COMMENT_LENGTH, COMMENT_FLAG);
	
}


void		translation(t_parser *stor)
{
	if ((stor->fd_cor = open(stor->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
		core_error(stor, OPEN_COR_ERR);
	enrich_data(stor);
	translate_commons(stor);
	translate_exec_code(stor);
	ft_putstr("Writing output program to ");
	ft_putendl_fd(stor->file_name, 1);
	close(stor->fd_cor);
}
