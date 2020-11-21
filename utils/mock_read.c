/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:50:34 by user              #+#    #+#             */
/*   Updated: 2020/11/21 18:51:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "translation.h"

// y=3 x=1 - loop arg
// y=0 x=3 - live arg

// void		test_label_value_(t_parser *stor)
// {
// 	t_token *dst;
// 	int		val;
// 	int		size;
// 	int		y = 3;	// put coords for label-arg you want to find
// 	int		x = 1;	// put coords for label-arg you want to find

// 	val = 0;
// 	size = 0;
// 	dst = stor->tokens_head;
// 	while (dst)
// 	{
// 		if (dst->point.row == y)
// 		{
// 			if (dst->type == OP_TYPE)
// 				size = dst->size;
// 			if (dst->point.token == x)
// 				break ;
// 		}
// 		dst = dst->next;
// 	}
// 	// printf("content = %s, y = %d x = %d\n", dst->content, dst->point.row, dst->point.token);
// 	val = find_label_value(stor, dst, size);
// 	printf("*******val = %d\n", val);
// }

// void	parse_arg_(t_token *token, char *arg, int y, int x)
// {
// 	int i = 0;

// 	token->point.row = y;
// 	token->point.token = x;

// 	if (arg[i] == 'r')
// 	{
// 		token->content = ft_strdup(arg);
// 		token->type = REG_ARG_TYPE;
// 	}
// 	else if (arg[i] == '%')
// 	{
// 		if (arg[i + 1] != ':')
// 		{
// 			token->content = ft_strdup(arg + 1);
// 			token->type = DIR_ARG_TYPE;
// 		}
// 		else
// 		{
// 			token->content = ft_strdup(arg + 2);
// 			token->type = DIR_LABL_ARG_TYPE;
// 		}
// 	}
// 	else if (ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == ':')
// 	{
// 		if (ft_isdigit(arg[i]) || arg[i] == '-')
// 		{
// 			token->content = ft_strdup(arg);
// 			token->type = IND_ARG_TYPE;
// 		}
// 		else
// 		{
// 			token->content = ft_strdup(arg + 1);
// 			token->type = IND_LABL_ARG_TYPE;
// 		}
// 	}
// }

// void	add_label_(t_parser *stor, char *label, int y, int x)
// {
// 	t_label *elem;

// 	if (!stor->labels)
// 	{
// 		stor->labels = ft_calloc(1, sizeof(t_label));
// 		stor->labels->content = ft_strdup(label);
// 		stor->labels->point.row = y;
// 		stor->labels->point.token = x;
// 	}
// 	else
// 	{
// 		elem = stor->labels;
// 		while (elem->next)
// 			elem = elem->next;
// 		elem->next = ft_calloc(1, sizeof(t_label));
// 		elem = elem->next;
// 		elem->content = ft_strdup(label);
// 		elem->point.row = y;
// 		elem->point.token = x;
// 	}
// }

// void	create_line_(t_parser *stor, t_token *token, int y, char *label, char *cmd, char *arg1, char *arg2, char *arg3)
// {
// 	int x = 0;

// 	if (token)
// 	{
// 		while (token->next)
// 			token = token->next;
// 		token->next = ft_calloc(1, sizeof(t_token));
// 		token = token->next;
// 	}
// 	else
// 	{
// 		token = ft_calloc(1, sizeof(t_token));
// 		stor->tokens = token;
// 	}
// 	if (label)
// 	{
// 		token->point.row = y;
// 		token->point.token = x++;
// 		token->content = ft_strdup(label);
// 		token->type = LABEL_TYPE;
// 		add_label_(stor, label, y, x);
// 		token->next = ft_calloc(1, sizeof(t_token));
// 		token = token->next;
// 	}
// 	if (cmd)
// 	{
// 		token->point.row = y;
// 		token->point.token = x++;
// 		token->content = ft_strdup(cmd);
// 		token->type = OP_TYPE;
// 	}
// 	if (arg1)
// 	{
// 		token->next = ft_calloc(1, sizeof(t_token));
// 		token = token->next;
// 		parse_arg_(token, arg1, y, x++);
// 	}
// 	if (arg2)
// 	{
// 		token->next = ft_calloc(1, sizeof(t_token));
// 		token = token->next;
// 		parse_arg_(token, arg2, y, x++);
// 	}
// 	if (arg3)
// 	{
// 		token->next = ft_calloc(1, sizeof(t_token));
// 		token = token->next;
// 		parse_arg_(token, arg3, y, x++);
// 	}
// }

// void	mock_read_(t_parser *stor)
// {
// 	stor->file_name = ft_strdup("test_translation.cor");
// 	stor->name = ft_strdup("Batman");
// 	stor->comment = ft_strdup("This city needs me");
// 	// stor->code_total_size = 10;
// 	// stor->tokens = ft_calloc(1, sizeof(t_token));
// 	// stor->tokens->content = ft_strdup("INIT TOKENS");
// 	// stor->tokens->type == UNKNOWN;
// 	create_line_(stor, stor->tokens, 0, "loop", "sti", "r1", "%:live", "%1");
// 	create_line_(stor, stor->tokens, 1, "live", "live", "%0", NULL, NULL);
// 	create_line_(stor, stor->tokens, 2, NULL, "zjmp", "%:typing", NULL, NULL);
// 	create_line_(stor, stor->tokens, 3, NULL, "sti", "r1", "%:copie", "%2");
// 	create_line_(stor, stor->tokens, 4, NULL, "ld", "%0", "r2", NULL);
// 	create_line_(stor, stor->tokens, 5, NULL, "sub", "r2", "r4", "r2");
// 	create_line_(stor, stor->tokens, 6, NULL, "zjmp", "%:loop", NULL, NULL);
// 	create_line_(stor, stor->tokens, 7, NULL, "st", "r3", "r5", NULL);
// 	create_line_(stor, stor->tokens, 8, "typing", "aff", "r2", NULL, NULL);
// 	create_line_(stor, stor->tokens, 9, "copie", "ld", "%1", "r1", NULL);
// 	create_line_(stor, stor->tokens, 10, NULL, "xor", "r10", "r10", "r10");
// 	stor->tokens_head = stor->tokens;
// }
