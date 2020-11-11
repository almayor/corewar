/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:34:55 by user              #+#    #+#             */
/*   Updated: 2020/11/11 23:02:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_struct.h"
#include "../includes/translation.h"

void		calculate_code_size(t_parser *stor)
{
	t_token *head;

	head = stor->tokens;
	while (stor->tokens)
	{
		if (stor->tokens->type != NEW_LINE_TYPE)
			get_code_size(stor->tokens);
		stor->tokens = stor->tokens->next;
	}
	stor->tokens = head;
}

void		translate_common(t_parser *stor)
{
	write_magic(stor, COREWAR_EXEC_MAGIC);
	write_name(stor, PROG_NAME_LENGTH);
	write_comment(stor, COMMENT_LENGTH);
}


void		translation(t_parser *stor)
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
