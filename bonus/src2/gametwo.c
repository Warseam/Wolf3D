/*
** gametwo.c for  in /home/WASSEX/Semestre1/infographie/wolf3d
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Jun  3 14:53:56 2017 Wassim Alkayar
** Last update Wed Jun  7 23:20:06 2017 Wassim Alkayar
*/

#include <math.h>
#include "wolf3d.h"
#include "src.h"

void	put_game_part_one(t_raycast *a, sfVector2f *pos, sfVector2f *direction)
{
  a->camerax = 2 * a->x / (double)SCREEN_WIDTH - 1;
  a->raypos.x = pos->x;
  a->raypos.y = pos->y;
  a->raydir.x = direction->x + a->plane.x * a->camerax;
  a->raydir.y = direction->y + a->plane.y * a->camerax;
  a->mapx = (int)a->raypos.x;
  a->mapy = (int)a->raypos.y;
  a->deltadist.x = sqrt(1 + (a->raydir.y * a->raydir.y) /
			(a->raydir.x * a->raydir.x));
  a->deltadist.y = sqrt(1 + (a->raydir.x * a->raydir.x) /
			(a->raydir.y * a->raydir.y));
}

void	put_game_part_two(t_raycast *a)
{
  if (a->side == 0)
    a->walldist = (a->mapx - a->raypos.x + (1 - a->step.x) / 2) / a->raydir.x;
  else
    a->walldist = (a->mapy - a->raypos.y + (1 - a->step.y) / 2) / a->raydir.y;
  a->lineheight = (int)(SCREEN_HEIGHT / a->walldist);
  a->drawstart = -a->lineheight / 2 + SCREEN_HEIGHT / 2;
  a->drawend = a->lineheight / 2 + SCREEN_HEIGHT / 2;
  if (a->drawstart < 0)
    a->drawstart = 0;
  if (a->drawend >= SCREEN_HEIGHT)
    a->drawend = SCREEN_HEIGHT - 1;
}
