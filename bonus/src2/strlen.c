/*
** my_strlen.c for my_strlen in /home/Wasx/CPool_Day04
** 
** Made by Wassim ALKAYAR
** Login   <Wasx@epitech.net>
** 
** Started on  Thu Mar  2 15:08:40 2017 Wassim ALKAYAR
** Last update Thu May 18 20:09:42 2017 Wassim Alkayar
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
