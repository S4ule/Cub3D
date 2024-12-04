/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:01:31 by sbalesme          #+#    #+#             */
/*   Updated: 2022/11/01 10:13:24 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*check keyboard action and do something with*/
int	key_press(int key, t_game *game)
{
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
		tmpdirx = game->ray.dirx;
		tmplanx = game->ray.planx;
		game->ray.dirx = (tmpdirx * cos(rot)) - (game->ray.diry * sin(rot));
		game->ray.diry = (tmpdirx * sin(rot)) + (game->ray.diry * cos(rot));
		game->ray.planx = (tmplanx * cos(rot)) - (game->ray.plany * sin(rot));
		game->ray.plany = (tmplanx * sin(rot)) + (game->ray.plany * cos(rot));
	}
	else if (key == ARROW_LEFT)
	{
		tmpdirx = game->ray.dirx;
		tmplanx = game->ray.planx;
		game->ray.dirx = (tmpdirx * cos(-rot)) - (game->ray.diry * sin(-rot));
		game->ray.diry = (tmpdirx * sin(-rot)) + (game->ray.diry * cos(-rot));
		game->ray.planx = (tmplanx * cos(-rot)) - (game->ray.plany * sin(-rot));
		game->ray.plany = (tmplanx * sin(-rot)) + (game->ray.plany * cos(-rot));
	}
}

/*Rotation vectorielle plane*/
// x' = x cos@ - y sin@
// y' = x sin@ + y cos@
// 180 degre (x,y) -> (-x,-y)
// 90 degre clockwise (x,y) -> (-x, y)
// 90 degre counterclockwise (x,y) -> (x,-y)

void	check_keydirection(int key, t_game *game)
{
	if (key == W)
	{
		game->ray.posx += game->ray.dirx * game->player.move_speed;
		game->ray.posy += game->ray.diry * game->player.move_speed;
	}
	else if (key == S)
	{
		game->ray.posx -= game->ray.dirx * game->player.move_speed;
		game->ray.posy -= game->ray.diry * game->player.move_speed;
	}
	else if (key == A)
	{
		game->ray.posx += game->ray.diry * game->player.move_speed;
		game->ray.posy -= game->ray.dirx * game->player.move_speed;
	}
	else if (key == D)
	{
		game->ray.posx -= game->ray.diry * game->player.move_speed;
		game->ray.posy += game->ray.dirx * game->player.move_speed;
	}
}
