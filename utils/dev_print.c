/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:43:33 by user              #+#    #+#             */
/*   Updated: 2020/11/21 20:46:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "translation.h"

// void	print_tokens_by_line_(t_token **token)
// {
// 	int 		y = (*token)->point.row;

// 	while ((*token) && (*token)->point.row == y)
// 	{
		
// 		printf("*** TOKEN [%d][%d] ***\n", (*token)->point.row, (*token)->point.token);
// 		printf("type = %s\n", types[(*token)->type]);
// 		printf("coords: row = %d token = %d\n", (*token)->point.row, (*token)->point.token);
// 		printf("content = %s\n", (*token)->content);
// 		printf("op_code = %#x\n", (*token)->op_code);
// 		printf("size = %d\n", (*token)->size);
// 		printf("num_args = %d\n", (*token)->num_args);
// 		printf("dir_size = %d\n", (*token)->dir_size);
// 		printf("is arg_code = %s\n", (*token)->is_arg_code ? "YES" : "NO");
// 		printf("arg_code = %#x\n", (*token)->arg_code);
// 		printf("\n");
// 		(*token) = (*token)->next;
// 	}
// }

// void	simple_tokens_print_(t_parser *stor)
// {
// 	t_token *t = stor->tokens;
// 	while (t)
// 	{
// 		printf("content = %s, y = %d x = %d\n", t->content, t->point.row, t->point.token);
// 		t = t->next;
// 	}
// }

// void	simple_parser_print_(t_parser *stor)
// {
// 	if (!stor)
// 		return ;
// 	printf("total_size = %d  hex(%#x)\n", stor->code_total_size, stor->code_total_size);
// 	printf("champ name = %s\n", stor->name);
// 	printf("champ comment = %s\n", stor->comment);
// 	printf("filename = %s\n", stor->file_name);
// 	printf("fd_cor = %d  fd_s = %d\n", stor->fd_cor, stor->fd_s);
// 	printf("is tokens = %s\n", stor->tokens ? "YES" : "NO");
// 	printf("is tokens_head = %s\n", stor->tokens_head ? "YES" : "NO");
// 	printf("is labels = %s\n", stor->labels ? "YES" : "NO");
// }




// tmp statics - for possible usage printing

// static char types[11][20] = {"NEW_LINE_TYPE", "REG_ARG_TYPE", "DIR_ARG_TYPE",
// 	"DIR_LABL_ARG_TYPE",
// 	"IND_ARG_TYPE", 
// 	"IND_LABL_ARG_TYPE",
// 	"LABEL_TYPE", 
// 	"DELIM_TYPE", 
// 	"OP_TYPE", 
// 	"END_FILE",
// 	"UNKNOWN"};

// static char names[16][5] = {
// 	"LIVE",
// 	"LD",
// 	"ST",
// 	"ADD",
// 	"SUB",
// 	"AND",
// 	"OR",
// 	"XOR",
// 	"ZJMP",
// 	"LDI",
// 	"STI",
// 	"FORK",
// 	"LLD",
// 	"LLDI",
// 	"LFORK",
// 	"AFF",
// };