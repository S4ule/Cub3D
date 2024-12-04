/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkutils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:28:53 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 11:49:05 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	freefree(t_game *game, char **line, char *map)
{
	free(map);
	ft_free_mapping(line);
	printexit_perror(game, "MAP");
}

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
	else if (!ft_strchr("0123C5", game->mapping[i][j]))
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
		if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '5')
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
