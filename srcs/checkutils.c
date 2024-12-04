/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:48:20 by sbalesme          #+#    #+#             */
/*   Updated: 2022/11/14 10:01:47 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*check map elements and put player position in map*/
static void	check_elements(t_game *game, int i, int j)
{
	if (ft_strchr("NSWE", game->mapping[i][j]) && game->player.dir == 0)
	{
		game->player.dir = game->mapping[i][j];
		game->player.x = (float)j;
		game->player.y = (float)i;
	}
	else if (ft_strchr("NSWE", game->mapping[i][j]) && game->player.dir)
		printexit_perror(game, "PLAYER");
	else if (!ft_strchr("01C", game->mapping[i][j]))
		printexit_perror(game, "CARAC");
	if ((i == game->height - 1) && !game->player.dir)
		printexit_perror(game, "PLAYER");
}

/*count '1' = wall in each line*/
int	countwall(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '1')
			count++;
		i++;
	}
	return (count);
}

/*count ' ' = space in each line*/
int	countspace(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

/*check elements in the map*/
void	check_wfpnswe(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->mapping[i][j] != ' ')
				check_elements(game, i, j);
			j++;
		}
		i++;
	}
}
