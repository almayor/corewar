
uint8_t	T_REG = 1 << 0; // argument can be a register
uint8_t T_DIR = 1 << 1; // argument can be a direct value
uint8_t	T_IND = 1 << 2; // argument can be a memory index

typedef struct	s_op
{
	const char		*name;				// operation name
	const uint8_t	args[3];			// types of allowed arguments (a bit-mask)
	uint8_t			opcode;				// the op-code
	uint8_t			duration;			// operation duration
	const char		*doc;				// doc string
	uint8_t			modify_carry;		// whether operation modifies carry (a boolean)
	uint8_t			dir_size;			// whether T_DIR arguments are 2 bytes (1) or 4 bytes (0)
}				t_op;

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG, 0}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0, 0}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0, 0, 0}, 0, 0, 0, 0, 0}
};

typedef struct	s_proc
{
	uint8_t			*reg; 				// registries as a continuous block of size (REG_NUMBER * REG_SIZE) bytes
	uint8_t			carry;				// carry
	uint64_t		pc; 				// program counter
	uint64_t		cycles_since_live;	// number of cycles passed since this process last executed a `live`
}				t_proc;

typedef struct	s_champ
{
	const char		*name;				// champion's name
	uint64_t		nprocs;				// number of processes that belong to a champion (bookkeeping)
	uint8_t			number;				// champion's number (the champion is dead if this number becomes zero)
}				t_champ;

typedef struct	s_vm
{
	t_list			*procs;				// a singly linked list of processes
	uint64_t		cycles_to_die;		// current number of cycles to die
	uint64_t		cycles_since_die;	// number of cycles since last die
	uint8_t			*mem;				// circular memory
	t_champ			*champs;			// a null-terminated array of champions		
}				t_vm;

// a global structure representing the virtual machine

extern t_vm	*g_vm;

// a singly linked list of processes

typedef struct	s_list
{
	size_t			size;
	t_link			*head;
}

typedef struct	s_link
{
	t_proc			proc;
	struct s_list	*next;
}				t_link;

void load_champions(const char *filename, )

# define	PLAYER_ALIVE	"a process shows that player %hhu (%s) is alive"
# define	PLAYER_WON		"player %hhu (%s) won"

# define	FILE_NOT_EXE	"%s is not a corewar executable"
# define	PROG_NUM_USED	"player number %hhu already in use"
# define	FILE_NOT_ACCESS	"file %s not accessible"
# define	MALLOC_ERROR	"malloc error"
# define	CHAMP_TOO_LARGE	"champion %hhu (%s) exceeds maximum size"

