/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:02:09 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:15:00 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assembler(char *filename)
{
	t_parser	*parser;

	parser = init_asm_parser();
	if ((parser->fd_s = open(filename, O_RDONLY)) == -1)
		terminate(ERR_OPEN_FILE);
	parsing(parser);
	parser->file_name = ft_strjoin(ft_strsub(filename, 0,
				ft_strlen(filename) - 2), ".cor");
	//ft_putendl(parser->file_name);
}
