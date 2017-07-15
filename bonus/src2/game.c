/*
** game.c for  in /home/WASSEX/Semestre1/infographie/wolf3d
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Fri Jun  2 15:14:46 2017 Wassim Alkayar
** Last update Sun Jul 16 01:08:46 2017 Wassim Alkayar
*/

#include <math.h>
#include <SFML/Window/Event.h>
#include "wolf3d.h"
#include "src.h"

sfVector2f	set_sidedist(t_raycast *a)
{
  sfVector2f	sidedist;

  if (a->raydir.x < 0)
    {
      a->step.x = -1;
      sidedist.x = (a->raypos.x - a->mapx) * a->deltadist.x;
    }
  else
    {
      a->step.x = 1;
      sidedist.x = (a->mapx + 1.0 - a->raypos.x) * a->deltadist.x;
    }
  if (a->raydir.y < 0)
    {
      a->step.y = -1;
      sidedist.y = (a->raypos.y - a->mapy) * a->deltadist.y;
    }
  else
    {
      a->step.y = 1;
      sidedist.y = (a->mapy + 1.0 - a->raypos.y) * a->deltadist.y;
    }
  return (sidedist);
}

int	check_hit_wall(t_raycast *a, int hit, int **tab)
{
  while (hit == 0)
    {
      if (a->sidedist.x < a->sidedist.y)
	{
	  a->sidedist.x += a->deltadist.x;
	  a->mapx += a->step.x;
	  a->side = 0;
	}
      else
	{
	  a->sidedist.y += a->deltadist.y;
	  a->mapy += a->step.y;
	  a->side = 1;
	}
      if (tab[a->mapx][a->mapy] == 2)
	return (1);
    }
  return (0);
}

void	keyboard_react(sfVector2f *pos,
		       sfVector2f *direction,
		       int **tab,
		       t_raycast *a)
{
  int	x;
  int	y;

  x = pos->x;
  y = pos->y;
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    key_up(pos, direction, tab, a);
  if (sfKeyboard_isKeyPressed(sfKeyDown))
    key_down(pos, direction, tab, a);
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    key_right(a, direction);
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    key_left(a, direction);
  if (sfKeyboard_isKeyPressed(sfKeyNum1))
    a->movespeed -= 0.02;
  if (sfKeyboard_isKeyPressed(sfKeyNum2))
    a->movespeed += 0.02;
  if (sfKeyboard_isKeyPressed(sfKeyC))
      tab[x][y + 2] = 2;
}

void		put_game(sfVector2f pos,
			 sfVector2f direction,
			 int **tab,
			 t_window w)
{
  int		hit;
  t_raycast	a;

  a.movespeed = 0.04;
  a.plane.x = 0;
  a.plane.y = 0.66;
  while (1 == 1)
    {
      while (a.x < SCREEN_WIDTH)
	{
	  put_game_part_one(&a, &pos, &direction);
	  hit = 0;
	  a.sidedist = set_sidedist(&a);
	  hit = check_hit_wall(&a, hit, tab);
	  put_game_part_two(&a);
	  my_draw_linecustom(w.framebuffer, a.x, a.drawstart, a.drawend);
	  a.x += 1;
	}
      keyboard_react(&pos, &direction, tab, &a);
      maintain_window(w.window, w.texture, w.sprite, w.framebuffer);
      clear_buffer(w);
      draw_floor(w);
      draw_sky(w);
      a.x = 0;
    }
}

void		initializing(int **tab, t_window w)
{
  sfVector2f	playerpos;
  sfVector2f	direction;

  playerpos.x = 10;
  playerpos.y = 10;
  direction.x = -1;
  direction.y = 0;
  put_game(playerpos, direction, tab, w);
}
