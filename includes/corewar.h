/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:19:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/10 21:01:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include "corewar_logs.h"

typedef struct s_args	t_args;
typedef struct s_proc	t_proc;
typedef struct s_champ	t_champ;
typedef struct s_vm		t_vm;

/*
** A pointer to the function that would execute an instruction
** given the process
*/

typedef int		(*t_instruct)(t_proc *proc);

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

struct			s_proc
{
	int32_t		reg[REG_NUMBER];
	int32_t		pc;
	uint8_t		carry;
	uint8_t		ichamp;
	uint8_t		opcode;
	uint32_t	cycles_busy;
	int32_t		cycles_since_live;
	uint64_t	iproc;
	int32_t		args[3];
	t_proc		*next;
};

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

struct			s_champ
{
	char		name[PROG_NAME_LENGTH + 1];
	uint32_t	ichamp;
	char		comment[COMMENT_LENGTH];
	uint64_t	size;
	uint64_t	curr_nlive;
	uint64_t	prev_nlive;
};

/*
**	Структура t_args используется в процессе парсинга и валидации, куда
**	записываются по очереди аргументы командной строки (по назначению -
**	игроки).
**	Структура хранит, соответственно, имя игрока, номер игрока и дескриптор
**	файла. Как только все игроки пройдут проверку, они будут перенесены в
**	g_vm.champs, каждый на свой индекс.
**	Пример: Игрок с номером 3, пойдет на индекс 2.
**
**	Данная структура была добавлена в g_vm.
*/

struct			s_args
{
	const char	*fname;
	int			num;
};


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
** @var s_gm::cycles_since_die
** Number of cycles passed since passive processes were killed
 * ** @var s_gm::checks_since_change
** Number of checks since the variable s_gm::cycles_to_die
** has been modified
** @var s_gm::dump_ncycles
** Number of cycles remaining before the memory will be dumped to the
** standard output and the program will exit
** @var s_gm::dump_flag
** Whether the `-dump` option was specified
** @var s_gm::log_flag
** How much logging to perform
*/

struct			s_vm
{
	uint8_t		mem[MEM_SIZE];
	int			nchamps;
	t_champ		champs[MAX_PLAYERS];
	size_t		nprocs;
	t_proc		*procs;
	uint64_t	curr_nlive;
	uint32_t	last_live_champ;
	uint64_t	icycle;
	int64_t		cycles_to_die;
	int64_t		cycles_since_die;
	int64_t		checks_since_change;
	uint64_t	dump_ncycles;
	int			dump_flag;
	uint8_t		log;
	t_args		args[MAX_PLAYERS];
};

/*
** The virtual machine and all its associated information
*/

extern	t_vm	g_vm;

/*
** Instructions
*/

int			add_instruct(t_proc *proc);
int			aff_instruct(t_proc *proc);
int			and_instruct(t_proc *proc);
int			fork_instruct(t_proc *proc);
int			ld_instruct(t_proc *proc);
int			ldi_instruct(t_proc *proc);
int			lfork_instruct(t_proc *proc);
int			live_instruct(t_proc *proc);
int			lld_instruct(t_proc *proc);
int			lldi_instruct(t_proc *proc);
int			or_instruct(t_proc *proc);
int			st_instruct(t_proc *proc);
int			sti_instruct(t_proc *proc);
int			sub_instruct(t_proc *proc);
int			xor_instruct(t_proc *proc);
int			zjmp_instruct(t_proc *proc);

void	*ft_xcalloc(size_t count, size_t size);
void	*ft_xmalloc(size_t size);

int			check_instruction(const t_proc *proc);
uint32_t	get_instruction_length(const t_proc *proc);

int			get_arg_length(const t_proc *proc, int n);
t_arg_type	get_arg_type(const t_proc *proc, int n);
int			put_argument(t_proc *proc, int n, int32_t val);
int			load_argument(const t_proc *proc, int n, int32_t *val);

void	create_proc(uint32_t ichamp, int32_t pos);
void	fork_proc(int32_t pos, const t_proc *parent);
void	kill_proc(t_proc *proc);
void	print_proc(const t_proc *proc);

int32_t	mem_read(int32_t pos, int nbytes);
void	mem_write(int32_t pos, int32_t val, int nbytes);

void	cleanup(void);
void	terminate(const char *format, ...);


void		dispatch(t_proc *proc);
void		cycle(void);
void		run(void);
void		dump(void);
void		load(int argc, char **argv);

/*
** >----------------< Parsing arguments >----------------<
*/

void			parse_args(int argc, char **argv);
void			validate_dump(int argc, char **argv, int *i);
void			init_numbers(void);

#endif
