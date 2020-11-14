/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:02:09 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 13:02:13 by kysgramo         ###   ########.fr       */
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
}