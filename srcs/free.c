/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:54:35 by sbalesme          #+#    #+#             */
/*   Updated: 2022/10/26 12:23:26 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
