/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_logs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:20:17 by user              #+#    #+#             */
/*   Updated: 2020/12/02 22:01:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_LOGS_H

# define COREWAR_LOGS_H

# define CHAMP_ALIVE		"Player %u (%s) is said to be alive\n"
# define CHAMP_WON			"Player %u (%s) has won!\n"

# define MALLOC_ERROR		"Malloc error\n"
# define SDL_NOT_SUPPORT	"Please install SDL2 and SDL2_ttf to visualize!\n"

# define OPEN_ERROR			"Error! Cannot open '%s': %s\n"
# define READ_ERROR			"Error! File '%s': %s\n"
# define CHAMP_TOO_LARGE	"Error! Player %u (%s) is too large (%u bytes)\n"
# define CHAMP_WRONG_SIZE	"Error! Player %u (%s) has a size mismatch\n"

# define NO_PLAYERS			"Error! No players\n"
# define MANY_PLAYERS		"Error! Too many players (max = 4)\n"
# define PROG_NUM_USED		"Error! Player number %d already in use\n"

# define INVALID_KEY		"Error! Invalid key: %s\n"
# define NOT_ENOUGH			"Error! Not enough arguments to use key '%s'\n"
# define BAD_N_FORMAT		"Error! Wrong number format after key -n: '%s'\n"
# define BAD_LOG_FORMAT		"Error! Wrong number format after key -log: '%s'\n"
# define OUT_OF_RANGE_LOG	"Error! Number of log must be between 0 and 31\n"
# define N_OUT_OF_RANGE		"Error! Player number must be between 1 and 4\n"
# define DUMP_INVALID		"Error! -dump '%s' is invalid\n"

# define LOG_OPER_PREFIX_P	"P%05lu | "
# define LOG_OPER_PREFIX	"       | "
# define LOG_ADV_PREFIX_P	"P%05lu > "
# define LOG_ADV_PREFIX		"       > "

# define MEM_DUMP_WIDTH		32

#endif
