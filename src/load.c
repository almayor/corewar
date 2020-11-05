#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>

static int	check_magic(int fd)
{
	static char	magic_arr[4];
	uint32_t	magic_num;	

	if (read(fd, magic, 4) != 4)
		return (1);
	magic_num = magic_arr[0] << 24
				| magic_arr[1] << 16
				| magic_arr[2] << 8
				| magic_arr[3];
	return (magic_num == COREWAR_EXEC_MAGIC);
}

static int	load_bytecode(int fd, uint32_t pos)
{
	static char	bytecode[CHAMP_MAX_SIZE];
	ssize_t		nbytes;
	size_t		i;

	ft_bzero(bytecode, CHAMP_MAX_SIZE);
	if ((nbytes = read(fd, bytecode, CHAMP_MAX_SIZE)) <= 0)
		return (1);
	i = 0;
	while (i < nbytes)
		mem_write_8bit(pos++, bytecode[i++]);
	return (0);
}

static int	check_champ_size(int fd)
{
	static char	size_arr[4];
	uint32_t	size_val;

	if (read(fd, magic, 4) != 4)
		return (1);
	size_val = size_arr[0] << 24
				| size_arr[1] << 16
				| size_arr[2] << 8
				| size_arr[3];
	return (size_val <= CHAMP_MAX_SIZE);
}

void 		load(const char *file, int ichamp, uint32_t	pos)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		terminate(FILE_NOT_ACCESS, file);
	else if (check_magic(fd))
		terminate(FILE_NOT_EXE, file);
	else if (read(fd, g_vm.champs[ichamp].name, PROG_NAME_LENGTH)
			!= PROG_NAME_LENGTH)
		terminate(FILE_MANGLED, file);
	else if (check_champ_size(fd))
		terminate(CHAMP_TOO_LARGE, ichamp, g_vm.champs[ichamp].name);
	else if (read(fd, g_vm.champs[ichamp].comment, COMMENT_LENGTH)
			!= COMMENT_LENGTH)
		terminate(FILE_MANGLED, file);
	else if (load_bytecode(fd, pos))
		terminate(FILE_MANGLED, file);
}
