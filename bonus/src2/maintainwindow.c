/*
** close_window.c for  in /home/WASSEX/Semestre1/infographie/wolf3d/src2
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Wed May 31 16:42:36 2017 Wassim Alkayar
** Last update Sun Jun 11 23:15:17 2017 Wassim Alkayar
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "src.h"
#include "wolf3d.h"

void	maintain_window(sfRenderWindow *window,
			sfTexture *texture,
			sfSprite *sprite,
			t_my_framebuffer *framebuffer)
{
  sfTexture_updateFromPixels(texture, framebuffer->pixels, SCREEN_WIDTH,
			     SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_display(window);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}
