/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:57:23 by user              #+#    #+#             */
/*   Updated: 2020/11/21 18:31:13 by user             ###   ########.fr       */
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
	ft_printf("incorrect token[%d][%d]: %s\n",
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

void	put_asm_usage(void)
{
	ft_printf("Usage: ./asm <champion>.s [OPTION] [OPTION] [OPTION]\n");
	ft_printf("Translate code from assemble (.s) to byte-core (.cor)\n");
	ft_printf("\nMandatory options.\n");
	ft_printf("  -t, --tokens\t print tokens information\n");
	ft_printf("  -l, --labels\t print labels information\n");
	ft_printf("  -h, --help\t print usage\n");
	ft_printf("\nDescription.\n");
	ft_printf("Programme translates assembler code from file .s to byte-code.\n");
	ft_printf("Result is stored to the .cor file in the same directory as the .s file\n");

}

void		put_bonus(t_parser *stor, t_flags flags)
{
	flags.labels = flags.help ? 0 : flags.labels;
	flags.tokens = flags.help ? 0 : flags.tokens;
	if (flags.tokens)
		print_tokens_(stor);
	if (flags.labels)
		print_labels_(stor);
	if (flags.help)
		put_asm_usage();
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