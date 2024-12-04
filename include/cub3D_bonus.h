/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:25:25 by sbalesme          #+#    #+#             */
/*   Updated: 2022/11/14 12:48:18 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <sys/time.h>

# ifndef WIDTHW
#  define WIDTHW 1280
# endif

# ifndef HEIGHTW
#  define HEIGHTW 1024
# endif

# define MAX 5
# define MIN 1

/*
-------------------------------------------------------------------------------
textures cub3D
-------------------------------------------------------------------------------
*/
# define START "./texturesbonus/start3.xpm"
# define STARTB "./texturesbonus/start5.xpm"
# define STARTBB "./texturesbonus/start4.xpm"
# define STARTBBB "./texturesbonus/start6.xpm"
# define HBRAS "./texturesbonus/homerbras.xpm"
# define HBRASD "./texturesbonus/homerbrasd.xpm"
# define HBRASG "./texturesbonus/homerbrasg.xpm"
# define HBRASBAS "./texturesbonus/homerbrasbas.xpm"
# define HDOS "./texturesbonus/homerdos.xpm"
# define HDROITE "./texturesbonus/homerdroite.xpm"
# define HGAUCHE "./texturesbonus/homergauche.xpm"
# define HFACE "./texturesbonus/homerface.xpm"
# define HJAMBES "./texturesbonus/homerjambes.xpm"
# define HJAMBESF "./texturesbonus/homerjambesface.xpm"
# define EPAULES "./texturesbonus/epaules.xpm"
# define EPAULESF "./texturesbonus/epaulesface.xpm"
# define ZZZ "./texturesbonus/000.xpm"
# define ZZO "./texturesbonus/001.xpm"
# define ZOZ "./texturesbonus/010.xpm"
# define ZOO "./texturesbonus/011.xpm"
# define OZZ "./texturesbonus/100.xpm"
# define OZO "./texturesbonus/101.xpm"
# define OOZ "./texturesbonus/110.xpm"
# define OOO "./texturesbonus/111.xpm"
# define ONELIF "./texturesbonus/regleone.xpm"
# define TWOLIF "./texturesbonus/regletwo.xpm"
# define THREELIF "./texturesbonus/reglethree.xpm"
# define HBRASH "./texturesbonus/homerbrash.xpm"
# define HBRASDH "./texturesbonus/homerbrasdh.xpm"
# define HBRASGH "./texturesbonus/homerbrasgh.xpm"
# define HBRASBASH "./texturesbonus/homerbrasbash.xpm"
# define HDOSH "./texturesbonus/homerdosh.xpm"
# define HDROITEH "./texturesbonus/homerdroiteh.xpm"
# define HGAUCHEH "./texturesbonus/homergaucheh.xpm"
# define HFACEH "./texturesbonus/homerfaceh.xpm"
# define HJAMBESH "./texturesbonus/homerjambesh.xpm"
# define HJAMBESFH "./texturesbonus/homerjambesfaceh.xpm"
# define EPAULESH "./texturesbonus/epaulesh.xpm"
# define EPAULESFH "./texturesbonus/epaulesfaceh.xpm"
# define VICTORY "./texturesbonus/victory.xpm"

/*
-------------------------------------------------------------------------------
colors cub3D
-------------------------------------------------------------------------------
*/
# define SKYBLUE 0x7fffff
# define GREEN 0xff00
# define D_BLUE 0x555
# define D_RED 0x7f0000
# define RED 0xff0000
# define GREY 0x333333
# define ORANGE 0xFF6900
# define GREY_FLOOR 0x424242
# define YELLOW 0xFFED2D
# define BLACK 0x0B0404

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
# define B 98
# define M 109
# define C 99
# define F 102
# define E 101
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
	int			sidebis;
}	t_ray;

