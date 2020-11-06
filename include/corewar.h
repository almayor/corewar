/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:10 by user              #+#    #+#             */
/*   Updated: 2020/11/06 15:01:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include <stdint.h>
# include <stdlib.h>
# include "utils.h"
# include "corewar_logs.h"
# include "libft.h"
# include "ft_printf.h"

/*
** @struct s_proc
** A process running in the virtual machine
** @var s_proc::reg
** An array of registers
** @var s_proc::pc
** The program counter (position of the process within the memory)
** @var s_proc::carry
** The carry register
** @var s_proc::cycles_busy
** Number of cycles during which the process will remain busy (inactive)
** @var s_proc::cycles_since_live
** Number of cycles passed since the process has executed a `live` instruction
** @var s_proc::next
** A pointer to the next process in a singly linked list
** @note
** All processes are stored in a singly linked list
*/

typedef struct	s_proc
{
	int32_t			reg[REG_NUMBER];
	int32_t			pc;
	uint8_t			carry;
	uint8_t			ichamp;
	uint8_t			opcode;
	uint8_t			cycles_busy;
	int32_t			cycles_since_live;
	struct s_proc	*next;
}				t_proc;

/*
** @struct s_champ
** A champion and all its associated information
** @var s_champ::name
** The champion's name
** @var s_champ::ichamp
** The champion's number
** @var s_champ::comment
** The champion's comment
** @var s_champ::size
** The champion's size (in bytes)
** @var s_champ::curr_nlive
** Number of times that the champion has executed a `live` during the
** current `CYCLE_TO_DIE` epoch 
** @var s_champ::prev_nlive
** Number of times that the champion has executed a `live` during the
** previus `CYCLE_TO_DIE` epoch 
*/

typedef struct	s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	uint32_t		ichamp;
	char			comment[COMMENT_LENGTH + 1];
	size_t			size;
	uint64_t		curr_nlive;
	uint64_t		prev_nlive;
}				t_champ;

/*
** @enum e_log
** Degree of logging to perform during execution of the virtual machine
** @var e_log::STD_LOG
** Standard logging only
** @var e_log::EXTRA_LOG
** Extra logging (display commands executed by each process)
** @var e_log::VERBOSE_LOG
** Verbose logging (log every single action)
*/

typedef enum	e_log
{
	STD_LOG, EXTRA_LOG, VERBOSE_LOG
}				t_log;

/*
** @struct s_vm
** The virtual machine and all its associated information
** @var s_gm::mem
** The circular memory where the competition takes place
** @var s_gm::nchamps
** Number of champions in the virtual machine
** @var s_gm::champs
** An array of all champions
** @note The champion having number one is located at the `0th` position
** @var s_gm::nproc
** Number of processing running in the virtual machine
** @var s_gm::procs
** A singly linked list of processes
** @var s_gm::curr_nlive
** Number of times that the `live` command has been executed during the
** current `CYCLE_TO_DIE` epoch
** @var s_gm::last_live_champ
** The number of the last champion who last executed a `live` command
** @var s_gm::cycles_to_die
** Current number of cycles to die (cycles before passive processes are killed)
** @var s_gm::cycles since_change
** Number of cycles since the variable s_gm::cycles_to_die
** has been modified
** @var s_gm::cycles_since_die
** Number of cycles passed since passive processes were killed
** @var s_gm::dump_ncycles
** Number of cycles remaining before the memory will be dumped to the
** standard output and the program will exit
** @var s_gm::dump_flag
** Whether the `-dump` option was specified
** @var s_gm::log_flag
** How much logging to perform
*/

typedef struct	s_vm
{
	uint8_t			mem[MEM_SIZE];
	size_t			nchamps;
	t_champ			champs[MAX_PLAYERS];
	size_t			nprocs;
	t_proc			*procs;
	uint64_t		curr_nlive;
	uint32_t		last_live_champ;
	int64_t			cycles_to_die;
	int64_t 		cycles_since_change;
	int64_t			cycles_since_die;
	uint64_t		dump_ncycles;
	uint8_t			dump_flag;
	t_log			log_flag;
}				t_vm;

/*
** The virtual machine and all its associated information
*/

extern	t_vm	g_vm;

/*
** A pointer to the function that would execute an instruction
** given the process
*/

typedef void (*t_instruct)(t_proc *proc);

# endif
