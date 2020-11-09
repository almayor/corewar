/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_logs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:37:35 by fallard           #+#    #+#             */
/*   Updated: 2020/11/09 20:57:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_LOGS_H

# define COREWAR_LOGS_H

# define PLAYER_ALIVE		"Champion %u (%s) has been reported as alive\n"
# define PLAYER_WON			"Champion %u (%s) has won!\n"
# define NO_LIVE			"No `live` has been executed during the game"

# define MALLOC_ERROR		"Malloc error\n"

# define OPEN_ERROR			"Error! Cannot open '%s': %s\n"
# define READ_ERROR			"Error! File '%s': %s\n"
# define CHAMP_TOO_LARGE	"Error! Champion %u (%s) is too large (%u bytes)\n"
# define CHAMP_WRONG_SIZE	"Error! Champion %u (%s) has a size mismatch\n"

# define NO_PLAYERS			"Error! No players"
# define MANY_PLAYERS		"Error! Too many players (max = 4)"
# define PROG_NUM_USED		"Error! Champion number %s already in use\n"

# define INVALID_KEY		"Error! Invalid key: %s\n"
# define NOT_ENOUGH_N		"Error! Not enough arguments to use key -n\n"
# define BAD_N_FORMAT		"Error! Wrong number format after key -n: '%s'\n"
# define N_OUT_OF_RANGE		"Error! Champion number must be between 1 and 4\n"
# define DUMP_INVALID		"Error! -dump %s is invalid\n"
# define NOT_ENOUGH_DUMP	"Error! Not enough arguments to use key -dump\n"




#endif
