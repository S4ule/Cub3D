/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:09:52 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 07:49:52 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	life(t_game *game)
{
	if (game->life == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.threelif, 950, 10);
	if (game->life == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.twolif, 950, 10);
	if (game->life == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.onelif, 950, 10);
}

void	rescue(t_game *game)
{
	if (game->nelson == 0 && game->burns == 0 && game->krusty == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.zzz, 1070, 72);
	if (game->nelson == 1 && game->burns == 0 && game->krusty == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.ozz, 1070, 72);
	if (game->nelson == 1 && game->burns == 0 && game->krusty == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.ozo, 1070, 72);
	if (game->nelson == 1 && game->burns == 1 && game->krusty == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.ooz, 1070, 72);
	if (game->nelson == 1 && game->burns == 1 && game->krusty == 1)
		win_game(game);
	if (game->nelson == 0 && game->burns == 1 && game->krusty == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.zoz, 1070, 72);
	if (game->nelson == 0 && game->burns == 1 && game->krusty == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.zoo, 1070, 72);
	if (game->nelson == 0 && game->burns == 0 && game->krusty == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.zzo, 1070, 72);
}

int	rand_door(t_game *game)
{
	int	nombre;

	(void)game;
	srand(time(NULL));
	nombre = (rand() % (MAX + 1 - MIN)) + MIN;
	if (nombre == 1 && game->nelson == 0)
		game->nelson = 1;
	else if (nombre == 2 && game->burns == 0)
		game->burns = 1;
	else if (nombre == 3 && game->krusty == 0)
		game->krusty = 1;
	else
		space_invaders(game);
	return (0);
}

void	space_invaders(t_game *game)
{
	game->life--;
	if (game->life == 0)
	{
		mlx_string_put(game->mlx_ptr, game->mlx_win, 500, 500, \
		YELLOW, "DO'H YOU LOOSE !!!\n");
		printf("DO'H YOU LOOSE !!!");
		ft_exit_close(game);
	}
}

void	check_hulk(t_game *game)
{
	int	x;
	int	y;

	x = game->ray.posx;
	y = game->ray.posy;
	if (game->mapping[y][x] == '5')
	{
		game->life = 3;
		game->hulk = 1;
		game->mapping[y][x] = '0';
	}
}
