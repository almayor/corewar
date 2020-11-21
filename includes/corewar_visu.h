/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visu.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:42:31 by fallard           #+#    #+#             */
/*   Updated: 2020/11/21 23:40:37 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISU_H
# define COREWAR_VISU_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include "corewar.h"

# define RUNNING	"*** RUNNING ***"
# define PAUSED		"*** PAUSED ***"

# define S_CYCLE	"Cycle:     "
# define S_PROC		"Processes: "
# define S_CURRLIVE	"Lives in current period: "
# define LAST_LIVE	"Last live:               "

# define CURR_RATIO	"Live breakdown for current period:"
# define PREV_RATIO "Live breakdown for previous period:"
# define EMPTY_LINE	"[                                                  ]"
# define FILL_LINE	"##################################################"

# define USAGE_0	"       ****** HANDLING ******"
# define USAGE_1	"Pause / Run         SPACE"
# define USAGE_2	"Left / Right        MOUSE PRESSED"
# define USAGE_3	"Up / Down           MOUSE WHEEL"

# define SURFACE	"Error create SDL surface\n"
# define TEXTURE	"Error create texture from surface\n"

# define WIDTH		1600
# define HEIGHT		768
# define POS_X		40
# define POS_Y		40

# define FONT		"fonts/DroidSansMono.ttf"
# define HEX		"0123456789ABCDEF"

typedef struct s_visu	t_visu;
typedef struct s_vmap	t_vmap;

struct				s_vmap
{
	SDL_Rect		pos;
	SDL_Color		clr;
	char			*join;
	char			*next;
	char			*tmp;
	int				i;
	int				j;
};

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
	int				m_x;
	int				m_y;
	int				g_x;
	int				g_y;
};

extern	t_visu		g_visu;

/*
** >>------------------<< SDL INIT / QUIT >>-----------------------<<
*/

void				sdl_launch(void);
void				sdl_quit(void);

/*
** >>-----------------------<< SDL UTILS >>----------------------------<<
*/

void				sdl_mark_champ(uint32_t ichamp,
						size_t nbytes, uint32_t pos);
SDL_Color			get_player_color(uint32_t ichamp);
char				*sdl_strjoin(char *str1, char *str2);
char				*sdl_threejoin(uint32_t n, char *name);
char				*ft_ulltoa(uint64_t nbr);
char				*hex_num(uint8_t n);

/*
** >>-----------------------<< SDL EVENT >>----------------------------<<
*/

void				sdl_loop(void);
void				sdl_mouse_event(SDL_Event event);
void				sdl_pause_event(SDL_Event event);

/*
** >>------------------------<< SDL DRAW >>----------------------------<<
*/

void				sdl_draw_map(void);
void				sdl_draw_info(void);
void				sdl_draw_ratio(SDL_Rect pos, SDL_Color clr, int flag);
void				sdl_draw_border();

void				sdl_put_number(char *s, uint64_t n, int x, int y);
void				sdl_put_text(const char *word,
						SDL_Color color, SDL_Rect pos);

#endif
