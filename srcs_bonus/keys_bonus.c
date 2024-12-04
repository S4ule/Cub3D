/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:33:47 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 13:21:18 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*check keyboard action and do something with*/
int	key_press(int key, t_game *game)
{
	check_mouse(key, game);
	check_keyrotate(key, game);
	check_keydirection(key, game);
	if (key == ESC)
		ft_exit_close(game);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	put_crgb_screen(game);
	put_frgb_screen(game);
	put_map_screen(game);
	return (0);
}

/*check keyboard action and do player rotation*/
void	check_keyrotate(int key, t_game *game)
{
	double	tmpdirx;
	double	tmplanx;
	double	rot;

	rot = game->player.rot_speed;
	if (key == ARROW_RIGHT)
	{
		game->homer = 4;
		tmpdirx = game->ray.dirx;
		tmplanx = game->ray.planx;
		game->ray.dirx = (tmpdirx * cos(rot)) - (game->ray.diry * sin(rot));
		game->ray.diry = (tmpdirx * sin(rot)) + (game->ray.diry * cos(rot));
		game->ray.planx = (tmplanx * cos(rot)) - (game->ray.plany * sin(rot));
		game->ray.plany = (tmplanx * sin(rot)) + (game->ray.plany * cos(rot));
	}
	else if (key == ARROW_LEFT)
	{
		game->homer = 3;
		tmpdirx = game->ray.dirx;
		tmplanx = game->ray.planx;
		game->ray.dirx = (tmpdirx * cos(-rot)) - (game->ray.diry * sin(-rot));
		game->ray.diry = (tmpdirx * sin(-rot)) + (game->ray.diry * cos(-rot));
		game->ray.planx = (tmplanx * cos(-rot)) - (game->ray.plany * sin(-rot));
		game->ray.plany = (tmplanx * sin(-rot)) + (game->ray.plany * cos(-rot));
	}
}

static int	check_collision(float x, float y, t_game *game)
{
	if (game->mapping[(int)y][(int)x] == '1' || \
	game->mapping[(int)y][(int)x] == '2' || \
	game->mapping[(int)y][(int)x] == '3' || \
	game->mapping[(int)y][(int)x] == '4')
		return (1);
	return (0);
}

void	check_keydirection(int key, t_game *game)
{
	if (key == W)
	{
		game->homer = 2;
		if (!check_collision(game->ray.posx + \
		game->ray.dirx * game->player.move_speed, game->ray.posy, game))
			game->ray.posx += game->ray.dirx * game->player.move_speed;
		if (!check_collision(game->ray.posx, game->ray.posy + \
		game->ray.diry * game->player.move_speed, game))
			game->ray.posy += game->ray.diry * game->player.move_speed;
	}
	else if (key == S)
	{
		game->homer = 1;
		if (!check_collision(game->ray.posx - \
		game->ray.dirx * game->player.move_speed, game->ray.posy, game))
			game->ray.posx -= game->ray.dirx * game->player.move_speed;
		if (!check_collision(game->ray.posx, game->ray.posy - \
		game->ray.diry * game->player.move_speed, game))
			game->ray.posy -= game->ray.diry * game->player.move_speed;
	}
	else if (key == A || key == D)
		check_keydirectionbis(key, game);
}

void	check_keydirectionbis(int key, t_game *game)
{
	if (key == A)
	{
		game->homer = 5;
		if (!check_collision(game->ray.posx + \
		game->ray.diry * game->player.move_speed, game->ray.posy, game))
			game->ray.posx += game->ray.diry * game->player.move_speed;
		if (!check_collision(game->ray.posx, game->ray.posy - \
		game->ray.dirx * game->player.move_speed, game))
			game->ray.posy -= game->ray.dirx * game->player.move_speed;
	}
	else if (key == D)
	{
		game->homer = 6;
		if (!check_collision(game->ray.posx - \
		game->ray.diry * game->player.move_speed, game->ray.posy, game))
			game->ray.posx -= game->ray.diry * game->player.move_speed;
		if (!check_collision(game->ray.posx, game->ray.posy + \
		game->ray.dirx * game->player.move_speed, game))
			game->ray.posy += game->ray.dirx * game->player.move_speed;
	}
}
