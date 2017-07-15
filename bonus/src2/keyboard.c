/*
** keyboard.c for  in /home/WASSEX/Semestre1/infographie/wolf3d/src2
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Jun  6 14:15:53 2017 Wassim Alkayar
** Last update Sun Jun 11 21:35:53 2017 Wassim Alkayar
*/

#include <math.h>
#include "wolf3d.h"
#include "src.h"

void	key_up(sfVector2f *pos,
	       sfVector2f *direction,
	       int **tab,
	       t_raycast *a)
{
  int	posx;
  int	posy;

  posx = (pos->x + direction->x * a->movespeed);
  posy = (pos->y + direction->y * a->movespeed);
  posx = pos->x;
  if ((tab[posx][posy]) != 2)
    {
      pos->x += direction->x * a->movespeed;
      pos->y += direction->y * a->movespeed;
    }
}

void	key_down(sfVector2f *pos,
		 sfVector2f *direction,
		 int **tab,
		 t_raycast *a)
{
  int	posx;
  int	posy;

  posx = (pos->x - direction->x * a->movespeed);
  posy = (pos->y - direction->y * a->movespeed);
  if ((tab[posx][posy]) != 2)
    {
      pos->x -= direction->x * a->movespeed;
      pos->y -= direction->y * a->movespeed;
    }
}

void	key_right(t_raycast *a,
		  sfVector2f *direction)
{
  a->olddirx = direction->x;
  direction->x = direction->x * cos(- ROTSPEED) -
    direction->y * sin(- ROTSPEED);
  direction->y = a->olddirx * sin(- ROTSPEED) + direction->y * cos(- ROTSPEED);
  a->oldplanex = a->plane.x;
  a->plane.x = a->plane.x * cos(- ROTSPEED) - a->plane.y * sin(- ROTSPEED);
  a->plane.y = a->oldplanex * sin(- ROTSPEED) + a->plane.y * cos(- ROTSPEED);
}

void	key_left(t_raycast *a,
		 sfVector2f *direction)
{
  a->olddirx = direction->x;
  direction->x = direction->x * cos(ROTSPEED) - direction->y * sin(ROTSPEED);
  direction->y = a->olddirx * sin(ROTSPEED) + direction->y * cos(ROTSPEED);
  a->oldplanex = a->plane.x;
  a->plane.x = a->plane.x * cos(ROTSPEED) - a->plane.y * sin(ROTSPEED);
  a->plane.y = a->oldplanex * sin(ROTSPEED) + a->plane.y * cos(ROTSPEED);
}
