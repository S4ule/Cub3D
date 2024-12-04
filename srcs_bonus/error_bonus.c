/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:31:45 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 10:28:54 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*print error*/
static void	printerror(char *error)
{
	if (ft_strcmp(error, "FD") == 0)
		write(2, "error opening FD file.\n", 23);
	else if (ft_strcmp(error, "OUTMAP") == 0)
		write(2, "invalid map textures.\n", 22);
	else if (ft_strcmp(error, "MAP") == 0)
		write(2, "invalid map.\n", 13);
	else if (ft_strcmp(error, "EMPTY") == 0)
		write(2, "map is empty.\n", 14);
	else if (ft_strcmp(error, "TEXT") == 0)
		write(2, "invalid textures.\n", 18);
	else if (ft_strcmp(error, "COLOR") == 0)
		write(2, "invalid colors.\n", 16);
	else if (ft_strcmp(error, "CMAP") == 0)
		write(2, "invalid contour map.\n", 21);
	else if (ft_strcmp(error, "PLAYER") == 0)
		write(2, "invalid number of players.\n", 27);
	else if (ft_strcmp(error, "CARAC") == 0)
		write(2, "invalid caractere.\n", 19);
	else if (ft_strcmp(error, "MLX") == 0)
		write(2, "invalid MLX init.\n", 18);
	else if (ft_strcmp(error, "INIT") == 0)
		write(2, "invalid number of args.\n", 24);
}

/*print error free all and exit*/
int	printexit_perror(t_game *game, char *error)
{
	if (!error)
		return (0);
	write(2, "Error\n", 6);
	write(2, "cub3D: ", 7);
	printerror(error);
	free_all(game);
	exit(1);
	return (1);
}

/*mlx destroy images if exit game*/
void	destroy_images(t_game *game)
{
	if (game->tex.e_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.e_start);
	if (game->tex.n_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.n_start);
	if (game->tex.s_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.s_start);
	if (game->tex.w_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.w_start);
	if (game->screen_img != NULL)
		mlx_destroy_image(game->mlx_ptr, game->screen_img);
	if (game->tex.p_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.p_start);
	if (game->tex.o_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.o_start);
	if (game->tex.d_start != NULL)
		mlx_destroy_image(game->mlx_ptr, game->tex.d_start);
	if (game->image.hbras != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbras);
	if (game->image.hdos != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hdos);
	if (game->image.hdroite != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hdroite);
	destroy_imagesbis(game);
}

/*mlx destroy images if exit game*/
void	destroy_imagesbis(t_game *game)
{
	if (game->image.hgauche != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hgauche);
	if (game->image.hface != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hface);
	if (game->image.hjambes != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hjambes);
	if (game->image.hjambesf != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hjambesf);
	if (game->image.hbrasg != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasg);
	if (game->image.hbrasd != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasd);
	if (game->image.hbrasbas != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasbas);
	if (game->image.epaules != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.epaules);
	if (game->image.epaulesface != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.epaulesface);
	if (game->image.victory != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.victory);
	destroy_imagesbisbis(game);
}

/*mlx destroy images if exit game*/
void	destroy_imagesbisbis(t_game *game)
{
	if (game->image.zzz != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.zzz);
	if (game->image.zzo != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.zzo);
	if (game->image.zoz != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.zoz);
	if (game->image.zoo != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.zoo);
	if (game->image.ozz != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.ozz);
	if (game->image.ozo != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.ozo);
	if (game->image.ooz != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.ooz);
	if (game->image.ooo != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.ooo);
	if (game->image.onelif != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.onelif);
	if (game->image.twolif != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.twolif);
	if (game->image.threelif != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.threelif);
	destroy_imagesbisbisbis(game);
}
