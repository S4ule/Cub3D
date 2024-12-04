/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:23:38 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 12:45:11 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	do_check_ls_bits_y(t_game *game, int p_y, int p_x, int *res)
{
	int	x;
	int	y;

	x = p_x;
	y = p_y;
	while (y >= 0 && y < game->height && game->mapping[y][x] != ' ')
	{
		if (game->mapping[y][x] == '1')
		{
			(*res) += 1;
			break ;
		}
		y++;
	}
	x = p_x;
	y = p_y;
	while (y >= 0 && y < game->height && game->mapping[y][x] != ' ')
	{
		if (game->mapping[y][x] == '1')
		{
			(*res) += 1;
			break ;
		}
		y--;
	}
}

static void	do_check_ls_bits_x(t_game *game, int p_y, int p_x, int *res)
{
	int	x;
	int	y;

	x = p_x;
	y = p_y;
	while (x >= 0 && x < game->width && game->mapping[y][x] != ' ')
	{
		if (game->mapping[y][x] == '1')
		{
			(*res) += 1;
			break ;
		}
		x++;
	}
	x = p_x;
	y = p_y;
	while (x >= 0 && x < game->width && game->mapping[y][x] != ' ')
	{
		if (game->mapping[y][x] == '1')
		{
			(*res) += 1;
			break ;
		}
		x--;
	}
}

int	open_and_readmapbis(char **line, t_game *game, int in_map, int countnormmap)
{
	if (line[1] && line[1][0] && line[1][0] >= 'A' && line[1][0] <= 'Z')
	{
		if (in_map == 1)
			in_map = 2;
		put_txturs_in_map(line[1], game, &countnormmap);
		if (countnormmap > game->num_imgs_text + 2)
			freefreefree(game, line[1]);
	}
	else if (line[1] && line[1][0] != '\0' && in_map != 2)
	{
		in_map = 1;
		if (!game->mapping)
			game->mapping = resize_map(game, line[1]);
		game->mapping = ft_mapping(line[1], game->mapping);
		if (ft_strlengh(line[1]) > game->width)
			game->width = ft_strlengh(line[1]);
	}
	else if (line[1] && line[1][0])
		freefreefree(game, line[1]);
	return (countnormmap);
}

static bool	check_lc_bits(t_game *game, int p_y, int p_x)
{
	int	res;

	res = 0;
	if (game->mapping[p_y][p_x] == '0')
	{
		do_check_ls_bits_y(game, p_y, p_x, &res);
		do_check_ls_bits_x(game, p_y, p_x, &res);
	}
	else
		return (true);
	if (res == 4)
		return (true);
	return (false);
}

void	check_maps_are_ok_bis(t_game *game)
{
	int	last;
	int	col;
	int	line;

	last = ft_strlen(game->mapping[0]) - 1;
	col = -1;
	while (++col <= last)
	{
		line = 0;
		while (line < game->height)
		{
			if (check_lc_bits(game, line, col) == false)
				printexit_perror(game, "CMAP");
			line++;
		}
	}
}
