/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:14:36 by user              #+#    #+#             */
/*   Updated: 2020/11/30 21:09:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alt_parser.h"
#include "translation.h"

void		lexical_err(t_parser *stor)
{
	ft_printf("Lexical error at row %d, symbol %d\n",
	stor->y_read, stor->x_read);
}

int			reader(t_parser *stor)
{
	int ret;

	ret = 0;
	if ((ret = read(stor->fd_s, stor->l, BUFFER_SIZE + 1)) <= 0)
	{
		if (ret == 0)
			return (-1);
		if (ret < 0)
			core_error(stor, READ_ERR, NULL, NULL);
	}
	printf("read result = %d\n", ret);
	return (ret);
}

void		skip_spaces(t_parser *stor)
{
	while (ft_iswspace(stor->l[stor->x_read]))
		stor->x_read++;
	if (stor->l[stor->x_read] == COMMENT_CHAR ||
		stor->l[stor->x_read] == ALT_COMMENT)
	{
		while (stor->l[stor->x_read - 1] != '\n')
			stor->x_read++;
	}

}


void		get_common(t_parser *stor, int step, int flag)
{
	int		len;
	int		pos;

	len = 0;
	pos = 0;
	if (stor->name || stor->x_read + step + 1 != '\"')
		core_error(stor, UNX_COMM_ERR, *lexical_err, NULL);
	stor->x_read += step;
	skip_spaces(stor);
	if (stor->l[stor->x_read++] == '\"')
	{
		pos = stor->x_read;
		while (stor->l[stor->x_read++] != '\"')
			len++;
	}
	flag == NAME_FLAG ? (stor->name = ft_strsub(stor->l, pos, len)) :
	(stor->comment = ft_strsub(stor->l, pos, len));
	while (stor->l[stor->x_read++] != '\n')
		if (!ft_iswspace(stor->l[stor->x_read]))
			core_error(stor, UNX_COMM_ERR, *lexical_err, NULL);

}

void		parse_commons(t_parser *stor)
{		
	if (!ft_strncmp(&(stor->l[stor->x_read]), NAME_CMD_STRING, NAME_STEP))
		get_common(stor, NAME_STEP, NAME_FLAG);
	else if (!ft_strncmp(&(stor->l[stor->x_read]), COMMENT_CMD_STRING, COMM_STEP))
		get_common(stor, COMM_STEP, COMMENT_FLAG);
	else
	{
		printf("aaaaaa\n");
		core_error(stor, UNX_COMM_ERR, *lexical_err, NULL);
	}
}


void		alt_parsing(t_parser *stor)
{

	printf("name len = %ld\t comm_len = %ld\n", NAME_STEP, COMM_STEP);
	while (reader(stor) > 0)
	{
		printf("cur pos = %c\n", stor->l[stor->x_read]);
		skip_spaces(stor);
		printf("cur pos after skip = %c\n", stor->l[stor->x_read]);
		if (stor->l[stor->x_read] == '.')
			parse_commons(stor);
	}
	printf("readed name = %s\n", stor->name);
	printf("readed comment = %s\n", stor->comment);
	
}