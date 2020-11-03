#ifndef COREWAR_H

# define COREWAR_H

# include "stdint.h"
# include "utils.h"
# include <limits.h>

typedef struct	s_arg
{
	t_arg_type		type;
	int32_t			val;
}				t_arg;

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

typedef struct	s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	uint32_t		ichamp;
	char			comment[COMMENT_LENGTH];
	size_t			size;
	uint64_t		curr_nlive;
	uint64_t		prev_nlive;
}				t_champ;

typedef struct	s_vm
{
	uint8_t			mem[MEM_SIZE];
	t_champ			champs[MAX_PLAYERS + 1];
	size_t			nprocs;
	t_proc			*procs;
	uint64_t		curr_nlive;
	uint32_t		last_live_champ;
	int64_t			cycles_to_die;
	int64_t 		cycles_since_change;
	int64_t			cycles_since_die;
}				t_vm;

extern	t_vm	g_vm;

# define	PLAYER_ALIVE	"a process shows that player %u (%s) is alive\n"
# define	PLAYER_WON		"player %u (%s) won\n"

# define	FILE_NOT_EXE	"%s is not a corewar executable\n"
# define	PROG_NUM_USED	"player number %u already in use\n"
# define	FILE_NOT_ACCESS	"file %s not accessible\n"
# define	MALLOC_ERROR	"malloc error\n"
# define	CHAMP_TOO_LARGE	"champion %u (%s) exceeds maximum size\n"
# define	INVALID_MACRO	"macro %s values other than %i are not supported\n"

typedef void (*t_instruct)(t_proc *proc);

# endif
