/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:11:22 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 14:11:25 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		print_labels(t_label *labels)
{
	t_label *label;

	label = labels;
	while (label)
	{
		ft_printf("{red}->%s, %d, %d{eoc}\n", label->content,
		label->point.row, label->point.token);
		label = label->next;
	}
}

void		print_tokens(t_token *tokens)
{
	int		y;
	t_token	*token;

	token = tokens;
	y = token->point.row;
	while (token)
	{
		if (y != token->point.row)
			ft_printf("\n");
		if (token->type == LABEL_TYPE || token->type == DIR_LABL_ARG_TYPE
		|| token->type == IND_LABL_ARG_TYPE)
			ft_printf("{red}->%s, %d, %d, %d {eoc}\n", token->content,
			token->point.row, token->point.token, token->type);
		else
			ft_printf("{green}->%s, %d, %d, %d {eoc}\n", token->content,
			token->point.row, token->point.token, token->type);
		y = token->point.row;
		token = token->next;
	}
}
