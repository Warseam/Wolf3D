/*
** my.h for  in /home/WASSEX/Semestre1/bswireframe/include
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon May  1 22:48:46 2017 Wassim Alkayar
** Last update Sun Jun 11 23:13:37 2017 Wassim Alkayar
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Audio.h>
# include "src.h"

# define	SCREEN_WIDTH	1000
# define	SCREEN_HEIGHT	1000
# define	MOVESPEED	0.04
# define	ROTSPEED	0.02
# define	MUSIC		"music/music.ogg"

typedef struct		s_window
{
  t_my_framebuffer	*framebuffer;
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*texture;
}			t_window;

typedef struct		s_raycast
{
  sfVector2f	raypos;
  sfVector2f	raydir;
  int		mapx;
  int		mapy;
  sfVector2f	sidedist;
  sfVector2f	deltadist;
  sfVector2f	step;
  sfVector2f	plane;
  float		walldist;
  double	camerax;
  float		olddirx;
  float		oldplanex;
  int		side;
  int		lineheight;
  int		drawstart;
  int		drawend;
  int		x;
  float		movespeed;
}			t_raycast;

int	my_strlen(char *str);

int	get_file_size(char *file);
int	**prepare_get_tab_from_map(char *map);
int	**get_tab_from_map(char *map, int i, int j, int **tab);
char	*copy_map(char *file, int filesize);

sfUint8		*create_pixel_buffer(int width, int height);
sfColor		change_color(int r, int g, int b, int a);
sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle);
sfRenderWindow	*create_window(char *name, int width, int height);
void		maintain_window(sfRenderWindow *window,
				sfTexture *texture,
				sfSprite *sprite,
				t_my_framebuffer *framebuffer);
void		close_window(sfRenderWindow *window,
			     sfTexture *texture,
			     sfSprite *sprite,
			     t_my_framebuffer *framebuffer);

void		clear_buffer(t_window w);

sfVector2f	set_sidedist(t_raycast *a);
int		check_hit_windowall(t_raycast *a, int hit, int **tab);
void		put_game(sfVector2f pos,
			 sfVector2f direction,
			 int **tab,
			 t_window w);

void		initializing(int **tab, t_window w);

void		my_draw_linecustom(t_my_framebuffer *framebuffer,
				   int x,
				   int drawstart,
				   int drawend);

void		more_vertical(t_my_framebuffer *framebuffer,
				    sfVector2i from,
				    sfVector2i to,
				    sfColor color);

void		more_horizontal(t_my_framebuffer *framebuffer,
				      sfVector2i from,
				      sfVector2i to,
				      sfColor color);

void	put_game_part_one(t_raycast *a,
			  sfVector2f *pos,
			  sfVector2f *direction);
void	put_game_part_two(t_raycast *a);

void	key_up(sfVector2f *pos,
	       sfVector2f *direction,
	       int **tab,
	       t_raycast *a);
void	key_down(sfVector2f *pos,
		 sfVector2f *direction,
		 int **tab,
		 t_raycast *a);
void	key_right(t_raycast *a, sfVector2f *direction);
void	key_left(t_raycast *a, sfVector2f *direction);

void	draw_sky(t_window w);
void	draw_floor(t_window w);

#endif /* !WOLF3D_H_ */
