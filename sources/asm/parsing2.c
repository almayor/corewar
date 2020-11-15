/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:42:53 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 18:43:38 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_token_content(t_parser *parser, char *row, int start)
{
	char	*content;

	if (!(content = ft_strsub(row, start, parser->x_read - start)))
		terminate(ERR_STR_INIT);
	return (content);
}
/*
void    parse_num(t_parser *parser, char *row, int start,
t_token *token)
{
	token->point->row = start;
	if (row[parser->x_read] == '-')
		parser->x_read++;
}
*/
/*
void	parse_alpha(t_parser *parser, char *row, int start,
t_token *token)
{
	start = parser->x_read;
	while (row[parser->x_read] && ft_strchr(LABEL_CHARS, row[parser->x_read]))
		parser->x_read++;

}*/
// move by one symbol until LABEK_CHAR
// check that all symbols are from LABEL_CHARS
// detect token type - direct or indirect
// write in token?

void	parse_command(t_parser *parser, char *row, int start)
{
	int	type;

	type = 0;
	while (row[parser->x_read] && ft_strchr(LABEL_CHARS, row[parser->x_read]))
		parser->x_read++;
	if (!ft_strcmp(get_token_content(parser, row, start), "name")) 
		type = 1;
	else if (!ft_strcmp(get_token_content(parser, row, start), "comment"))
		type = 2;
	else
		terminate(ERR_COMMAND); 
	while (row[parser->x_read++] != '\"')
		start = parser->x_read;
	start++;
	while (row[parser->x_read] != '\"')
		parser->x_read++;
	if (type == 1)
		parser->name = get_token_content(parser, row, start);
	else
		parser->comment = get_token_content(parser, row, start);

}