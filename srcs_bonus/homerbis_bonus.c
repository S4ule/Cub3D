/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homerbis_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:56:25 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 19:20:15 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	put_homergg(t_game *game)
{
	if (game->animgauche % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hgauche, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 618, 860);
		game->animgauche++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hgauche, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasg, 528, 860);
		game->animgauche++;
	}
}

void	put_homerdd(t_game *game)
{
	if (game->animdroite % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdroite, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 618, 860);
		game->animdroite++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambes, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdroite, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasd, 618, 860);
		game->animdroite++;
	}
}

void	put_homerface(t_game *game)
{
	if (game->animface % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesf, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hface, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesface, 703, 860);
		game->animface++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesf, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hface, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesface, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbas, 703, 860);
		game->animface++;
	}
}
