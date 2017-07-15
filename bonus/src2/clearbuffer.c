/*
** clearbuffer.c for  in /home/WASSEX/Semestre1/infographie/wolf3d/src2
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon Jun  5 15:20:01 2017 Wassim Alkayar
** Last update Sun Jun 11 16:10:30 2017 Wassim Alkayar
*/

#include "wolf3d.h"
#include "src.h"

void	clear_buffer(t_window w)
{
  int	x;
  int	y;

  x = 0;
  while (x < SCREEN_WIDTH)
    {
      y = 0;
      while (y < SCREEN_HEIGHT)
	{
	  my_put_pixel(w.framebuffer, x, y, sfBlack);
	  y += 1;
	}
      x += 1;
    }
}

void		draw_floor(t_window w)
{
  int		x;
  int		y;
  sfColor	color;

  x = 0;
  color = change_color(0, 204, 102, 255);
  while (x < SCREEN_WIDTH)
    {
      y = 300;
      while (y < SCREEN_HEIGHT)
	{
	  my_put_pixel(w.framebuffer, x, y, color);
	  y += 1;
	}
      x += 1;
    }
}

void		draw_sky(t_window w)
{
  int		x;
  int		y;
  sfColor	color;

  x = 0;
  color = change_color(0, 255, 255, 255);
  while (x < SCREEN_WIDTH)
    {
      y = SCREEN_HEIGHT / 2;
      while (y >= 0)
	{
	  my_put_pixel(w.framebuffer, x, y, color);
	  y -= 1;
	}
      x += 1;
    }
}
