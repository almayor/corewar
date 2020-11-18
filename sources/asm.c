/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:02:09 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/17 22:15:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "translation.h"

void	check_escape2(char *balance, t_parser *parser, int escapes, int i)
{
	while (balance[i] != '\0')
	{
		if (balance[i++] == '\n')
			escapes++;
	}
	if (escapes != parser->y_read - 1)
		core_error(parser, ERR_ESCAPE);
}

void	check_escape(t_parser *parser, char *filename)
{
	static char	*stock[256];
	int			pkg;
	char		balance[9999 + 1];
	char		*wagon;

	if ((parser->fd_s = open(filename, O_RDONLY)) == -1)
		core_error(parser, ERR_OPEN_FILE);
	while ((pkg = read(parser->fd_s, balance, 9999)) > 0)
	{
		balance[pkg] = '\0';
		if (!stock[parser->fd_s])
			stock[parser->fd_s] = ft_strnew(1);
		wagon = ft_strjoin(stock[parser->fd_s], balance);
		free(stock[parser->fd_s]);
		stock[parser->fd_s] = ft_strdup(wagon);
		free(wagon);
		if (ft_strchr(balance, '\0'))
			break ;
	}
	check_escape2(balance, parser, 0, 0);
}

void	assembler(char *filename)
{
	t_parser	*parser;

	parser = init_asm_parser();
	if ((parser->fd_s = open(filename, O_RDONLY)) == -1)
		core_error(parser, ERR_OPEN_FILE);
	parsing(parser, 0);
	close(parser->fd_s);
	check_escape(parser, filename);
	parser->file_name = ft_strjoin_free(ft_strsub(filename, 0,
				ft_strlen(filename) - 2), ".cor");
	
	translation(parser);
	// simple_parser_print_(parser);
	// print_tokens_(parser);
	// print_labels_(parser);


	core_free(parser);
}
