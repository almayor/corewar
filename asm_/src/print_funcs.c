/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:00:23 by user              #+#    #+#             */
/*   Updated: 2020/11/24 20:33:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

static char g_types[11][20] = {
	"NEW_LINE_TYPE",
	"REG_ARG_TYPE",
	"DIR_ARG_TYPE",
	"DIR_LABL_ARG_TYPE",
	"IND_ARG_TYPE",
	"IND_LABL_ARG_TYPE",
	"LABEL_TYPE",
	"DELIM_TYPE",
	"OP_TYPE",
	"END_FILE",
	"UNKNOWN"};

void	collect_row_data(t_token *row[10], t_parser *stor, t_token *token)
{
	int		i;

	i = 0;
	while (i < stor->row_len)
	{
		row[i] = token;
		token = token->next;
		i++;
	}
}

int		get_row_len(t_parser *stor, t_token *token)
{
	int		y;
	int		len;

	y = token->point.row;
	len = 0;
	while (token->point.row == y && token->type != END_FILE)
	{
		len++;
		token = token->next;
	}
	stor->row_len = len;
	return (len);
}

void	print_tokens_by_line(t_parser *stor, t_token **token)
{
	t_token *row[get_row_len(stor, *token)];
	int		i;

	collect_row_data(row, stor, *token);
	i = -1;
	ft_printf("%-10s", "TOKEN");
	while (++i < stor->row_len && row[i])
		ft_printf("%-20s", ft_itoa(row[i]->point.token));
	ft_printf("\n");
	i = -1;
	ft_printf("%-10s", "content");
	while (++i < stor->row_len && row[i])
		ft_printf("%-20s", row[i]->content);
	ft_printf("\n");
	i = -1;
	ft_printf("%-10s", "type");
	while (++i < stor->row_len && row[i])
		ft_printf("%-20s", g_types[row[i]->type]);
	ft_printf("\n\n");
	(*token) = get_token(*token, stor->row_len);
}

void	tokens_print(t_parser *stor)
{
	t_token *token;

	token = stor->tokens;
	while (token && token->type != END_FILE)
	{
		ft_printf("********************************************");
		ft_printf(" TOKENS ROW %d ", token->point.row);
		ft_printf("********************************************\n\n");
		print_tokens_by_line(stor, &token);
	}
}

void	labels_print(t_parser *stor)
{
	t_label	*label;
	int		i;

	i = 0;
	label = stor->labels;
	ft_printf("\n************ LABELS ************\n");
	while (label)
	{
		ft_printf("\n*** LABEL %d ***\n", i++);
		ft_printf("%-10s %s\n", "content", label->content);
		ft_printf("%-10s row %d  token %d\n", "coords",
		label->point.row, label->point.token);
		label = label->next;
	}
	ft_printf("\n");
}
