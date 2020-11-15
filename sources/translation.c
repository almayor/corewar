/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:34:55 by user              #+#    #+#             */
/*   Updated: 2020/11/16 00:45:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

void		translate_exec_code(t_parser *stor)
{
	return ;
}

// int			enrich_code_line(t_token **token)
// {
// 	while ((*token)->type != NEW_LINE_TYPE)
// 	{
		
// 	}
// }



// void		enrich_data(t_parser *stor)
// {
// 	t_token 	*token;
// 	int			cmd_size;

// 	cmd_size = 0;
// 	token = stor->tokens;
// 	while (token)
// 	{
// 		enrich_code_line(*token);
// 		token = token->next;
// 	}

// }

void		translate_commons(t_parser *stor)
{
	int_writer(stor, COREWAR_EXEC_MAGIC);
	write_name_or_comment(stor, PROG_NAME_LENGTH, NAME_FLAG);
	int_writer(stor, 0); // here we fill zeros for 4 bytes of exec_code_size (in the end fill it with real value by l_seek to this point)
						 // l_seek: 1. On the start of the file. 2. 4 (magic) + PROG_NAME_LENGTH + 4 (NULL)
	write_name_or_comment(stor, COMMENT_LENGTH, COMMENT_FLAG);
}


void		translation(t_parser *stor)
{
	if ((stor->fd_cor = open(stor->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
		core_error(stor, OPEN_COR_ERR);
	// enrich_data(stor);
	translate_commons(stor);
	translate_exec_code(stor);
	ft_putstr("Writing output program to ");
	ft_putendl_fd(stor->file_name, 1);
	close(stor->fd_cor);
}
