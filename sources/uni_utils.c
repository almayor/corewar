/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:20 by user              #+#    #+#             */
/*   Updated: 2020/11/16 13:26:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"


void		core_error(t_parser *stor, char *message)
{
	if (stor)
		core_free(stor);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void		free_tokens(t_parser *stor)
{
	t_token 	*token;
	t_token		*tmp;
	
	if (!stor->tokens)
		return ;
	token = stor->tokens;
	while (token)
	{
		tmp = token;
		if (token->content)
			free(token->content);
		if (token->op_code)
			free(token->op_code);
		if (token->arg_code)
			free(token->arg_code);
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

void		core_free(t_parser *stor)
{
	if (!stor)
		return ;
	if (stor->tokens)
		free_tokens(stor);
	if (stor->labels)
		free_labels(stor);
	
	// function to clean all data stored in frame
	
	

	free_parser(stor);
}
