/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:21:03 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 10:29:32 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_scorebis(t_game *game)
{
	game->image.epaulesface = mlx_xpm_file_to_image(game->mlx_ptr, EPAULESF, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.epaulesfaceh = mlx_xpm_file_to_image(game->mlx_ptr, EPAULESFH, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.victory = mlx_xpm_file_to_image(game->mlx_ptr, VICTORY, \
	&(game->image.img_w), &(game->image.img_h));
}

void	init_data(t_game *game)
{
	game->resolx = 1280;
	game->resolx = 1024;
	game->mouse_on = 0;
	game->fps = 0;
	game->animdos = 1;
	game->animface = 1;
	game->minimap = 0;
	game->homer = 1;
	game->animgauche = 1;
	game->animdroite = 1;
	game->krusty = 0;
	game->nelson = 0;
	game->burns = 0;
	game->life = 3;
	game->hulk = 0;
}

void	init_texturesbis(t_game *game)
{
	game->image.zzz = NULL;
	game->image.zzo = NULL;
	game->image.zoz = NULL;
	game->image.zoo = NULL;
	game->image.ozz = NULL;
	game->image.ozo = NULL;
	game->image.ooz = NULL;
	game->image.ooo = NULL;
	game->image.onelif = NULL;
	game->image.twolif = NULL;
	game->image.threelif = NULL;
	game->image.epaulesface = NULL;
	game->tex.d_start = NULL;
	game->image.victory = NULL;
}

void	init_textures(t_game *game)
{
	game->tex.e_start = NULL;
	game->tex.n_start = NULL;
	game->tex.s_start = NULL;
	game->tex.w_start = NULL;
	game->tex.p_start = NULL;
	game->tex.o_start = NULL;
	game->image.imgb = NULL;
	game->image.imgbb = NULL;
	game->image.imgbbb = NULL;
	game->image.hbras = NULL;
	game->image.hdos = NULL;
	game->image.hdroite = NULL;
	game->image.hgauche = NULL;
	game->image.hface = NULL;
	game->image.hjambes = NULL;
	game->image.hjambesf = NULL;
	game->image.hbrasg = NULL;
	game->image.hbrasd = NULL;
	game->image.hbrasbas = NULL;
	game->image.epaules = NULL;
	init_texturesbis(game);
}

void	init_score(t_game *game)
{
	game->image.zzz = mlx_xpm_file_to_image(game->mlx_ptr, ZZZ, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.zzo = mlx_xpm_file_to_image(game->mlx_ptr, ZZO, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.zoz = mlx_xpm_file_to_image(game->mlx_ptr, ZOZ, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.zoo = mlx_xpm_file_to_image(game->mlx_ptr, ZOO, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.ozz = mlx_xpm_file_to_image(game->mlx_ptr, OZZ, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.ozo = mlx_xpm_file_to_image(game->mlx_ptr, OZO, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.ooz = mlx_xpm_file_to_image(game->mlx_ptr, OOZ, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.ooo = mlx_xpm_file_to_image(game->mlx_ptr, OOO, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.onelif = mlx_xpm_file_to_image(game->mlx_ptr, ONELIF, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.twolif = mlx_xpm_file_to_image(game->mlx_ptr, TWOLIF, \
	&(game->image.img_w), &(game->image.img_h));
	game->image.threelif = mlx_xpm_file_to_image(game->mlx_ptr, THREELIF, \
	&(game->image.img_w), &(game->image.img_h));
	init_scorebis(game);
}
