/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:37:21 by user              #+#    #+#             */
/*   Updated: 2020/11/16 00:48:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OPERATIONS_H_
# define _OPERATIONS_H_

# include <stdint.h>

typedef enum
{
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF,
}					t_ops_names;

typedef struct		s_ops
{
	uint8_t			op_code;
	uint8_t			args_num;
	int				is_arg_code;
	uint8_t			args_types[3];
	uint8_t			dir_size;
}					t_ops;


static t_ops	op_tmpl[16] = {
	{
		.op_code = 0x01,
		.args_num = 1,
		.is_arg_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 4,
	},
	{
		.op_code = 0x02,
		.args_num = 2,
		.is_arg_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
	},
	{
		.op_code = 0x03,
		.args_num = 2,
		.is_arg_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.dir_size = 4,
	},
	{
		.op_code = 0x04,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
	},
	{
		.op_code = 0x05,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
	},
	{
		.op_code = 0x06,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
	},
	{
		.op_code = 0x07,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
	},
	{
		.op_code = 0x08,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
	},
	{
		.op_code = 0x09,
		.args_num = 1,
		.is_arg_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
	},
	{
		.op_code = 0x0a,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
	},
	{
		.op_code = 0x0b,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.dir_size = 2,
	},
	{
		.op_code = 0x0c,
		.args_num = 1,
		.is_arg_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
	},
	{
		.op_code = 0x0d,
		.args_num = 2,
		.is_arg_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
	},
	{
		.op_code = 0x0e,
		.args_num = 3,
		.is_arg_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
	},
	{
		.op_code = 0x0f,
		.args_num = 1,
		.is_arg_code = 0,
		.args_types = {T_REG, 0, 0},
		.dir_size = 2,
	},
	{
		.op_code = 0x10,
		.args_num = 1,
		.is_arg_code = 1,
		.args_types = {T_REG, 0, 0},
		.dir_size = 4,
	},
};

#endif