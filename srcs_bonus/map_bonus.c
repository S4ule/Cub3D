/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:35:16 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 12:45:48 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*check if av[1].cub ceiling and floor color are ok*/
int	check_floor_and_ceiling(char *line, t_game *game)
{
	if (line == NULL)
		return (1);
	if ((!ft_strcmp(line, "F") && game->tex.floor == -1) || \
		(!ft_strcmp(line, "C") && game->tex.ceiling == -1))
		return (1);
	return (0);
}

/*check errors after reading av[1].cub*/
static void	check_error_read_map(t_game *game, int count)
{
	if (count == 0)
		printexit_perror(game, "EMPTY");
	if (count > 0 && count < 8)
		printexit_perror(game, "TEXT");
	game->height = ft_sizingtab(game->mapping);
	return ;
}

/*return FD map*/
static int	file_descriptor(char *map, t_game *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		printexit_perror(game, "FD");
	return (fd);
}

/*open av[1].cub...put textures/colors in game and do mapping*/
void	open_and_read_map(char *map, t_game *game)
{
	char	*line[2];
	int		in_map;
	int		countnormmap;

	countnormmap = 0;
	in_map = 0;
	game->fd = file_descriptor(map, game);
	while (1)
	{
		line[0] = get_next_line(game->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n");
		free(line[0]);
		countnormmap = open_and_readmapbis(line, game, in_map, countnormmap);
		free(line[1]);
	}
	if (countnormmap != game->num_imgs_text + 2)
		printexit_perror(game, "MAP");
	check_error_read_map(game, countnormmap);
}

/*check av[1].ber and put wall textures in game*/
void	put_txturs_in_map(char *map, t_game *game, int *countnormmap)
{
	char	**line;
	int		err;

	line = ft_split(map, ' ');
	if (!line)
	{
		free(map);
		printexit_perror(game, "OUTMAP");
	}
	err = comp_and_put(map, game, countnormmap, line);
	ft_free_mapping(line);
	if (err == 1)
	{
		free(map);
		printexit_perror(game, "TEXT");
	}
}
