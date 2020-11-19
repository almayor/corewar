/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visu.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:42:31 by fallard           #+#    #+#             */
/*   Updated: 2020/11/20 00:48:34 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISU_H
# define COREWAR_VISU_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>

# include "corewar.h"
# include "libft.h"
# include <time.h>

# define RUNNING "** RUNNING **"
# define PAUSED "** PAUSED **"

# define S_CYCLE	"Cycle:     "
# define S_PROC		"Processes: "
# define S_CURRLIVE	"Lives in current period: "
# define LAST_LIVE	"Last live:               "


# define WIDTH 1600
# define HEIGHT 768
# define POS_X 40
# define POS_Y 40

//# define FONT "fonts/Anonymous_Pro_B.ttf"
# define FONT "fonts/DroidSansMono.ttf"
# define HEX "0123456789ABCDEF"

typedef struct s_visu t_visu;

struct				s_visu
{
	uint8_t			vmem[MEM_SIZE];
	SDL_Window		*win;
	SDL_Renderer	*rend;
	TTF_Font		*font;
	SDL_Rect		rect;
	SDL_Event		event;
	const uint8_t	*keyboard;
	int				quit;
	int				pause;
	int				pause_flag;
	int				runing;
	int				click;
	int				x;
	int				y;
};

extern	t_visu g_visu;

void	sdl_launch();
void	sdl_draw();
void	sdl_mark_champ(uint32_t ichamp, size_t nbytes, uint32_t pos);
void	sdl_put_params();
void	sdl_draw_border();
char	*ft_ulltoa(uint64_t nbr);
void	sdl_put_number(char *s, uint64_t n, int x, int y);
SDL_Color get_player_color(uint32_t ichamp);

char	*sdl_strjoin(char *str1, char *str2);

void	sdl_new_draw(void);

char	*hex_num(uint8_t n);

void	sdl_put_text(const char *word, SDL_Color color, SDL_Rect pos);
void	draw_hex(uint8_t n, SDL_Color color, SDL_Rect pos);
char	*sdl_threejoin(uint32_t n, char *name);

void	sdl_put_players(void);




#endif
