/*
** move.forward.c for  in /home/WASSEX/Semestre1/Cgraphical/wolf3d/src
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Fri May 19 01:44:15 2017 Wassim Alkayar
** Last update Wed Jun  7 23:33:29 2017 Wassim Alkayar
*/

#include <math.h>
#include <SFML/Graphics.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	result;

  direction = (M_PI * direction) / 180;
  result.x = pos.x + (distance * cos(direction));
  result.y = pos.y + (distance * sin(direction));
  return (result);
}
