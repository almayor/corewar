/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:34:55 by user              #+#    #+#             */
/*   Updated: 2020/11/11 22:18:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_struct_new.h"
#include "../includes/translation.h"

void		calculate_code_size(t_frame *stor)
{
	t_token *head;

	head = stor->token;
	while (stor->token)
	{
		if (stor->token->type != NEW_LINE_TYPE)
			get_code_size(stor->token);
		stor->token = stor->token->next;
	}
	stor->token = head;
}

void		translate_common(t_frame *stor)
{
	write_magic(stor, COREWAR_EXEC_MAGIC);
	write_name(stor, PROG_NAME_LENGTH);
	write_comment(stor, COMMENT_LENGTH);
}


void		translation(t_frame *stor)
{
	if ((stor->fd_cor = open(stor->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
		core_error(stor, OPEN_COR_ERR);
	calculate_code_size(stor);
	translate_common(stor);
	translate_exec_code(stor);
	ft_putendl_fd("Writing output program to ", 1);
	ft_putendl_fd(stor->file_name, 1);
	close(stor->fd_cor);
}


