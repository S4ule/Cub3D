/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:30:08 by ezielins          #+#    #+#             */
/*   Updated: 2022/10/28 06:30:15 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*transform rgb to int*/
static int	rgb_to_int(unsigned int r, unsigned int g, unsigned int b)
{
	int	res;

	if (r > 255 || g > 255 || b > 255)
		return (0xffffff);
	res = r * 256 * 256 + g * 256 + b;
	return (res);
}

/*get rgb with line*/
static int	get_rgb(char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	r = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	i++;
	g = ft_atoi(line + i);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	i++;
	b = ft_atoi(line + i);
	return (rgb_to_int(r, g, b));
}

/*verif rgb for ceiling and floor with atoi color and return int = rgb*/
static int	verif_rgb(char *line)
{
	char	**tmp;

	tmp = ft_split(line, ',');
	if (!tmp || ft_sizingtab(tmp) != 3)
	{
		ft_free_mapping(tmp);
		return (-1);
	}
	if (ft_atoi_color(tmp[0]) == 1 || ft_atoi_color(tmp[1]) == 1 || \
	ft_atoi_color(tmp[2]) == 1)
	{
		ft_free_mapping(tmp);
		return (-1);
	}
	ft_free_mapping(tmp);
	return (get_rgb(line));
}

/*verif rgb for ceiling and floor*/
static int	floor_ceiling_color_bis(char *line, t_game *game, char c)
{
	int	err;

	err = -1;
	if (c == 'F')
	{
		err = verif_rgb(line);
		game->tex.floor = verif_rgb(line);
	}
	else if (c == 'C')
	{
		err = verif_rgb(line);
		game->tex.ceiling = verif_rgb(line);
	}
	if (err == -1)
		return (1);
	return (0);
}

/*check if map.cub colors are ok*/
int	floor_ceiling_color(char *line, t_game *game, \
	char *str, int *countnormmap)
{
	char	c;

	if (!str || !line)
		return (1);
	if (ft_strncmp(str, "F", 2) == 0)
		c = 'F';
	else if (ft_strncmp(str, "C", 2) == 0)
		c = 'C';
	else
	{
		game->tex.floor = -1;
		game->tex.ceiling = -1;
		return (1);
	}
	if (line != NULL)
	{
		if (floor_ceiling_color_bis(line, game, c) == 1)
			return (1);
		(*countnormmap) += 1;
	}
	return (0);
}
