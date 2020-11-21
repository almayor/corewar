/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:57:23 by user              #+#    #+#             */
/*   Updated: 2020/11/21 21:08:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"
#include "operations.h"

static char	g_args_types[8][22] = {
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
	int		ind;
	int		num_args;

	ind = 0;
	num_args = g_op_tmpl[arg->name].args_num;
	ft_printf("incorrect token[%d][%d]: %s\n",
	arg->point.row, arg->point.token, arg->content);
	ft_printf("\nUsage: %s ", g_op_tmpl[arg->name].name);
	while (ind < num_args)
	{
		ft_printf("arg[%d]", ind++ + 1);
		ft_printf("%s", ind == num_args ? "\n" : ", ");
	}
	ft_printf("possible args types:\n");
	ind = 0;
	while (ind < num_args)
	{
		ft_printf("\targ[%d]: %-25s\n", ind + 1,
		g_args_types[g_op_tmpl[arg->name].args_types[ind]]);
		ind++;
	}
}

void		put_label_err(t_token *arg)
{
	ft_printf("token[%d][%d] - undefined label \"%s\"\n",
	arg->point.row, arg->point.token, arg->content);
}

void		put_asm_usage(void)
{
	ft_printf("Usage: ./asm <champion>.s [OPTION] [OPTION] [OPTION]\n");
	ft_printf("Translate code from assemble (.s) to byte-code (.cor)\n");
	ft_printf("\nMandatory options.\n");
	ft_printf("  -t, --tokens\t print tokens information\n");
	ft_printf("  -l, --labels\t print labels information\n");
	ft_printf("  -h, --help\t print usage (cancel other options)\n");
	ft_printf("\nDiscription.\n");
	ft_printf("Programm translate assemble code from file .s to byte-code.\n");
	ft_printf("Result storing in file .cor");
	ft_printf("in the same directory that .s file\n");
}

void		put_bonus(t_parser *stor, t_flags flags)
{
	flags.labels = flags.help ? 0 : flags.labels;
	flags.tokens = flags.help ? 0 : flags.tokens;
	if (flags.tokens)
		tokens_print(stor);
	if (flags.labels)
		labels_print(stor);
	if (flags.help)
		put_asm_usage();
}
