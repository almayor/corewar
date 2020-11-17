/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:49:27 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/17 21:32:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			read_row(int fd, char **row)
{
	int size;

	if ((size = get_next_line(fd, row) <= 0))
	{
		if ((*row) == NULL)
			return (-1);
		if (size == -1)
			terminate(ERR_READING);
	}
	return (TRUE);
}

void		trim_from_comments_spaces(t_parser *parser, char *row)
{
	while (row[parser->x_read] == ' ' || row[parser->x_read] == '\t' ||
			row[parser->x_read] == '\n')
		parser->x_read++;
	if (row[parser->x_read] == COMMENT_CHAR ||
			row[parser->x_read] == ALT_COMMENT_CHAR)
		while (row[parser->x_read] && row[parser->x_read] != '\n')
			parser->x_read++;
	if (row[parser->x_read] == '\"')
		parser->x_read++;
}