typedef struct s_img
{
	void	*img;
	void	*imgb;
	void	*imgbb;
	void	*imgbbb;
	void	*hbras;
	void	*hdos;
	void	*hdroite;
	void	*hgauche;
	void	*hface;
	void	*hjambes;
	void	*hjambesf;
	void	*hbrasg;
	void	*hbrasd;
	void	*hbrasbas;
	void	*epaules;
	void	*epaulesface;
	void	*zzz;
	void	*zzo;
	void	*zoz;
	void	*zoo;
	void	*ozz;
	void	*ozo;
	void	*ooz;
	void	*ooo;
	void	*onelif;
	void	*twolif;
	void	*threelif;
	char	*img_str;
	void	*hbrash;
	void	*hdosh;
	void	*hdroiteh;
	void	*hgaucheh;
	void	*hfaceh;
	void	*hjambesh;
	void	*hjambesfh;
	void	*hbrasgh;
	void	*hbrasdh;
	void	*hbrasbash;
	void	*epaulesh;
	void	*epaulesfaceh;
	void	*victory;
	int		bits;
	int		size_line;
	int		endian;
	int		img_h;
	int		img_w;
	char	*addr;
}	t_img;

typedef struct s_tex
{
	void	*n_start;
	void	*s_start;
	void	*w_start;
	void	*e_start;
	void	*p_start;
	void	*o_start;
	void	*d_start;
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
	t_img		image;
	int			mouse_on;
	float		clicking;
	int			resolx;
	int			resoly;
	int			fps;
	int			minimap;
	int			homer;
	int			animdroite;
	int			animgauche;
	int			animdos;
	int			animface;
	int			life;
	int			burns;
	int			nelson;
	int			krusty;
	int			hulk;
}	t_game;

/*
-------------------------------------------------------------------------------
main_bonus.c
-------------------------------------------------------------------------------
*/
int		main(int ac, char **av);
void	init_accueil(t_game *game);
void	win_game(t_game *game);

/*
-------------------------------------------------------------------------------
init_bonus.c
-------------------------------------------------------------------------------
*/
void	init_data(t_game *game);
void	init_textures(t_game *game);
void	init_score(t_game *game);
void	init_texturesbis(t_game *game);

/*
-------------------------------------------------------------------------------
error_bonus.c
-------------------------------------------------------------------------------
*/
int		printexit_perror(t_game *game, char *error);
void	destroy_images(t_game *game);
void	destroy_imagesbis(t_game *game);
void	destroy_imagesbisbis(t_game *game);

/*
-------------------------------------------------------------------------------
map_bonus.c
-------------------------------------------------------------------------------
*/
void	open_and_read_map(char *map, t_game *game);
void	put_txturs_in_map(char *map, t_game *game, int *countnormmap);
int		check_floor_and_ceiling(char *line, t_game *game);

/*
-------------------------------------------------------------------------------
map_screen_bonus.c
-------------------------------------------------------------------------------
*/
void	calcul_ray(t_game *game, int x);
void	calcul_sidedist(t_game *game);
void	calcul_wallhit_wallside(t_game *game);
void	calcul_textures(t_game *game);
void	print_textures_with_side(t_game *game, int x);

/*
-------------------------------------------------------------------------------
images_bonus.c
-------------------------------------------------------------------------------
*/
int		*load_img_textures(char *mapxpm, int i, t_game *game);
int		put_img_textures(char *mapxpm, int i, t_game *game, int *countnormmap);
int		put_map_screen(t_game *game);
void	init_win(t_game *game);
void	init_win_more(t_game *game);

/*
-------------------------------------------------------------------------------
mapping_bonus.c
-------------------------------------------------------------------------------
*/
char	**ft_mapping(char *str, char **map);
char	**resize_endofmap(t_game *game);
char	**resize_map(t_game *game, char *str);
int		comp_and_put(char *map, t_game *game, \
int *countnormmap, char **line);

