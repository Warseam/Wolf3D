/*
** create_pixel_buffer.c for  in /home/WASSEX/Semestre1/bswireframe
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sun Apr 16 16:39:18 2017 Wassim Alkayar
** Last update Wed May 31 14:52:19 2017 Wassim Alkayar
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

sfUint8		*create_pixel_buffer(int width, int height)
{
  int		i;
  sfUint8*	pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    return (0);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}
