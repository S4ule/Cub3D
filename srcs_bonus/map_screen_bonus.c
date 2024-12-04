/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:34:43 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 18:13:12 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*put cub3D textures in screen with addr and drawing rayon*/
void	print_textures_with_side(t_game *game, int x)
{
	int		y;
	int		color;

	y = game->ray.drawstart;
	while (y < game->ray.drawend)
	{
		game->tex_y = (int)game->tex_pos & (game->img_y - 1);
		game->tex_pos += game->step;
		color = 0;
		if (game->ray.hit == 1)
			color = color_ray(game);
		else if (game->ray.hit == 2 || game->ray.hit == 4)
			color = game->imgs_text[4][game->img_y * game->tex_y + game->tex_x];
		else if (game->ray.hit == 3)
			color = game->imgs_text[5][game->img_y * game->tex_y + game->tex_x];
		else if (game->ray.hit == 5)
			color = game->imgs_text[6][game->img_y * game->tex_y + game->tex_x];
		game->screen_img_addr[y * WIDTHW + x] = color;
		y++;
	}
}

/*calcul lineheight for raycasting and textures position*/
void	calcul_textures(t_game *game)
{
	game->ray.lineheight = (int)(HEIGHTW / game->ray.perpwalldist);
	game->ray.drawstart = -game->ray.lineheight / 2 + HEIGHTW / 2;
	if (game->ray.drawstart < 0)
		game->ray.drawstart = 0;
	game->ray.drawend = game->ray.lineheight / 2 + HEIGHTW / 2;
	if (game->ray.drawend >= HEIGHTW)
		game->ray.drawend = HEIGHTW - 1;
	if (game->ray.side == 0)
		game->ray.wall_x = game->ray.posy + game->ray.perpwalldist \
			* game->ray.raydiry;
	else
		game->ray.wall_x = game->ray.posx + game->ray.perpwalldist \
			* game->ray.raydirx;
	game->ray.wall_x -= floor(game->ray.wall_x);
	game->tex_x = (int)(game->ray.wall_x * (double)game->img_x);
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		game->tex_x = game->img_x - game->tex_x - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		game->tex_x = game->img_x - game->tex_x - 1;
	game->step = 1.0 * game->img_y / game->ray.lineheight;
	game->tex_pos = (game->ray.drawstart - HEIGHTW / 2 \
		+ game->ray.lineheight / 2) * game->step;
}

/*calcul distance between 2 intersection points*/
void	calcul_wallhit_wallside(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedistx < game->ray.sidedisty)
		{
			game->ray.sidedistx += game->ray.deltadistx;
			game->ray.mapx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedisty += game->ray.deltadisty;
			game->ray.mapy += game->ray.stepy;
			game->ray.side = 1;
		}
		game->ray.hit = ft_hit(game);
	}
	if (game->ray.side == 0)
		game->ray.perpwalldist = (game->ray.mapx - game->ray.posx \
			+ (1 - game->ray.stepx) / 2) / game->ray.raydirx;
	else
		game->ray.perpwalldist = (game->ray.mapy - game->ray.posy \
			+ (1 - game->ray.stepy) / 2) / game->ray.raydiry;
}

/*calcul distance of side wall with rayon distance*/
void	calcul_sidedist(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.stepx = -1;
		game->ray.sidedistx = (game->ray.posx - game->ray.mapx) \
		* game->ray.deltadistx;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0 \
			- game->ray.posx) * game->ray.deltadistx;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.stepy = -1;
		game->ray.sidedisty = (game->ray.posy \
			- game->ray.mapy) * game->ray.deltadisty;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0 \
			- game->ray.posy) * game->ray.deltadisty;
	}
}

/*starting rayon for raycasting*/
void	calcul_ray(t_game *game, int x)
{
	double	eyes_x;

	eyes_x = 2 * x / (double)WIDTHW - 1;
	game->ray.raydirx = game->ray.dirx + game->ray.planx * eyes_x;
	game->ray.raydiry = game->ray.diry + game->ray.plany * eyes_x;
	game->ray.mapx = (int)game->ray.posx;
	game->ray.mapy = (int)game->ray.posy;
	game->ray.deltadistx = fabs(1 / game->ray.raydirx);
	game->ray.deltadisty = fabs(1 / game->ray.raydiry);
	game->ray.hit = 0;
}
