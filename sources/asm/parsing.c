/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:09:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 14:10:01 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			read_x(int fd, char **row)
{
	int size;

	if ((size = get_next_line(fd, row) > 0))
	{
		//row[size] = '\0';
	}
	if ((*row) == NULL)
		return (-1);
	if (size == -1)
		terminate(ERR_READING);
	return (TRUE);
}

void	trim_from_comments_spaces(t_parser *parser, char *row)
{
	while (row[parser->point->y] == ' ' || row[parser->point->y] == '\t' ||
	row[parser->point->y] == '\n')
		parser->point->y++;
	if (row[parser->point->y] == COMMENT_CHAR ||
	row[parser->point->y] == ALT_COMMENT_CHAR)
		while (row[parser->point->y] && row[parser->point->y] != '\n')
			parser->point->y++;
}

void		add_token(t_token **tokens, t_token *token)
{
	t_token *curr;

	if (tokens && *tokens)
	{
		curr = *tokens;
		while (curr->next)
			curr = curr->next;
		if (curr->type == NEW_LINE_TYPE && token->type == NEW_LINE_TYPE)
			ft_memdel((void **)token);
		else
			curr->next = token;
	}
	else
	{
		if (token->type == NEW_LINE_TYPE)
			ft_memdel((void **)token);
		else
			*tokens = token;
	}
}

void		parse_token(t_parser *parser, char **row)
{
	if (*row[parser->point->y] == SEPARATOR_CHAR && ++parser->point->y)
		add_token(&parser->tokens, init_token(parser, SEPARATOR_CHAR));
	else if (*row[parser->point->y] == '\n' && ++parser->point->y)
		add_token(&parser->tokens, init_token(parser, NEW_LINE_TYPE));
	else if (*row[parser->point->y] == '.' && ++parser->point->y)
		parse_symbols(parser, *row, parser->point->y++,
		init_token(parser, COMMAND));
	/*else if (row[parser->y_read] == DIRECT_CHAR && ++parser->y_read)
		//add_token(&parser->tokens, init_token(parser, NEW_LINE));
	else if (row[parser->y_read] == '\"' && ++parser->y_read)
		//add_token(&parser->tokens, init_token(parser, STRING));
	//else if (row[parser->y_read] == LABEL_CHAR && ++parser->y_read)
	//	add_token(&parser->tokens, init_token(parser, ));
	else
		//add_token(&parser->tokens, init_token(parser, INDIRECT_LABEL));*/
}

void		parsing(t_parser *parser)
{
	char	*row;

	while (++parser->point->x && !(parser->point->y == 0) &&
	read_x(parser->fd_s, &row) > 0)
	{
		while (row[parser->point->x])
		{
			trim_from_comments_spaces(parser, row);
			if (row[parser->point->x])
				parse_token(parser, &row);
		}
		ft_strdel(&row);

	}
}