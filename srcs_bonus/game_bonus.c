/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:32:47 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 11:12:57 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*init the rayon position with the player position*/
static void	init_ray_more(t_game *game, int number)
{
	if (number == 4)
	{
		game->ray.planx = -0.66;
		game->ray.diry = 1;
	}
	else if (number == 5)
	{
		game->ray.plany = -0.66;
		game->ray.dirx = -1;
	}
}

/*init the rayon position with the player position*/
static void	init_ray_start(t_game *game, int number)
{
	game->ray.posx = game->player.x + 0.5;
	game->ray.posy = game->player.y + 0.5;
	if (number == 2 || number == 4)
	{
		game->ray.dirx = 0;
		game->ray.diry = -1;
		game->ray.planx = 0.66;
		game->ray.plany = 0;
		init_ray_more(game, number);
	}
	else
	{
		game->ray.dirx = 1;
		game->ray.diry = 0;
		game->ray.planx = 0;
		game->ray.plany = 0.66;
		init_ray_more(game, number);
	}
}

/*init the rayon position with the player position*/
void	init_ray(t_game *game)
{
	if (game->player.dir == 'N')
		init_ray_start(game, 2);
	else if (game->player.dir == 'E')
		init_ray_start(game, 3);
	else if (game->player.dir == 'S')
		init_ray_start(game, 4);
	else if (game->player.dir == 'W')
		init_ray_start(game, 5);
}

/*engine of cub3D*/
void	start_game(t_game *game)
{
	init_win(game);
	init_ray(game);
	put_crgb_screen(game);
	put_frgb_screen(game);
	put_map_screen(game);
	mlx_hook(game->mlx_win, 6, 1L << 6, mouse_hook, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx_win, 17, 0, (void *)ft_exit_close, game);
	mlx_loop(game->mlx_ptr);
	return ;
}
