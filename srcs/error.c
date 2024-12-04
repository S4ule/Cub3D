/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalesme <sbalesme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:13:05 by sbalesme          #+#    #+#             */
/*   Updated: 2022/11/14 12:06:55 by sbalesme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	freefreefree(t_game *game, char *line)
{
	free(line);
	printexit_perror(game, "MAP");
}
