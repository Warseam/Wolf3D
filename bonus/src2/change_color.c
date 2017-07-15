/*
** utils.c for  in /home/WASSEX/Semestre1/bswireframe
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue May  2 13:53:26 2017 Wassim Alkayar
** Last update Sat May 20 17:07:29 2017 Wassim Alkayar
*/

#include <SFML/Graphics/RenderWindow.h>

sfColor		change_color(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}
