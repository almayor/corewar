/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:59:40 by user              #+#    #+#             */
/*   Updated: 2020/12/01 09:36:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

void		core_error(t_parser *stor, char *message, void (*f)(), t_token *arg)
{
	if (message)
		ft_putendl_fd(message, 2);
	if (f)
		f(arg, stor);
	if (stor && stor->fd_s)
		close(stor->fd_s);
	if (stor && stor->fd_cor)
		close(stor->fd_cor);
	if (stor)
		core_free(stor);
	exit(EXIT_FAILURE);
}

void		free_tokens(t_parser *stor)
{
	t_token		*token;
	t_token		*tmp;

	if (!stor->tokens)
		return ;
	token = stor->tokens;
	while (token)
	{
		tmp = token;
		if (token->content)
			free(token->content);
		token = token->next;
		free(tmp);
	}
}

void		free_parser(t_parser *stor)
{
	if (stor->name)
		free(stor->name);
	if (stor->comment)
		free(stor->comment);
	if (stor->file_name)
		free(stor->file_name);
	free(stor);
}

void		free_labels(t_parser *stor)
{
	t_label	*tmp;
	t_label	*label;

	label = stor->labels;
	while (label)
	{
		tmp = label;
		if (label->content)
			free(label->content);
		label = label->next;
		free(tmp);
	}
}

void		free_tokens_row(t_parser *stor)
{
	int i;

	i = 0;
	while (i < TOKENS_ROW)
	{
		if (stor->row[i] && stor->row[i]->content)
			free(stor->row[i]->content);
		if (stor->row[i])
			free(stor->row[i]);
		i++;
	}
}

void		core_free(t_parser *stor)
{
	if (!stor)
		return ;
	if (stor->tokens)
	{
		if (stor->tokens_head)
			stor->tokens = stor->tokens_head;
		free_tokens(stor);
	}
	if (stor->labels)
		free_labels(stor);
	if (stor->row)
		free_tokens_row(stor);
	free_parser(stor);
}
