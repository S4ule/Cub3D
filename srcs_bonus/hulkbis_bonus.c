/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hulkbis_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:19:12 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 12:47:17 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	put_homergghulk(t_game *game)
{
	if (game->animgauche % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hgaucheh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 618, 860);
		game->animgauche++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hgaucheh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasgh, 528, 860);
		game->animgauche++;
	}
}

void	put_homerddhulk(t_game *game)
{
	if (game->animdroite % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdroiteh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 618, 860);
		game->animdroite++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hdroiteh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasdh, 618, 860);
		game->animdroite++;
	}
}

void	put_homerfacehulk(t_game *game)
{
	if (game->animface % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesfh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hfaceh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesfaceh, 703, 860);
		game->animface++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hjambesfh, 575, 850);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hfaceh, 559, 691);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.epaulesfaceh, 528, 860);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->image.hbrasbash, 703, 860);
		game->animface++;
	}
}

void	freefreefree(t_game *game, char *line)
{
	free(line);
	printexit_perror(game, "MAP");
}
