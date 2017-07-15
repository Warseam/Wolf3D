/*
** readfile.c for  in /home/WASSEX/Semestre1/Cgraphical/wolf3d/src2
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Thu May 18 17:05:07 2017 Wassim Alkayar
** Last update Sun Jul 16 01:21:03 2017 Wassim Alkayar
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "wolf3d.h"

int	get_file_size(char *file)
{
  int	filesize;
  int	fd;
  char	c;
  int	i;

  filesize = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  while ((i = (read(fd, &c, 1)) != 0))
    filesize += 1;
  if ((close(fd)) == -1)
    return (0);
  return (filesize);
}

int	get_line_number(char *map)
{
  int	i;
  int	ct;

  ct = 0;
  i = 0;
  while (map[i] != '\0')
    {
      if (map[i] == '\n')
	ct += 1;
      i += 1;
    }
  return (ct);
}

int	**get_tab_from_map(char *map, int i, int j, int **tab)
{
  int	k;

  k = 0;
  if ((tab = malloc(sizeof(char *) * (get_line_number(map) + 1))) == NULL)
    return (0);
  while (map[i] != '\0')
    {
      if ((tab[k] = malloc(sizeof(char) * my_strlen(map))) == NULL)
      return (0);
      j = 0;
      while (map[i] != '\n')
	{
	  if (map[i] == '1' || map[i] == '2' || map[i] == '5')
	    {
	      tab[k][j] = map[i] - '0';
	      j += 1;
	    }
	  i += 1;
	}
      i += 1;
      k += 1;
    }
  tab[k] = 0;
  return (tab);
}

int	**prepare_get_tab_from_map(char *map)
{
  int	i;
  int	j;
  int	**tab;

  tab = NULL;
  i = 0;
  j = 0;
  tab = get_tab_from_map(map, i, j, tab);
  return (tab);
}

char	*copy_map(char *file, int filesize)
{
  int	fd;
  char	*map;

  map = malloc(sizeof(char) * filesize + 1);
  if (map == NULL)
    exit (0);
  if ((fd = open(file, O_RDONLY)) == -1)
    exit (0);
  read(fd, map, filesize);
  map[filesize] = '\0';
  if ((close(fd)) == -1)
    exit (0);
  return (map);
}
