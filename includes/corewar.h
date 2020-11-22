/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:19:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/22 14:30:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <assert.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include "corewar_logs.h"

typedef struct s_parse	t_parse;
typedef struct s_proc	t_proc;
typedef struct s_champ	t_champ;
typedef struct s_vm		t_vm;
typedef union u_int		t_int;

/*
** A pointer to the function that would execute an instruction
** given the process
*/

typedef int				(*t_instruct)(t_proc *proc);

/*
** A union used for type punning
*/

union					u_int
{
	int8_t		int8;
	int16_t		int16;
	int32_t		int32;
	uint8_t		uint8;
	uint16_t	uint16;
	uint32_t	uint32;
};

struct					s_proc
{
	int32_t		reg[REG_NUMBER];
	int32_t		pc;
	uint8_t		carry;
	uint8_t		ichamp;
	uint8_t		opcode;
	uint8_t		type_octet;
	uint32_t	cycles_busy;
	int32_t		cycles_since_live;
	uint64_t	iproc;
	int32_t		args[3];
	t_proc		*next;
};

struct					s_champ
{
	char		name[PROG_NAME_LENGTH + 1];
	uint32_t	ichamp;
	char		comment[COMMENT_LENGTH];
	uint64_t	size;
	uint64_t	curr_nlive;
	uint64_t	prev_nlive;
	uint64_t	last_live;
};

struct					s_parse
{
	const char	*fname;
	int			num;
};

struct					s_vm
{
	uint8_t		mem[MEM_SIZE];
	int			nchamps;
	t_champ		champs[MAX_PLAYERS];
	size_t		nprocs;
	t_proc		*procs;
	uint64_t	curr_nlive;
	uint64_t	prev_nlive;
	uint32_t	last_live_champ;
	uint64_t	icycle;
	int64_t		cycles_to_die;
	int64_t		cycles_since_die;
	int64_t		checks_since_change;
	uint64_t	dump_ncycles;
	int			dump_flag;
	uint8_t		aff_flag;
	uint8_t		log;
	t_parse		temp[MAX_PLAYERS];
};

/*
** The virtual machine and all its associated information
*/

extern	t_vm			g_vm;

int						add_instruct(t_proc *proc);
int						aff_instruct(t_proc *proc);
int						and_instruct(t_proc *proc);
int						fork_instruct(t_proc *proc);
int						ld_instruct(t_proc *proc);
int						ldi_instruct(t_proc *proc);
int						lfork_instruct(t_proc *proc);
int						live_instruct(t_proc *proc);
int						lld_instruct(t_proc *proc);
int						lldi_instruct(t_proc *proc);
int						or_instruct(t_proc *proc);
int						st_instruct(t_proc *proc);
int						sti_instruct(t_proc *proc);
int						sub_instruct(t_proc *proc);
int						xor_instruct(t_proc *proc);
int						zjmp_instruct(t_proc *proc);

void					*ft_xcalloc(size_t count, size_t size);
void					*ft_xmalloc(size_t size);

uint32_t				get_instruction_length(const t_proc *proc);
int						check_instruction(const t_proc *proc);
void					read_instruction(t_proc *proc);

int						get_arg_length(const t_proc *proc, int n);
t_arg_type				get_arg_type(const t_proc *proc, int n);
int						put_argument(t_proc *proc, int n, int32_t val);
int						load_argument(const t_proc *proc, int n, int32_t *val);

void					create_proc(uint32_t ichamp, int32_t pos);
void					fork_proc(int32_t pos, const t_proc *parent);
void					kill_proc(t_proc *proc);
void					print_proc(const t_proc *proc);

int32_t					mem_read(int64_t pos, int nbytes);
void					mem_write(int64_t pos, int32_t val, int nbytes);

void					cleanup(void);
void					terminate(const char *format, ...);

void					cycle(void);
void					run(void);
void					dump(void);
void					load(void);

void					parse_args(int argc, char **argv);
void					validate_dump(int argc, char **argv, int *i);
void					init_numbers(void);
int						is_number(const char *string);

#endif
