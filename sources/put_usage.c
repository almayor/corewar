/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:57:23 by user              #+#    #+#             */
/*   Updated: 2020/11/21 02:34:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"
#include "operations.h"

static char args_types[8][22] = {
	"",
	"T_REG",
	"T_DIR",
	"T_REG | T_DIR",
	"",
	"T_REG | T_IND",
	"T_DIR | T_IND",
	"T_REG | T_DIR | T_IND"};

void		put_op_usage(t_token *arg)
{
	int		ind = 0;
	int		num_args;
	
	num_args = op_tmpl[arg->name].args_num;
	ft_printf("token[%d][%d] - incorrect arg: %s\n",
	arg->point.row, arg->point.token, arg->content);
	ft_printf("\nUsage: %s ", op_tmpl[arg->name].name);
	while (ind < num_args)
	{
		ft_printf("arg[%d]", ind++ + 1);
		ft_printf("%s", ind == num_args ? "\n" : ", ");
	}
	ft_printf("possible args types:\n");
	ind = 0;
	while (ind < num_args)
	{
		ft_printf("\targ[%d]: %-25s\n", ind + 1, args_types[op_tmpl[arg->name].args_types[ind]]);
		ind++;
	}
}

void	put_label_err(t_token *arg)
{
	ft_printf("token[%d][%d] - undefined label \"%s\"\n",
	arg->point.row, arg->point.token, arg->content);
}


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