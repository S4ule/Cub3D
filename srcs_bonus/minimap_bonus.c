/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:32:08 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 09:51:03 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

long	ft_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

static int	get_color(char c)
{
	int	color;

	if (c == '0' || c == '5')
		color = GREY_FLOOR;
	else if (c == '1' || c == '4')
		color = BLACK;
	else if (c == '2')
		color = RED;
	else if (c == '3')
		color = GREEN;
	else if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		color = GREY_FLOOR;
	else
		color = 0;
	return (color);
}

void	draw_pxlarge(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx_ptr, game->mlx_win, \
			(y * 10) + i + 1, (x * 10) + j + 1, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = -1;
		while (j < 5)
		{
			mlx_pixel_put(game->mlx_ptr, game->mlx_win, \
			(game->ray.posx * 10) + i + 1, (game->ray.posy * 10) + j + 1, \
			YELLOW);
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_game *game)
{
	int	line;
	int	col;
	int	i;
	int	j;
	int	color;

	line = game->height;
	col = game->width;
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			color = get_color(game->mapping[i][j]);
			if (color)
				draw_pxlarge(game, i, j, color);
			j++;
		}
		i++;
	}
	draw_player(game);
	return (0);
}
