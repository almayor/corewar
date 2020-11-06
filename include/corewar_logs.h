/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_logs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:14 by user              #+#    #+#             */
/*   Updated: 2020/11/06 14:37:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_LOGS_H

# define COREWAR_LOGS_H

# define	PLAYER_ALIVE	"a process shows that player %u (%s) is alive\n"
# define	PLAYER_WON		"player %u (%s) won\n"
# define	NO_LIVE			"no live has been executed during the game"

# define	FILE_NOT_EXE	"%s is not a corewar executable\n"
# define	FILE_NOT_ACCESS	"file %s not accessible\n"
# define	FILE_MANGLED	"file %s mangled"
# define	CHAMP_TOO_LARGE	"champion %u (%s) exceeds maximum size\n"

# define	PROG_NUM_USED	"player number %u already in use\n"
# define	DUMP_INVALID	"-dump %s is invalid"
# define	N_INVALID		"-n %s is invalid"

# define	MALLOC_ERROR	"malloc error\n"
# define	INVALID_MACRO	"macro %s values other than %i are not supported\n"

#endif
