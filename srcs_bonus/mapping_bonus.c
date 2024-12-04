/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:35:54 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 11:50:32 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*duping in new char** an old char** with index of char* to dup*/
static char	*ft_duping(char *str, char **map, int i, char **tmp)
{
	(void)str;
	if (!map[i])
	{
		map[i] = ft_strdup(str);
	}
	tmp[i] = ft_strdup(map[i]);
	if (!tmp[i])
	{
		ft_free_mapping(map);
		ft_free_mapping(tmp);
	}
	return (tmp[i]);
}

/*mapping game with additional new line*/
char	**ft_mapping(char *str, char **map)
{
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	tmp = NULL;
	if (!str)
		return (map);
	len = ft_sizingtab(map);
	tmp = (char **)malloc(sizeof(char *) * (len + 2));
	if (!tmp)
		return (map);
	tmp[len + 1] = NULL;
	while (i < len)
	{
		tmp[i] = ft_duping(str, map, i, tmp);
		i++;
	}
	tmp[i] = ft_strdup(str);
	i = 0;
	while (i < len)
		free(map[i++]);
	free(map);
	return (tmp);
}

/*resize end of each lines with spaces up to all lines have the same width*/
char	**resize_endofmap(t_game *game)
{
	int		line;
	int		col;
	char	**tmp;

	line = 0;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		return (game->mapping);
	while (line < game->height)
	{
		tmp[line] = (char *)malloc(sizeof(char) * (game->width + 1));
		col = 0;
		while (col < game->width)
		{
			if (col >= ft_strlengh(game->mapping[line]))
				tmp[line][col] = ' ';
			else
				tmp[line][col] = game->mapping[line][col];
			col++;
		}
		tmp[line][col] = '\0';
		line++;
	}
	tmp[line] = NULL;
	return (tmp);
}

/*resize map for the first line*/
char	**resize_map(t_game *game, char *str)
{
	int		line;
	int		col;
	char	**tmp;

	(void)str;
	if (!game->height)
		game->height = 0;
	line = 0;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		return (NULL);
	while (line < game->height)
	{
		tmp[line] = (char *)malloc(sizeof(char) * (game->width + 1));
		col = 0;
		while (col < game->width)
		{
			tmp[line][col] = game->mapping[line][col];
			col++;
		}
		tmp[line][col] = '\0';
		line++;
	}
	tmp[line] = NULL;
	return (tmp);
}

int	comp_and_put(char *map, t_game *game, int *countnormmap, char **line)
{
	int	err;

	err = 1;
	if (!ft_strcmp(line[0], "NO"))
		err = put_img_textures(line[1], 0, game, countnormmap);
	else if (!ft_strcmp(line[0], "SO"))
		err = put_img_textures(line[1], 1, game, countnormmap);
	else if (!ft_strcmp(line[0], "EA"))
		err = put_img_textures(line[1], 3, game, countnormmap);
	else if (!ft_strcmp(line[0], "WE"))
		err = put_img_textures(line[1], 2, game, countnormmap);
	else if (!ft_strcmp(line[0], "PP"))
		err = put_img_textures(line[1], 4, game, countnormmap);
	else if (!ft_strcmp(line[0], "PC"))
		err = put_img_textures(line[1], 5, game, countnormmap);
	else if (!ft_strcmp(line[0], "DD"))
		err = put_img_textures(line[1], 6, game, countnormmap);
	else if (!check_floor_and_ceiling(line[1], game))
		err = floor_ceiling_color(line[1], game, line[0], countnormmap);
	else
		freefree(game, line, map);
	return (err);
}
