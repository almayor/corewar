/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:30:02 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/17 20:47:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	validate_commands(t_parser *parser)
{
	if (parser->name == NULL)
		terminate(ERR_NO_NAME);
	if (parser->comment == NULL)
		terminate(ERR_NO_COMMENT);
	if (ft_strlen(parser->name) > PROG_NAME_LENGTH)
		terminate(ERR_TOO_LONG_NAME);
	if (ft_strlen(parser->comment) > COMMENT_LENGTH)
		terminate(ERR_TOO_LONG_COMMENT);
}

char	*join_str(char **str1, char **str2)
{
	char *result;

	if (!(result = ft_strjoin(*str1, *str2)))
		terminate(ERR_STR_INIT);
	ft_strdel(str1);
	ft_strdel(str2);
	return (result);
}

void	parse_command2(t_parser *parser, char **row, int start, int type)
{
	int		size;
	char	*str;
	char	*end;

	while (!(end = ft_strchr(&((*row)[start]), '\"')) &&
	(size = read_row(parser->fd_s, &str) > 0) &&
	++parser->y_read)
		*row = join_str(row, &str);
	if (size == -1)
		terminate(ERR_READING);
	while (*(*row + parser->x_read))
		parser->x_read++;
	if (type == 1)
		parser->name = ft_strsub(*row, start, (int)(end - &((*row)[start])));
	else
		parser->comment = ft_strsub(*row, start, (int)(end - &((*row)[start])));
}

/*
** add new rows to *row until you meet '"'
** check that parsing is right
** using ft_strsub pus command ito the token
*/

void	parse_command(t_parser *parser, char **row, int start)
{
	int	type;

	type = 0;
	while (*(*row + parser->x_read) && ft_strchr(LABEL_CHARS,
	*(*row + parser->x_read)))
		parser->x_read++;
	if (!ft_strcmp(get_token_content(parser, *row, start), "name"))
		type = 1;
	else if (!ft_strcmp(get_token_content(parser, *row, start), "comment"))
		type = 2;
	else
		terminate(ERR_COMMAND);
	trim_from_comments_spaces(parser, *row);
	parse_command2(parser, row, parser->x_read, type);
}
