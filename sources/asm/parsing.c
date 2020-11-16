/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:09:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:16:03 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	trim_from_comments_spaces(t_parser *parser, char *row)
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

void		add_token(t_token **tokens, t_token *token)
{
	t_token *curr;

	if (tokens && *tokens)
	{
		curr = *tokens;
		while (curr->next)
			curr = curr->next;
		curr->next = token;
		token->point.token++;
	}
	else
	{
		*tokens = token;
		token->point.token = 0;
	}
}

void		parse_token(t_parser *parser, char **row)
{
	if (*(*row + parser->x_read) == SEPARATOR_CHAR && ++parser->x_read)
		add_token(&parser->tokens, init_token(parser, DELIM_TYPE));
	else if (*(*row + parser->x_read) == '\n' && ++parser->x_read)
		add_token(&parser->tokens, init_token(parser, NEW_LINE_TYPE));
	else if (*(*row + parser->x_read) == '.' && ++parser->x_read)
		parse_command(parser, row, parser->x_read);
	else if (*(*row + parser->x_read) == DIRECT_CHAR && ++parser->x_read)
	{
		if (*(*row + parser->x_read) == LABEL_CHAR && ++parser->x_read)
			parse_alpha(parser, *row, parser->x_read,
					init_token(parser, DIR_LABL_ARG_TYPE));
		//else
		//	parse_digit(parser, *row, parser->x_read, init_token(parser, DIR_ARG_TYPE))	
	}

	else if (ft_strchr(LABEL_CHARS, *(*row + parser->x_read)))
	{
		if (ft_isalpha(*(*row + parser->x_read)))
			parse_alpha(parser, *row, parser->x_read, init_token(parser, UNKNOWN));
	}	
	//else
	//add_token(&parser->tokens, init_token(parser, INDIRECT_LABEL));*/
}

void		parsing(t_parser *parser)
{
	char	*row;

	while (++parser->point.row && read_row(parser->fd_s, &row) > 0)
	{
		ft_printf("%d\n", ft_strlen(row));
		parser->x_read = 0;
		ft_printf("%s\n", row);
		while (row[parser->x_read])
		{
			trim_from_comments_spaces(parser, row);
			if (row[parser->x_read])
				parse_token(parser, &row);
		}
		ft_strdel(&row);

	}
	validate_commands(parser);
	ft_printf("%s\n", parser->name);
	ft_printf("%s\n", parser->comment);
}

/* 
 ** ++parser->point->x - read by symbol
 ** && !(parser->point->y == 0) - ignore empty rows
 ** && read_x(parser->fd_s, &row) - row is not NULL
 */
