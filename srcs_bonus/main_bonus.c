/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:34:15 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 09:49:32 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_game(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->mapping = NULL;
	game->mlx_ptr = NULL;
	game->mlx_win = NULL;
	game->tex.ceiling = -1;
	game->tex.floor = -1;
	game->player.dir = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->player.move_speed = 0.35;
	game->player.rot_speed = 0.35;
	game->imgs = NULL;
	game->imgs_text = NULL;
	game->screen_img_addr = NULL;
	game->screen_img = NULL;
	game->image.img = NULL;
	game->fd = -1;
	game->num_imgs_text = 7;
	init_textures(game);
	init_data(game);
}

static int	check_accueil(int key, t_game *game)
{
	(void)game;
	if (key == B)
		exit(0);
	else if (key == A)
		start_game(game);
	return (0);
}

void	win_game(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.ooo, 1070, 72);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.victory, 450, 400);
	printf("DO'H YOU WIN !!!");
}

void	init_accueil(t_game *game)
{
	init_win_more(game);
	game->image.img = mlx_xpm_file_to_image(game->mlx_ptr, START, \
	&(game->image.img_w), &(game->image.img_h));
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.img, 40, 30);
	game->image.imgb = mlx_xpm_file_to_image(game->mlx_ptr, STARTB, \
	&(game->image.img_w), &(game->image.img_h));
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.imgb, 40, 502);
	game->image.imgbb = mlx_xpm_file_to_image(game->mlx_ptr, STARTBB, \
	&(game->image.img_w), &(game->image.img_h));
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.imgbb, 650, 30);
	game->image.imgbbb = mlx_xpm_file_to_image(game->mlx_ptr, STARTBBB, \
	&(game->image.img_w), &(game->image.img_h));
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.imgbbb, 650, 504);
	mlx_destroy_image(game->mlx_ptr, game->image.img);
	mlx_destroy_image(game->mlx_ptr, game->image.imgb);
	mlx_destroy_image(game->mlx_ptr, game->image.imgbb);
	mlx_destroy_image(game->mlx_ptr, game->image.imgbbb);
	mlx_hook(game->mlx_win, 2, 1L << 0, check_accueil, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**newmap;

	check_files_are_ok(ac, av);
	init_game(&game);
	open_and_read_map(av[1], &game);
	newmap = resize_endofmap(&game);
	ft_free_mapping(game.mapping);
	game.mapping = newmap;
	check_maps_are_ok(&game);
	start_game(&game);
	ft_free_mapping(game.mapping);
	free(game.mapping);
	return (0);
}
