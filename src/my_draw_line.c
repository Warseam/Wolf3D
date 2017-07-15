/*
** my_draw_line.c for  in /home/WASSEX/Semestre1/bswireframe
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon May  1 01:11:39 2017 Wassim Alkayar
** Last update Sat Jun 10 14:17:07 2017 Wassim Alkayar
*/

#include "src.h"

t_my_drawline	first_step(sfVector2i from,
			   sfVector2i to,
			   t_my_drawline a,
			   int *var)
{
  a.dx =  abs(to.x - from.x);
  a.xinc = -1;
  if (from.x < to.x)
    a.xinc = 1;
  a.dy = -abs(to.y - from.y);
  a.yinc = -1;
  if (from.y < to.y)
    a.yinc = 1;
  *var = a.dx + a.dy;
  return (a);
}

void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from,
				     sfVector2i to,
				     sfColor color)
{
  t_my_drawline		a;
  int			var;
  int			var2;

  a = first_step(from, to, a, &var);
  while (from.x != to.x && from.y != to.y)
    {
      my_put_pixel(framebuffer, from.x, from.y, color);
      var2 = 2 * var;
      if (var2 >= a.dy)
	{
	  var = var + a.dy;
	  from.x = from.x + a.xinc;
	}
      if (var2 <= a.dx)
	{
	  var = var + a.dx;
	  from.y = from.y + a.yinc;
	}
    }
}
