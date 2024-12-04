/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:33:17 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/15 06:18:37 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

//changer la value du malloc (ici 5) par le nombre d'images.
int	put_img_textures(char *mapxpm, int i, t_game *game, int *countnormmap)
{
	int	j;

	if (game->imgs == NULL)
	{
		game->imgs = (char **)malloc(sizeof(char *) * \
			(game->num_imgs_text + 1));
		j = 0;
		while (j <= game->num_imgs_text)
			game->imgs[j++] = NULL;
	}
	if (!game->imgs)
		return (1);
	(*countnormmap) += 1;
	game->imgs[i] = ft_strdup(mapxpm);
	return (0);
}

/*load image texture with mlx depend of map rules*/
int	*load_img_textures(char *mapxpm, int i, t_game *game)
{
	void	*img_ptr;
	int		*tmp;

	tmp = NULL;
	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, mapxpm, &(game->img_x), \
	&(game->img_y));
	if (img_ptr == NULL || !mapxpm || check_xpm(mapxpm, ".xpm", 4))
		printexit_perror(game, "OUTMAP");
	if (i == 0)
		game->tex.n_start = img_ptr;
	else if (i == 1)
		game->tex.s_start = img_ptr;
	else if (i == 2)
		game->tex.w_start = img_ptr;
	else if (i == 3)
		game->tex.e_start = img_ptr;
	else if (i == 4)
		game->tex.p_start = img_ptr;
	else if (i == 5)
		game->tex.o_start = img_ptr;
	else if (i == 6)
		game->tex.d_start = img_ptr;
	tmp = (int *)mlx_get_data_addr(img_ptr, &game->bpp, &game->line_len, \
	&game->endian);
	return (tmp);
}

/*print map2d in cub3d with raycasting method*/
int	put_map_screen(t_game *game)
{
	int		x;

	x = 0;
	while (x < WIDTHW)
	{
		calcul_ray(game, x);
		calcul_sidedist(game);
		calcul_wallhit_wallside(game);
		calcul_textures(game);
		print_textures_with_side(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->screen_img, 0, 0);
	put_homer(game);
	life(game);
	rescue(game);
	check_options(game);
	return (0);
}

/*init mlx screen*/
void	init_win_more(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		printexit_perror(game, "MLX");
	game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTHW, HEIGHTW, "cub3D");
	if (game->mlx_win == NULL)
	{
		free(game->mlx_win);
		printexit_perror(game, "MLX");
	}
}

/*init mlx screen ,mlx textures and mlx address for textures*/
void	init_win(t_game *game)
{
	int	i;

	init_win_more(game);
	game->screen_img = mlx_new_image(game->mlx_ptr, WIDTHW, HEIGHTW);
	game->screen_img_addr = (int *)mlx_get_data_addr(game->screen_img, \
	&game->bpp, &game->line_len, &game->endian);
	init_homer(game);
	init_homerhulk(game);
	init_score(game);
	if (game->imgs_text == NULL)
	{
		game->imgs_text = (int **)malloc(sizeof(int *) * 8);
		i = 0;
		while (i <= 7)
			game->imgs_text[i++] = NULL;
	}
	if (!game->imgs_text)
		printexit_perror(game, "OUTMAP");
	i = 0;
	while (i <= 6)
	{
		game->imgs_text[i] = load_img_textures(game->imgs[i], i, game);
		i++;
	}
	check_txtursorcolors_are_ok(game);
}
