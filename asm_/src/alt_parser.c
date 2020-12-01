/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:14:36 by user              #+#    #+#             */
/*   Updated: 2020/12/01 09:53:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alt_parser.h"
#include "translation.h"
#include "operations.h"

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

int			is_comment(char c)
{
	return (c == COMMENT_CHAR || c == ALT_COMMENT);
}

int			is_label(t_parser *stor)
{
	int		pos;
	int		len;

	len = 0;
	pos = stor->x_read;
	while (ft_strchr(LABEL_CHARS, stor->l[pos]))
		pos++;
	if (stor->l[pos++] == ':')
	{
		len = pos;
		while (stor->l[pos] != '\n')
		{
			if (is_op(stor, pos, 1))
				break ;
			if (!ft_iswspace(stor->l[pos]))
				return (0);
			pos++;
		}
		printf("it is a lable!\n");
		return (len);
	}
	return (0);
}

int			is_op(t_parser *stor, int st, int custom)
{
	int		ind;
	int		pos;

	// printf("in is op\n");
	// printf("after cur = (%c) | cur + 1 = (%c)\n", stor->l[stor->x_read], stor->l[stor->x_read + 1]);
	pos = st;
	if (!custom)
		pos = stor->x_read;
	ind = -1;
	while(++ind <= 15)
	{
		if (!ft_strncmp(&(stor->l[pos]),
			g_op_tmpl[ind].name, ft_strlen(g_op_tmpl[ind].name)))
		{
			printf("it is an op!\n");
			return (1);
		}
	}
	return (0);
}


t_token		*create_token(t_parser *stor, int len, int type)
{
	t_token		*token;

	if (!(token = ft_calloc(1, sizeof(t_token))))
		core_error(stor, ALLOC_ERR, NULL, NULL);
	token->point.row = stor->point.row;
	token->point.token = stor->point.token;
	token->content = ft_strsub(stor->l, stor->x_read, len);
	token->type = type;
	return (token);
}

void		collect_labels(t_parser *stor)
{
	int		i;

	i = 0;
	while((i = is_label(stor)))
	{
		stor->row[stor->point.token++] = create_token(stor, i, LABEL_TYPE);
		stor->x_read += i;
		skip_spaces(stor);
	}
}

void		parse_op_line(t_parser *stor)
{
	int			i;

	printf(" { 1 }\n");
	i = 0;
	stor->point.token = 0;
	ft_bzero(stor->row, sizeof(stor->row));
	if (is_label(stor))
		collect_labels(stor);
	while (i < 2)
	{
			printf("content = %s\n", stor->row[i - 1]->content ? 
			stor->row[i - 1]->content : NULL);
			i++;
	}
	
	// if (is_op(stor, 0, 0))
	// {
	// 	while (i < 2)
	// 		printf("content = %s\n", stor->row[i - 1]->content ? 
	// 		stor->row[i - 1]->content : NULL);
	// 		i++;
	// 		// stor->row[i++]->point.token = x;

	// }
}


void		alt_parsing(t_parser *stor)
{

	printf("name len = %ld\t comm_len = %ld\n", NAME_STEP, COMM_STEP);


	reader(stor);
	stor->x_read = 0;
	stor->y_read = 0;
	parse_commons(stor);

	while (stor->l[stor->x_read] != '\0')
	{
		printf(" { 0 }\n");

		skip_spaces(stor);
		if (is_label(stor) || is_op(stor, 0, 0))
			parse_op_line(stor);
		else
			core_error(stor, LEX_ERR, *lexical_err, NULL);
		
		// printf("after cur = (%c) | cur + 1 = (%c)\n", stor->l[stor->x_read], stor->l[stor->x_read + 1]);

		if (stor->name && stor->comment)
			break ;
	}
	printf("readed name = %s\n", stor->name);
	printf("readed comment = %s\n", stor->comment);
	
}