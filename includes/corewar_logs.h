/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_logs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:37:35 by fallard           #+#    #+#             */
/*   Updated: 2020/11/12 20:57:33 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_LOGS_H

# define COREWAR_LOGS_H

# define CHAMP_ALIVE		"Player %u (%s) is said to be alive\n"
# define CHAMP_WON			"Player %u (%s) has won!\n"
# define NO_LIVE			"No `live` has been executed during the game!"

# define MALLOC_ERROR		"Malloc error\n"

# define OPEN_ERROR			"Error! Cannot open '%s': %s\n"
# define READ_ERROR			"Error! File '%s': %s\n"
# define CHAMP_TOO_LARGE	"Error! Player %u (%s) is too large (%u bytes)\n"
# define CHAMP_WRONG_SIZE	"Error! Player %u (%s) has a size mismatch\n"

# define NO_PLAYERS			"Error! No players\n"
# define MANY_PLAYERS		"Error! Too many players (max = 4)\n"
# define PROG_NUM_USED		"Error! Player number %s already in use\n"

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

#endif
