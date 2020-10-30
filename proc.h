
uint8_t	T_REG = 1 << 0; 
uint8_t T_DIR = 1 << 1;
uint8_t	T_IND = 1 << 2;

typedef struct	s_op
{
	const char		*name;				// operation name
	const uint8_t	args[3];			// types of allowed arguments (a bit-mask)
	uint8_t			opcode;				// the op-code
	uint8_t			duration;			// operation duration
	const char		*doc;				// doc string
	uint8_t			modify_carry;		// whether operation modifies carry (a boolean)
	uint8_t			???;
}				t_op;

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

typedef struct	s_proc
{
	uint8_t			*reg; 				// registries as a continuous block of size (REG_NUMBER * REG_SIZE) bytes
	uint64_t		pc; 				// program counter
	uint64_t		cycles_since_live;	// number of cycles passed since this process last executed a `live`
	uint8_t			carry;				// carry
}				t_proc;

typedef struct	s_vm
{
	t_list			*procs;				// a singly linked list of processes
	uint64_t		cycle_to_die;		// current value of cycle to die
	uint8_t			*mem;				// circular memory
}				t_vm;

extern t_vm	*g_vm;

typedef struct	s_list
{
	t_proc			proc;
	struct s_list	*next;
}				t_list;

