/*
** close_window.c for  in /home/WASSEX/Semestre1/infographie/wolf3d/src2
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu Jun  1 15:45:08 2017 Wassim Alkayar
** Last update Wed Jun  7 14:58:19 2017 Wassim Alkayar
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "src.h"
#include "wolf3d.h"

void	close_window(sfRenderWindow *window,
			sfTexture *texture,
			sfSprite *sprite,
			t_my_framebuffer *framebuffer)
{
  sfRenderWindow_destroy(window);
  free(framebuffer);
  free(window);
  free(texture);
  free(sprite);
}
