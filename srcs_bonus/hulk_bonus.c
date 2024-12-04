/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hulk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:56:10 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 10:29:04 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_homerhulk(t_game *game)
{
	game->image.hjambesfh = mlx_xpm_file_to_image(game->mlx_ptr, HJAMBESFH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hfaceh = mlx_xpm_file_to_image(game->mlx_ptr, HFACEH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrash = mlx_xpm_file_to_image(game->mlx_ptr, HBRASH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasgh = mlx_xpm_file_to_image(game->mlx_ptr, HBRASGH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasdh = mlx_xpm_file_to_image(game->mlx_ptr, HBRASDH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hbrasbash = mlx_xpm_file_to_image(game->mlx_ptr, HBRASBASH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hjambesh = mlx_xpm_file_to_image(game->mlx_ptr, HJAMBESH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hdosh = mlx_xpm_file_to_image(game->mlx_ptr, HDOSH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hdroiteh = mlx_xpm_file_to_image(game->mlx_ptr, HDROITEH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.hgaucheh = mlx_xpm_file_to_image(game->mlx_ptr, HGAUCHEH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.epaulesh = mlx_xpm_file_to_image(game->mlx_ptr, EPAULESH, \
	&(game->image.img_w), &(game->image.img_h));
}

void	put_homerhulk(t_game *game)
{
	if (game->homer == 1)
		put_homerfacehulk(game);
	else if (game->homer == 2)
		put_homerdoshulk(game);
	else if (game->homer == 3)
		put_homerghulk(game);
	else if (game->homer == 4)
		put_homerdhulk(game);
	else if (game->homer == 5)
		put_homergghulk(game);
	else if (game->homer == 6)
		put_homerddhulk(game);
}

void	put_homerdoshulk(t_game *game)
{
	if (game->animdos % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdosh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesh, 703, 860);
		game->animdos++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdosh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesh, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 703, 860);
		game->animdos++;
	}
}

void	put_homerghulk(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hjambesfh, 575, 850);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hfaceh, 559, 691);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasgh, 437, 860);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasbash, 703, 860);
}

void	put_homerdhulk(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hjambesfh, 575, 850);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hfaceh, 559, 691);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasbash, 528, 860);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
	game->image.hbrasdh, 703, 860);
}
