/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:32:15 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 07:46:27 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*function to free a char** with int for size */
static void	ft_free_textures(char **str, int i)
{
	if (!str)
		return ;
	while (str && i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

/*for free everything*/
void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_ptr != NULL)
		mlx_clear_window(game->mlx_ptr, game->mlx_win);
	destroy_images(game);
	if (game->mlx_ptr != NULL && game->mlx_win != NULL)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_free_mapping(game->mapping);
	ft_free_textures(game->imgs, game->num_imgs_text);
	free(game->imgs_text);
	if (game->fd > 0)
		close(game->fd);
	if (game->mlx_ptr != NULL)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

/*function to free a char** */
void	ft_free_mapping(char **str)
{
	size_t	index;

	index = 0;
	if (!str)
		return ;
	while (str && str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

/*free and exit :)*/
void	ft_exit_close(t_game *game)
{
	free_all(game);
	exit(0);
}

void	destroy_imagesbisbisbis(t_game *game)
{
	if (game->image.hgaucheh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hgaucheh);
	if (game->image.hfaceh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hfaceh);
	if (game->image.hjambesh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hjambesh);
	if (game->image.hjambesfh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hjambesfh);
	if (game->image.hbrasgh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasgh);
	if (game->image.hbrasdh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasdh);
	if (game->image.hbrasbash != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrasbash);
	if (game->image.epaulesh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.epaulesh);
	if (game->image.epaulesfaceh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.epaulesfaceh);
	if (game->image.hbrash != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hbrash);
	if (game->image.hdosh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hdosh);
	if (game->image.hdroiteh != NULL)
		mlx_destroy_image(game->mlx_ptr, game->image.hdroiteh);
}
