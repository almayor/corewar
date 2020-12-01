/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_commons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:42:00 by user              #+#    #+#             */
/*   Updated: 2020/12/01 09:59:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alt_parser.h"
#include "translation.h"

void		check_common(t_parser *stor, int len, int max)
{
	if (len > max)
		core_error(stor, LEN_CMD_ERR, *command_err, NULL);
	while (stor->l[stor->x_read] != '\n')
	{
		if (!ft_iswspace(stor->l[stor->x_read]))
			core_error(stor, UNX_COMM_ERR, *command_err, NULL);
		stor->x_read++;
	}
} 

void		get_common(t_parser *stor, int step, int flag, int max)
{
	int		len;
	int		pos;
	
	// printf("{ FLAG = %s }\n", flag ? "NAME" : "COMM");
	len = 0;
	pos = 0;
	stor->x_read += step;
	// printf("+ step = %c\n", stor->l[stor->x_read]);
	skip_spaces(stor);

	if (stor->l[stor->x_read] != '\"')
		core_error(stor, UNX_COMM_ERR, *command_err, NULL);
	if (stor->l[stor->x_read++] == '\"')
	{
		pos = stor->x_read;
		while (stor->l[stor->x_read++] != '\"')
			len++;
	}
	flag == NAME_FLAG ? (stor->name = ft_strsub(stor->l, pos, len)) :
	(stor->comment = ft_strsub(stor->l, pos, len));
	check_common(stor, len, max);
	stor->x_read++;
}

void		parse_commons(t_parser *stor)
{
	printf(" { 2.0 }\n");

	while (stor->l[stor->x_read] && (ft_iswspace(stor->l[stor->x_read]) ||
	is_comment(stor->l[stor->x_read]) || stor->l[stor->x_read] == '.'))
	{
		skip_spaces(stor);
		if (stor->l[stor->x_read] == '.')
		{
			printf("we are here!\n");
			if (!ft_strncmp(&(stor->l[stor->x_read]),\
				NAME_CMD_STRING, NAME_STEP) && !stor->name)
				get_common(stor, NAME_STEP, NAME_FLAG, PROG_NAME_LENGTH);
			else if (!ft_strncmp(&(stor->l[stor->x_read]),\
				COMMENT_CMD_STRING, COMM_STEP) && !stor->comment)
				get_common(stor, COMM_STEP, COMMENT_FLAG, COMMENT_LENGTH);
			else
				core_error(stor, UNX_COMM_ERR, *command_err, NULL);
		}
	}
	printf(" { 2 }\n");
}
