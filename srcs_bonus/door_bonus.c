/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:56:51 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 16:35:14 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	check_aroundoor(t_game *game, int y, int x)
{
	if ((game->mapping[y - 1][x] && game->mapping[y - 1][x] == '2' \
	&& game->ray.diry < 0) || (game->mapping[y + 1][x] && \
	game->mapping[y + 1][x] == '2' && game->ray.diry > 0))
		return (1);
	if ((game->mapping[y][x - 1] && game->mapping[y][x - 1] == '2' \
	&& game->ray.dirx < 0) || (game->mapping[y][x + 1] && \
	game->mapping[y][x + 1] == '2' && game->ray.dirx > 0))
		return (1);
	if ((game->mapping[y - 1][x] && game->mapping[y - 1][x] == '3' \
	&& game->ray.diry < 0) || (game->mapping[y + 1][x] && \
	game->mapping[y + 1][x] == '3' && game->ray.diry > 0))
		return (2);
	if ((game->mapping[y][x - 1] && game->mapping[y][x - 1] == '3' \
	&& game->ray.dirx < 0) || (game->mapping[y][x + 1] && \
	game->mapping[y][x + 1] == '3' && game->ray.dirx > 0))
		return (2);
	return (0);
}

int	check_open(t_game *game)
{
	if (check_aroundoor(game, game->ray.posy, game->ray.posx) == 1)
		return (1);
	else if (check_aroundoor(game, game->ray.posy, game->ray.posx) == 2)
		return (2);
	return (0);
}

static void	new_map(t_game *game, int y, int x, char c)
{
	if (c == 'o')
	{
		game->mapping[y][x] = '3';
		rand_door(game);
	}
	if (c == 'c')
		game->mapping[y][x] = '4';
}

void	open_door(t_game *game)
{
	int	x;
	int	y;

	x = game->ray.posx;
	y = game->ray.posy;
	if (game->mapping[y - 1][x] && game->mapping[y - 1][x] == '2' \
	&& game->ray.diry < 0)
		new_map(game, y - 1, x, 'o');
	if (game->mapping[y][x + 1] && game->mapping[y + 1][x] == '2' \
	&& game->ray.diry > 0)
		new_map(game, y + 1, x, 'o');
	if (game->mapping[y][x - 1] && game->mapping[y][x - 1] == '2' \
	&& game->ray.dirx < 0)
		new_map(game, y, x - 1, 'o');
	if (game->mapping[y][x + 1] && game->mapping[y][x + 1] == '2' \
	&& game->ray.dirx > 0)
		new_map(game, y, x + 1, 'o');
}

void	close_door(t_game *game)
{
	int	x;
	int	y;

	x = game->ray.posx;
	y = game->ray.posy;
	if (game->mapping[y - 1][x] && game->mapping[y - 1][x] == '3' \
	&& game->ray.diry < 0)
		new_map(game, y - 1, x, 'c');
	if (game->mapping[y][x + 1] && game->mapping[y + 1][x] == '3' \
	&& game->ray.diry > 0)
		new_map(game, y + 1, x, 'c');
	if (game->mapping[y][x - 1] && game->mapping[y][x - 1] == '3' \
	&& game->ray.dirx < 0)
		new_map(game, y, x - 1, 'c');
	if (game->mapping[y][x + 1] && game->mapping[y][x + 1] == '3' \
	&& game->ray.dirx > 0)
		new_map(game, y, x + 1, 'c');
}
