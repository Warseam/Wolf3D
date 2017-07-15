/*
** main.c for main.c in /home/WASSEX/Semestre1/Cgraphical/wolf3d
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu May 18 16:57:13 2017 Wassim Alkayar
** Last update Sun Jul 16 01:20:32 2017 Wassim Alkayar
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "src.h"
#include "wolf3d.h"

void		put_window(int **tab)
{
  t_window	w;
  sfMusic	*music;

  w.framebuffer = malloc(sizeof(t_my_framebuffer));
  if (w.framebuffer == NULL)
    return ;
  w.framebuffer->width = SCREEN_WIDTH;
  w.framebuffer->height = SCREEN_HEIGHT;
  w.window = create_window("W O L F  3 D", SCREEN_WIDTH, SCREEN_HEIGHT);
  w.sprite = sfSprite_create();
  w.texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  w.framebuffer->pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
  if (!(music = sfMusic_createFromFile(MUSIC)))
    return ;
  sfMusic_setLoop(music, sfTrue);
  sfMusic_play(music);
  sfSprite_setTexture(w.sprite, w.texture, sfTrue);
  initializing(tab, w);
  close_window(w.window, w.texture, w.sprite, w.framebuffer);
}

int	main(int argc, char **argv)
{
  char	*map;
  int	**tab;

  if (argc != 2)
    return (0);
  map = copy_map(argv[1], get_file_size(argv[1]));
  tab = prepare_get_tab_from_map(map);
  free(map);
  put_window(tab);
  free(tab);
  return (0);
}
