/*
** my.h for  in /home/WASSEX/Semestre1/bswireframe/include
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu Apr 13 14:14:51 2017 Wassim Alkayar
** Last update Sun Jun 11 21:34:29 2017 Wassim Alkayar
*/

#ifndef SRC_H_
# define SRC_H_
# include <SFML/Graphics.h>
# include <SFML/Graphics.h>
# include <math.h>
# include <stdlib.h>

typedef struct		s_my_framebuffer
{
  int			height;
  int			width;
  sfUint8		*pixels;
}			t_my_framebuffer;

typedef struct		s_my_drawline
{
  int			dx;
  int			dy;
  int			xinc;
  int			yinc;
}			t_my_drawline;

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color);
void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i,
		     sfVector2i,  sfColor);
void	draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		  sfVector2i to, sfColor color);
#endif /* !SRC_H_ */
