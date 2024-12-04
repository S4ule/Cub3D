/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:28:01 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 18:31:41 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*check contour of map with only '1' condition */
static int	check_contours_are_ok(t_game *game, int line, int col, int last)
{
	int	result;
	int	wall;
	int	space;

	wall = countwall(game->mapping[line]);
	space = countspace(game->mapping[line]);
	result = ft_strlengh(game->mapping[line]) - wall - space;
	if (line == 0 && result != 0)
		return (0);
	if ((line == game->height - 1) && result != 0)
		return (0);
	if (col < last && game->mapping[line][col] != '1')
		return (0);
	else if (col < last && game->mapping[line][last] != '1')
		return (0);
	return (1);
}

/*check color of map arguments*/
void	check_txtursorcolors_are_ok(t_game *game)
{
	if (game->tex.ceiling == -1 || game->tex.floor == -1)
		printexit_perror(game, "COLOR");
	if (!game->tex.e_start || !game->tex.n_start || !game->tex.s_start \
	|| !game->tex.w_start || !game->tex.o_start || !game->tex.d_start)
		printexit_perror(game, "TEXT");
}

/*check if map format is .cub*/
static int	check_map_format(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s2);
	j = ft_strlen(s1);
	while (n != 0 && i != 0 && j != 0 && s1[j - 1] == s2[i - 1])
	{
		i--;
		j--;
		n--;
	}
	if (n != 0)
		return (-1);
	return (0);
}

/*check if argc and argv are ok*/
void	check_files_are_ok(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\n", 6);
		write(2, "cub3D: ", 7);
		write(2, "Too many or too less args\n", 26);
		exit(0);
	}
	if (check_map_format(av[1], ".cub", 4) != 0)
	{
		write(2, "Error\n", 6);
		write(2, "cub3D: ", 7);
		write(2, "expecting map with .cub format\n", 31);
		exit(0);
	}
}

/*check all elements of the map*/
void	check_maps_are_ok(t_game *game)
{
	int	col;
	int	line;
	int	last;

	if (game->mapping[0] == NULL)
		printexit_perror(game, "EMPTY");
	line = 0;
	while (line < game->height)
	{
		col = 0;
		last = ft_strlengh(game->mapping[line]) - 1;
		if (ft_strncmp(game->mapping[line], "", 1) == 0)
			printexit_perror(game, "MAP");
		while (game->mapping[line][col] == ' ' && col <= last)
			col++;
		while (game->mapping[line][last] == ' ' && last > 0)
			last--;
		if (!check_contours_are_ok(game, line, col, last))
			printexit_perror(game, "CMAP");
		line++;
	}
	check_wfpnswe(game);
	check_maps_are_ok_bis(game);
}
