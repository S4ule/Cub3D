/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:32:14 by sbalesme          #+#    #+#             */
/*   Updated: 2022/10/26 11:44:34 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*put ceiling color on screen pixel per pixel*/
void	put_crgb_screen(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTHW)
	{
		y = -1;
		while (++y < HEIGHTW / 2)
			game->screen_img_addr[y * WIDTHW + x] = game->tex.ceiling;
	}
}

/*put floor color on screen pixel per pixel*/
void	put_frgb_screen(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = HEIGHTW / 2;
	while (x < WIDTHW && y < HEIGHTW)
	{
		game->screen_img_addr[y * WIDTHW + x] = game->tex.floor;
		x++;
		if (x == WIDTHW)
		{
			y++;
			x = 0;
		}
	}
}

/*atoi adapted for detected color in cub3D*/
int	ft_atoi_color(char *str)
{
	long	res;

	if (*str == '\0')
		return (1);
	if (*str == '-')
		return (1);
	else if (*str == '+')
		str++;
	if (*str == '\0')
		return (1);
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 255)
			return (1);
		str++;
	}
	if (*str != '\0')
		return (1);
	return (0);
}

int	test_ray_board(t_game *game)
{
	if (game->ray.mapy < 0 || game->ray.mapy >= game->height || \
		game->ray.mapx < 0 || game->ray.mapx >= game->width)
		return (1);
	return (0);
}
