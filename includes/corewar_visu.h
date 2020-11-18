/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visu.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:42:31 by fallard           #+#    #+#             */
/*   Updated: 2020/11/18 16:45:37 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISU_H
# define COREWAR_VISU_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>

# include "libft.h"

# define WIDTH 1600
# define HEIGHT 768
# define POS_X 40
# define POS_Y 40

# define FONT "open-sans/OpenSans-Regular.ttf"
# define HEX "0123456789ABCDEF"

typedef struct s_visu t_visu;

struct				s_visu
{
	uint8_t			vmem[MEM_SIZE];
	SDL_Window		*win;
	SDL_Renderer	*rend;
	TTF_Font		*font;
	SDL_Rect		rect;
	int				quit;
	int				pause;
	int				runing;
};

extern	t_visu g_visu;

void	sdl_launch();
void	sdl_draw();

#endif
