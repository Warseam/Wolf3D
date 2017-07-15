/*
** put_pixel.c for  in /home/WASSEX/Semestre1/bswireframe
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu Apr 13 14:11:58 2017 Wassim Alkayar
** Last update Wed Jun  7 23:07:40 2017 Wassim Alkayar
*/

#include "src.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x,
		     int y,
		     sfColor color)
{
  if ((x >= 0 && x < framebuffer->width) &&
      (y >= 0 && y < framebuffer->height))
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
