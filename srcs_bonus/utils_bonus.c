/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:36:26 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/13 18:18:23 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*determine size of a strings tab*/
int	ft_sizingtab(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str)
		count++;
	return (count);
}

/*return str lengh*/
int	ft_strlengh(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*check if space in case around the map is ok*/
int	check_autour(t_game *game, int y, int x)
{
	int	i;
	int	j;

	i = y - 1;
	while (i < y + 1)
	{
		j = x - 1;
		while (j < x + 1)
		{
			if (game->mapping[i][j] != ' ' && game->mapping[i][j] != '1' && \
			game->mapping[i][j] != '2' && game->mapping[i][j] != '3' \
			&& game->mapping[i][j] != '5')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*search .xpm in a line*/
int	check_xpm(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (--n && i && j && s1[i] == s2[j])
	{
		i--;
		j--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

/*strcmp*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
