/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:33:20 by sbalesme          #+#    #+#             */
/*   Updated: 2022/10/27 09:06:36 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_textures(t_game *game)
{
	game->tex.e_start = NULL;
	game->tex.n_start = NULL;
	game->tex.s_start = NULL;
	game->tex.w_start = NULL;
}

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
	game->fd = -1;
	game->num_imgs_text = 4;
	init_textures(game);
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
