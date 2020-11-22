/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:27:09 by user              #+#    #+#             */
/*   Updated: 2020/11/22 14:30:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H

# define OP_H

# include <stdint.h>
# include <stddef.h>

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

/*
** A `char` specifying the type of an instruction
*/

typedef char	t_arg_type;

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				4096
# define IDX_MOD				512
# define CHAMP_MAX_SIZE			682

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

/*
** @struct s_op
** A structure specifying how a valid instruction will be given
** @var s_op::name
** The operation's name
** @var s_op::nargs
** Number of arguments that an instruction takes
** @var s_op::type_mask
** Types of allowed arguments (an array of 3 bit masks)
** @var s_op::opcode
** The instruction's opcode
** @var s_op::duration
** The number of cycles it takes to execute an instruction
** @var s_op::doc
** An instruction's doc-string
** @var s_op::modify_carry
** Whether an instruction can modify the `carry` register
** @var s_op::direct_size
** Size of a `direct` argument (2 bytes if `direct_size` is `1`, 4 bytes if 0)
** @var s_op::addr_restrict
** Whether `indirect` arguments are restricted by `% IDX_MOD`
** @var s_op::type_octet
** Whether the opcode is followed by a type octet
*/

typedef struct		s_op
{
	const char			*name;
	uint8_t				nargs;
	const uint8_t		type_mask[3];
	uint8_t				opcode;
	uint32_t			duration;
	const char			*doc;
	uint8_t				modify_carry;
	uint8_t				direct_size;
	uint8_t				addr_restrict;
	uint8_t				type_octet;
}					t_op;

# define NUM_INSTRUCT	16

/*
** An array specifying how each instruction will be given
*/

extern const t_op		g_op_tab[NUM_INSTRUCT + 1];

#endif
