/*
** raycast.c for  in /home/WASSEX/Semestre1/infographie/wolf3d/src
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue May 30 13:24:39 2017 Wassim Alkayar
** Last update Wed Jun  7 16:22:42 2017 Wassim Alkayar
*/

#include <SFML/Graphics.h>
#include "src.h"

float	raycast(sfVector2f pos, float direction, int **map,
		sfVector2i mapsize)
{
  float	distance;
  int	x;
  int	y;

  distance = 0;
  x = pos.x;
  y = pos.y;
  while ((map[y][x] == 0 && x >= 0 &&
	  x < mapsize.x && y >= 0 && y < mapsize.y))
    {
      pos = move_forward(pos, direction, 0.04);
      distance += 0.04;
      x = pos.x;
      y = pos.y;
    }
  return (distance);
}
