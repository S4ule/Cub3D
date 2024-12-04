/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:07:59 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 10:29:13 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_homer(t_game *game)
{
	game->image.hjambesf = mlx_xpm_file_to_image(game->mlx_ptr, HJAMBESF, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hface = mlx_xpm_file_to_image(game->mlx_ptr, HFACE, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbras = mlx_xpm_file_to_image(game->mlx_ptr, HBRAS, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasg = mlx_xpm_file_to_image(game->mlx_ptr, HBRASG, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasd = mlx_xpm_file_to_image(game->mlx_ptr, HBRASD, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasbas = mlx_xpm_file_to_image(game->mlx_ptr, HBRASBAS, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hjambes = mlx_xpm_file_to_image(game->mlx_ptr, HJAMBES, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hdos = mlx_xpm_file_to_image(game->mlx_ptr, HDOS, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hdroite = mlx_xpm_file_to_image(game->mlx_ptr, HDROITE, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hgauche = mlx_xpm_file_to_image(game->mlx_ptr, HGAUCHE, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.epaules = mlx_xpm_file_to_image(game->mlx_ptr, EPAULES, \
	&(game->image.img_w), &(game->image.img_h));
}

void	put_homer(t_game *game)
{
	if (game->hulk == 0)
	{
		if (game->homer == 1)
			put_homerface(game);
		else if (game->homer == 2)
			put_homerdos(game);
		else if (game->homer == 3)
			put_homerg(game);
		else if (game->homer == 4)
			put_homerd(game);
		else if (game->homer == 5)
			put_homergg(game);
		else if (game->homer == 6)
			put_homerdd(game);
	}
	else if (game->hulk == 1)
		put_homerhulk(game);
}

void	put_homerdos(t_game *game)
{
	if (game->animdos % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdos, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaules, 703, 860);
		game->animdos++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdos, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaules, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 703, 860);
		game->animdos++;
	}
}

void	put_homerg(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hjambesf, 575, 850);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hface, 559, 691);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasg, 437, 860);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasbas, 703, 860);
}

void	put_homerd(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hjambesf, 575, 850);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hface, 559, 691);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasbas, 528, 860);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasd, 703, 860);
}
