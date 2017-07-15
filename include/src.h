/*
** my.h for  in /home/WASSEX/Semestre1/bswireframe/include
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu Apr 13 14:14:51 2017 Wassim Alkayar
** Last update Sun Jun 11 16:55:16 2017 Wassim Alkayar
*/

#ifndef SRC_H_
# define SRC_H_
# include <SFML/Graphics.h>
# include <SFML/Graphics.h>
# include <math.h>
# include <stdlib.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_drawline
{
  int			dx;
  int			dy;
  int			xinc;
  int			yinc;
}			t_my_drawline;

void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x,
				     int y,
				     sfColor color);

void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from,
				     sfVector2i to,
				     sfColor color);

t_my_drawline		first_step(sfVector2i from,
				   sfVector2i to,
				   t_my_drawline a,
				   int *var);

sfVector2f		move_forward(sfVector2f pos,
				     float direction,
				     float distance);

float			raycast(sfVector2f pos,
				float direction,
				int **map,
				sfVector2i mapsize);

#endif /* !SRC_H_ */
