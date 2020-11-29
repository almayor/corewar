/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:30:02 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 02:06:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	validate_commands(t_parser *parser)
{
	if (parser->name == NULL)
		core_error(parser, ERR_NO_NAME, NULL, NULL);
	if (parser->comment == NULL)
		core_error(parser, ERR_NO_COMMENT, NULL, NULL);
	if ((ft_strlen(parser->name) + parser->name_len) > PROG_NAME_LENGTH)
		core_error(parser, ERR_TOO_LONG_NAME, NULL, NULL);
	if ((ft_strlen(parser->comment) + parser->comment_len) > COMMENT_LENGTH)
		core_error(parser, ERR_TOO_LONG_COMMENT, NULL, NULL);
}

char	*join_str(char **str1, char **str2)
{
	char *result;

	result = ft_strjoin(*str1, *str2);
	ft_strdel(str1);
	ft_strdel(str2);
	return (result);
}

void	type_check(t_parser *parser, int type)
{
	if (type == 1)
	{
		if (parser->name != NULL)
			core_error(parser, ERR_DOUBLE_COMMAND, NULL, NULL);
	}
	else
	{
		if (parser->comment != NULL)
			core_error(parser, ERR_DOUBLE_COMMAND, NULL, NULL);
	}
}

void	parse_command2(t_parser *parser, char **row, int start, int type)
{
	char	*str;
	char	*end;

	while (!(end = ft_strchr(&((*row)[start]), '\"')) &&
	(read_row(parser->fd_s, &str, parser) > 0) &&
	++parser->y_read && ++parser->row_len)
		*row = join_str(row, &str);
	while (**row && *(*row + parser->x_read) != '\"')
		++parser->x_read;
	if ((str = ft_strchr(&((*row)[++parser->x_read]), '\"')))
	{
		ft_strdel(row);
		core_error(parser, ERR_DOUBLE_COMMAND, NULL, NULL);
	}
	trim_from_comments_spaces(parser, *row);
	if (type == 1)
	{
		parser->name_len = parser->row_len;
		parser->name = ft_strsub(*row, start, (int)(end - &((*row)[start])));
	}
	else
	{
		parser->comment_len = parser->row_len;
		parser->comment = ft_strsub(*row, start, (int)(end - &((*row)[start])));
	}
}

/*
** add new rows to *row until you meet '"'
** check that parsing is right
** using ft_strsub pus command ito the token
*/

void	parse_command(t_parser *parser, char **row, int start)
{
	int		type;
	char	*tmp;

	type = 0;
	while (*(*row + parser->x_read) && ft_strchr(LABEL_CHARS,
	*(*row + parser->x_read)))
		parser->x_read++;
	tmp = get_token_content(parser, *row, start);
	if (!ft_strcmp(tmp, "name"))
		type = 1;
	else if (!ft_strcmp(tmp, "comment"))
		type = 2;
	else
		core_error(parser, ERR_COMMAND, NULL, NULL);
	free(tmp);
	trim_from_comments_spaces(parser, *row);
	type_check(parser, type);
	parse_command2(parser, row, parser->x_read, type);
}
