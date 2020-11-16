/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 03:49:59 by user              #+#    #+#             */
/*   Updated: 2020/11/16 05:19:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

static char types[10][20] = {"NEW_LINE_TYPE", "LABEL_TYPE", "DELIM_TYPE", "OP_TYPE", "REG_ARG_TYPE", "DIR_ARG_TYPE",
	"DIR_LABL_ARG_TYPE", "IND_ARG_TYPE", "IND_LABL_ARG_TYPE", "END_FILE"};

void	get_arg(t_token *token, char *arg, int y, int x)
{
	int i = 0;

	token->point.row = y;
	token->point.token = x;

	if (arg[i] == 'r')
	{
		token->content = ft_strdup(arg);
		token->type = REG_ARG_TYPE;
	}
	else if (arg[i] == '%')
	{
		if (arg[i + 1] != ':')
		{
			token->content = ft_strdup(arg + 1);
			token->type = DIR_ARG_TYPE;
		}
		else
		{
			token->content = ft_strdup(arg + 2);
			token->type = DIR_LABL_ARG_TYPE;
		}
	}
	else if (ft_isdigit(arg[i]) || ft_isalpha(arg[i]))
	{
		token->content = ft_strdup(arg);
		if (ft_isdigit(arg[i]))
			token->type = IND_ARG_TYPE;
		else if (ft_isalpha(arg[i]))
			token->type = IND_LABL_ARG_TYPE;
	}
}

void	create_line(t_token *token, int y, char *label, char *cmd, char *arg1, char *arg2, char *arg3)
{
	int x = 0;

	if (token)
	{
		while (token->next)
			token = token->next;
		token->next = ft_calloc(1, sizeof(t_token));
		token = token->next;
	}
	if (label)
	{
		token->point.row = y;
		token->point.token = x++;
		token->content = ft_strdup(label);
		token->type = LABEL_TYPE;
		token->next = ft_calloc(1, sizeof(t_token));
		token = token->next;
	}
	token->point.row = y;
	token->point.token = x == 0 ? x : x++;
	token->content = ft_strdup(cmd);
	token->type = OP_TYPE;

	if (arg1)
	{
		token->next = ft_calloc(1, sizeof(t_token));
		token = token->next;
		get_arg(token, arg1, y, x++);
	}

	if (arg2)
	{
		token->next = ft_calloc(1, sizeof(t_token));
		token = token->next;
		get_arg(token, arg2, y, x++);
	}
	if (arg3)
	{
		token->next = ft_calloc(1, sizeof(t_token));
		token = token->next;
		get_arg(token, arg3, y, x++);
	}

}

void	mock_read(t_parser *stor)
{
	stor->file_name = ft_strdup("test_translation.cor");
	stor->name = ft_strdup("Batman");
	stor->comment = ft_strdup("This city needs me");
	stor->code_total_size = 10;

	stor->tokens = ft_calloc(1, sizeof(t_token));
	stor->tokens->content = ft_strdup("INIT TIKENS");
	
	create_line(stor->tokens, 0, "loop", "sti", "r1", "%:live", "%1");
	create_line(stor->tokens, 1, "live", "live", "%0", NULL, NULL);
	create_line(stor->tokens, 2, NULL, "ld", "%0", "r2", NULL);
	create_line(stor->tokens, 2, NULL, "zjmp", "%:loop", NULL, NULL);
}

void	print_tokens_by_line(t_token **token)
{
	int y = (*token)->point.row;

	while ((*token) && (*token)->point.row == y)
	{
		printf("*** TOKEN %d ***\n", (*token)->point.token);
		printf("type = %s\n", types[(*token)->type]);
		printf("content = %s\n", (*token)->content);
		printf("coords: row = %d token = %d\n\n", (*token)->point.row, (*token)->point.token);
		(*token) = (*token)->next;
	}
}

void	print_tokens(t_parser *stor)
{
	t_token *token = stor->tokens->next;

	while (token)
	{
		printf("\n************* TOKENS ROW %d *************\n\n", token->point.row);
		print_tokens_by_line(&token);
	}
}
