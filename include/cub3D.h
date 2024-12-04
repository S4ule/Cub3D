/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:57:12 by sbalesme          #+#    #+#             */
/*   Updated: 2022/11/14 12:09:10 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"

# ifndef WIDTHW
#  define WIDTHW 1280
# endif

# ifndef HEIGHTW
#  define HEIGHTW 1024
# endif

/*
-------------------------------------------------------------------------------
keys cub3D
-------------------------------------------------------------------------------
*/
# define ESC 65307
# define QUIT 113
# define A 97
# define W 119
# define S 115
# define D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363 

/*
-------------------------------------------------------------------------------
struct cub3D
-------------------------------------------------------------------------------
*/
typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			allray;
	double		wall_x;
}	t_ray;

typedef struct s_tex
{
	void	*n_start;
	void	*s_start;
	void	*w_start;
	void	*e_start;
	int		floor;
	int		ceiling;
}	t_tex;

typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_game
{
	int			fd;
	t_tex		tex;
	int			height;
	int			width;
	char		**mapping;
	char		**imgs;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*screen_img;
	int			*screen_img_addr;
	t_player	player;
	float		x;
	float		y;
	int			img_x;
	int			img_y;
	double		dalle;
	double		map_h;
	double		map_w;
	t_ray		ray;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
	int			**imgs_text;
	int			num_imgs_text;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_game;

/*
-------------------------------------------------------------------------------
main.c
-------------------------------------------------------------------------------
*/
int		main(int ac, char **av);

/*
-------------------------------------------------------------------------------
error.c
-------------------------------------------------------------------------------
*/
int		printexit_perror(t_game *game, char *error);
void	freefreefree(t_game *game, char *line);

/*
-------------------------------------------------------------------------------
map.c
-------------------------------------------------------------------------------
*/
void	open_and_read_map(char *map, t_game *game);
void	put_txturs_in_map(char *map, t_game *game, int *countnormmap);
int		check_floor_and_ceiling(char *line, t_game *game);

/*
-------------------------------------------------------------------------------
map_screen.c
-------------------------------------------------------------------------------
*/
void	calcul_ray(t_game *game, int x);
void	calcul_sidedist(t_game *game);
void	calcul_wallhit_wallside(t_game *game);
void	calcul_textures(t_game *game);
void	print_textures_with_side(t_game *game, int x);

/*
-------------------------------------------------------------------------------
images.c
-------------------------------------------------------------------------------
*/
int		*load_img_textures(char *mapxpm, int i, t_game *game);
int		put_img_textures(char *mapxpm, int i, t_game *game, int *countnormmap);
int		put_map_screen(t_game *game);
void	init_win(t_game *game);
void	init_win_more(t_game *game);

/*
-------------------------------------------------------------------------------
mapping.c
-------------------------------------------------------------------------------
*/
char	**ft_mapping(char *str, char **map);
char	**resize_endofmap(t_game *game);
char	**resize_map(t_game *game, char *str);
int		comp_and_put(char *map, t_game *game, \
int *countnormmap, char **line);

/*
-------------------------------------------------------------------------------
utils.c
-------------------------------------------------------------------------------
*/
int		ft_sizingtab(char **str);
int		ft_strlengh(char *str);
int		check_autour(t_game *game, int y, int x);
int		check_xpm(const char *s1, const char *s2, size_t n);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		ft_strcmp(const char *s1, const char *s2);

/*
-------------------------------------------------------------------------------
color.c
-------------------------------------------------------------------------------
*/
int		floor_ceiling_color(char *line, t_game *game, \
char *str, int *countnormmap);

/*
-------------------------------------------------------------------------------
color_screen.c
-------------------------------------------------------------------------------
*/
int		ft_atoi_color(char *str);
void	put_frgb_screen(t_game *game);
void	put_crgb_screen(t_game *game);
int		test_ray_board(t_game *game);

/*
-------------------------------------------------------------------------------
free.c
-------------------------------------------------------------------------------
*/
void	free_all(t_game *game);
void	destroy_images(t_game *game);
void	ft_free_mapping(char **str);
void	ft_exit_close(t_game *game);

/*
-------------------------------------------------------------------------------
check.c
-------------------------------------------------------------------------------
*/
void	check_txtursorcolors_are_ok(t_game *game);
void	check_files_are_ok(int ac, char **av);
void	check_maps_are_ok(t_game *game);

/*
-------------------------------------------------------------------------------
checkutils.c
-------------------------------------------------------------------------------
*/
int		countwall(char *str);
int		countspace(char *str);
void	check_wfpnswe(t_game *game);

/*
-------------------------------------------------------------------------------
map_checker.c
-------------------------------------------------------------------------------
*/
void	check_maps_are_ok_bis(t_game *game);
int		open_and_readmapbis(char **line, t_game *game, \
int in_map, int countnormmap);

/*
-------------------------------------------------------------------------------
game.c
-------------------------------------------------------------------------------
*/
void	start_game(t_game *game);
void	init_ray(t_game *game);

/*
-------------------------------------------------------------------------------
keys.c
-------------------------------------------------------------------------------
*/
int		key_press(int key, t_game *game);
void	check_keyrotate(int key, t_game *game);
void	check_keydirection(int key, t_game *game);

#endif
