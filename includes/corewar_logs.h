#ifndef COREWAR_LOGS_H
# define COREWAR_LOGS_H

# define	PLAYER_ALIVE	"a process shows that player %u (%s) is alive\n"
# define	PLAYER_WON		"player %u (%s) won\n"
# define	NO_LIVE			"no live has been executed during the game"

# define	FILE_NOT_EXE	"%s is not a corewar executable\n"
# define	PROG_NUM_USED	"Player number %s already in use\n"
# define	FILE_NOT_ACCESS	"file %s not accessible\n"
# define	FILE_MANGLED	"file %s mangled"
# define	MALLOC_ERROR	"malloc error\n"
# define	CHAMP_TOO_LARGE	"Player '%s' has too large size (%u bytes > 682 bytes)\n"
# define	INVALID_MACRO	"macro %s values other than %i are not supported\n"
# define	DUMP_INVALID	"-dump %s is invalid\n"
# define	N_INVALID		"-n %s is invalid"

# define	OUT_OF_RANGE	"Player number must be between 1 and 4"
# define	NOT_ENOUGH_N	"Not enough arguments to use key -n"
# define	NOT_ENOUGH_DUMP	"Not enough arguments to use key -dump"
# define	BAD_N_FORMAT	"Wrong number format after key -n: '%s'\n"
# define	A_LOT_OF_PLAYER "Error! A lot of players. Max players - 4."
# define	BAD_MAGIC		"Error! File '%s' has bad magic number\n"
# define	READ_ERROR		"Error reading '%s': %s\n"
# define 	OPEN_ERROR		"Cannot open '%s': %s\n"
# define	NO_PLAYERS		"Error! No players"

#endif
