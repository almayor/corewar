/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:26:25 by user              #+#    #+#             */
/*   Updated: 2020/11/18 20:45:58 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

t_label		*get_label(t_parser *stor, char *name)
{
	t_label		*tmp;

	tmp = stor->labels;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->content))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_token		*get_start_token(t_parser *stor, t_label *label)
{
	t_token		*tmp;

	tmp = stor->tokens_head;
	while (tmp)
	{
		if (tmp->point.row == label->point.row &&
		tmp->point.token == label->point.token)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			calc_value(t_token *start, t_token *dst, int arg_line_size)
{
	int		val;

	val = 0;
	if (start->point.row < dst->point.row)
	{
		while (start && start->point.row != dst->point.row)
		{
			if (start->type == OP_TYPE)
				val += start->size;
			start = start->next;
		}
	}
	else
	{
		val += arg_line_size;
		while (dst && start->point.row != dst->point.row)
		{
			if (dst->type == OP_TYPE)
				val += dst->size;
			dst = dst->next;
		}
	}
	return (val);
}

int			find_label_value(t_parser *stor, t_token *dst, int dst_size)
{
	t_token		*start;
	t_label		*label;
	int			val;
	int			sign;

	sign = 1;
	if (!(label = get_label(stor, dst->content)))
		core_error(stor, LABEL_ERR);
	if (!(start = get_start_token(stor, label)))
		core_error(stor, LABEL_ERR);
	sign = start->point.row < dst->point.row ? -1 : 1;
	val = calc_value(start, dst, dst_size);
	return (val * sign);
}
