/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:29:33 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 18:05:36 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

int	color_ray(t_game *game)
{
	int	color;

	color = 0;
	if (game->ray.raydiry < 0 && game->ray.side == 1)
		color = game->imgs_text[1][game->img_y * game->tex_y + game->tex_x];
	else if (game->ray.raydirx < 0 && game->ray.side == 0)
		color = game->imgs_text[3][game->img_y * game->tex_y + game->tex_x];
	else if (game->ray.raydiry > 0 && game->ray.side == 1)
		color = game->imgs_text[0][game->img_y * game->tex_y + game->tex_x];
	else if (game->ray.raydirx > 0 && game->ray.side == 0)
		color = game->imgs_text[2][game->img_y * game->tex_y + game->tex_x];
	return (color);
}

int	ft_hit(t_game *game)
{
	if (game->mapping[game->ray.mapy][game->ray.mapx] == '1')
		return (1);
	else if (game->mapping[game->ray.mapy][game->ray.mapx] == '2')
		return (2);
	else if (game->mapping[game->ray.mapy][game->ray.mapx] == '3')
		return (3);
	else if (game->mapping[game->ray.mapy][game->ray.mapx] == '4')
		return (4);
	else if (game->mapping[game->ray.mapy][game->ray.mapx] == '5')
		return (5);
	return (0);
}
