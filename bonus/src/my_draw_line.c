/*
** my_draw_line.c for  in /home/WASSEX/Semestre1/bswireframe
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon May  1 01:11:39 2017 Wassim Alkayar
** Last update Wed Jun  7 23:22:29 2017 Wassim Alkayar
*/

#include "src.h"

void			more_vertical(t_my_framebuffer *framebuffer,
			      sfVector2i from,
			      sfVector2i to,
			      sfColor color)
{
  t_my_drawline		a;
  int			cumul;
  int			i;

  a.dx = to.x - from.x;
  a.dy = to.y - from.y;
  a.xinc = (a.dx > 0) ? 1 : -1;
  a.yinc = (a.dy > 0) ? 1 : -1;
  a.dx = abs(a.dx);
  a.dy = abs(a.dy);
  cumul = a.dx / 2;
  i = 1;
  while (i <= a.dx)
    {
      from.x = from.x + a.xinc;
      cumul = cumul + a.dy;
      if (cumul >= a.dx)
	{
	  cumul = cumul -a.dx;
	  from.y = from.y + a.yinc;
	}
      my_put_pixel(framebuffer, from.x, from.y, color);
      i += 1;
    }
}

void			more_horizontal(t_my_framebuffer *framebuffer,
				sfVector2i from,
				sfVector2i to,
				sfColor color)
{
  t_my_drawline		a;
  int			cumul;
  int			i;

  a.dx = to.x - from.x;
  a.dy = to.y - from.y;
  a.xinc = (a.dx > 0) ? 1 : -1;
  a.yinc = (a.dy > 0) ? 1 : -1;
  a.dx = abs(a.dx);
  a.dy = abs(a.dy);
  cumul = a.dy / 2;
  i = 1;
  while (i <= a.dy)
    {
      from.y = from.y + a.yinc;
      cumul += a.dx;
      if (cumul >= a.dy)
	{
	  cumul -= a.dy;
	  from.x = from.x + a.xinc;
	}
      my_put_pixel(framebuffer, from.x, from.y, color);
      i += 1;
    }
}

void		my_draw_line(t_my_framebuffer *framebuffer,
			     sfVector2i from,
			     sfVector2i to,
			     sfColor color)
{
  int		dx;
  int		dy;

  dx = to.x - from.x;
  dy = to.y - from.y;
  dx = abs(dx);
  dy = abs(dy);
  my_put_pixel(framebuffer, from.x, from.y, color);
  if (dx > dy)
    more_vertical(framebuffer, from, to, color);
  else
    more_horizontal(framebuffer, from, to, color);
}