/*
-------------------------------------------------------------------------------
utils_bonus.c
-------------------------------------------------------------------------------
*/
int		ft_sizingtab(char **str);
int		ft_strlengh(char *str);
int		check_autour(t_game *game, int y, int x);
int		check_xpm(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

/*
-------------------------------------------------------------------------------
color_bonus.c
-------------------------------------------------------------------------------
*/
int		floor_ceiling_color(char *line, t_game *game, \
char *str, int *countnormmap);

/*
-------------------------------------------------------------------------------
color_screen_bonus.c
-------------------------------------------------------------------------------
*/
int		ft_atoi_color(char *str);
void	put_frgb_screen(t_game *game);
void	put_crgb_screen(t_game *game);
int		color_ray(t_game *game);
int		ft_hit(t_game *game);

/*
-------------------------------------------------------------------------------
free_bonus.c
-------------------------------------------------------------------------------
*/
void	free_all(t_game *game);
void	ft_free_mapping(char **str);
void	ft_exit_close(t_game *game);
void	destroy_imagesbisbisbis(t_game *game);

/*
-------------------------------------------------------------------------------
check_bonus.c
-------------------------------------------------------------------------------
*/
void	check_txtursorcolors_are_ok(t_game *game);
void	check_files_are_ok(int ac, char **av);
void	check_maps_are_ok(t_game *game);

/*
-------------------------------------------------------------------------------
checkutils_bonus.c
-------------------------------------------------------------------------------
*/
int		countwall(char *str);
int		countspace(char *str);
void	check_wfpnswe(t_game *game);
void	freefree(t_game *game, char **line, char *map);

/*
-------------------------------------------------------------------------------
map_checker_bonus.c
-------------------------------------------------------------------------------
*/
void	check_maps_are_ok_bis(t_game *game);
int		open_and_readmapbis(char **line, t_game *game, \
int in_map, int countnormmap);

/*
-------------------------------------------------------------------------------
game_bonus.c
-------------------------------------------------------------------------------
*/
void	start_game(t_game *game);
void	init_ray(t_game *game);

/*
-------------------------------------------------------------------------------
keys_bonus.c
-------------------------------------------------------------------------------
*/
int		key_press(int key, t_game *game);
void	check_keyrotate(int key, t_game *game);
void	check_keydirection(int key, t_game *game);
void	check_keydirectionbis(int key, t_game *game);

/*
-------------------------------------------------------------------------------
minimap_bonus.c
-------------------------------------------------------------------------------
*/
void	draw_pxlarge(t_game *game, int x, int y, int color);
int		draw_minimap(t_game *game);
void	draw_player(t_game *game);
long	ft_time(void);
/*
-------------------------------------------------------------------------------
mouse_bonus.c
-------------------------------------------------------------------------------
*/
int		mouse_hook(int x, int y, t_game *game);
void	check_mouse(int key, t_game *game);
void	check_options(t_game *game);
void	disp_fps(t_game *game, char *str);
void	fps_count(t_game *game);

/*
-------------------------------------------------------------------------------
homer_bonus.c
-------------------------------------------------------------------------------
*/
void	init_homer(t_game *game);
void	put_homer(t_game *game);
void	put_homerdos(t_game *game);
void	put_homerd(t_game *game);
void	put_homerg(t_game *game);

/*
-------------------------------------------------------------------------------
homerbis_bonus.c
-------------------------------------------------------------------------------
*/
void	put_homerdd(t_game *game);
void	put_homergg(t_game *game);
void	put_homerface(t_game *game);

/*
-------------------------------------------------------------------------------
hulk_bonus.c
-------------------------------------------------------------------------------
*/
void	init_homerhulk(t_game *game);
void	put_homerhulk(t_game *game);
void	put_homerdoshulk(t_game *game);
void	put_homerdhulk(t_game *game);
void	put_homerghulk(t_game *game);

/*
-------------------------------------------------------------------------------
hulkbis_bonus.c
-------------------------------------------------------------------------------
*/
void	put_homerddhulk(t_game *game);
void	put_homergghulk(t_game *game);
void	put_homerfacehulk(t_game *game);
void	freefreefree(t_game *game, char *line);

/*
-------------------------------------------------------------------------------
door_bonus.c
-------------------------------------------------------------------------------
*/
int		check_aroundoor(t_game *game, int y, int x);
int		check_open(t_game *game);
void	open_door(t_game *game);
void	close_door(t_game *game);

/*
-------------------------------------------------------------------------------
score_bonus.c
-------------------------------------------------------------------------------
*/
void	life(t_game *game);
void	rescue(t_game *game);
int		rand_door(t_game *game);
void	space_invaders(t_game *game);
void	check_hulk(t_game *game);

#endif
