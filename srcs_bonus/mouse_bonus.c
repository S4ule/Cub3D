/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 06:25:30 by ezielins          #+#    #+#             */
/*   Updated: 2022/11/14 13:18:28 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	mouse_hook(int x, int y, t_game *game)
{
	(void)y;
	if (game->mouse_on == 1)
	{
		if (x > game->resolx - (WIDTHW / 2))
		{	
			game->player.rot_speed = 0.01;
			check_keyrotate(ARROW_RIGHT, game);
			mlx_clear_window(game->mlx_ptr, game->mlx_win);
			put_crgb_screen(game);
			put_frgb_screen(game);
			put_map_screen(game);
		}
		else if (x < game->resolx - (WIDTHW / 2))
		{
			game->player.rot_speed = 0.01;
			check_keyrotate(ARROW_LEFT, game);
			mlx_clear_window(game->mlx_ptr, game->mlx_win);
			put_crgb_screen(game);
			put_frgb_screen(game);
			put_map_screen(game);
		}
	}
	game->player.rot_speed = 0.35;
	return (0);
}

void	check_mouse(int key, t_game *game)
{
	if (key == M && game->mouse_on == 0)
		game->mouse_on = 1;
	else if (key == M && game->mouse_on == 1)
		game->mouse_on = 0;
	if (key == C && game->minimap == 0)
		game->minimap = 1;
	else if (key == C && game->minimap == 1)
		game->minimap = 0;
	if (key == F && game->fps == 0)
		game->fps = 1;
	else if (key == F && game->fps == 1)
		game->fps = 0;
	if (key == E && (check_open(game) == 1))
		open_door(game);
	else if (key == E && (check_open(game) == 2))
		close_door(game);
}

void	check_options(t_game *game)
{
	check_hulk(game);
	if (game->fps == 1)
		fps_count(game);
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 45, \
		BLACK, "TOUCHE (F)   F P S : 0");
	if (game->mouse_on == 1)
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 25, \
		BLACK, "TOUCHE (M)   SOURIS ACTIVEE");
	else if (game->mouse_on == 0)
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 25, \
		BLACK, "TOUCHE (M)   SOURIS DESACTIVEE");
	if (game->minimap == 1)
	{
		draw_minimap(game);
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 65, \
		BLACK, "TOUCHE (C)   MINIMAP ACTIVEE");
	}
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 65, \
		BLACK, "TOUCHE (C)   MINIMAP DESACTIVEE");
	if (game->life == 1)
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1065, 152, \
		RED, "CAREFULL..FIND A BEER !!");
}

void	disp_fps(t_game *game, char *str)
{
	if (str != NULL)
	{
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1070, 45, \
		BLACK, "TOUCHE (F)   F P S :");
		mlx_string_put(game->mlx_ptr, game->mlx_win, 1195, 45, \
		BLACK, str);
	}
}

void	fps_count(t_game *game)
{
	static long			lastime;
	static long			currentime;
	static int			nbframes;
	static double		fps;
	char				*str;

	(void)game;
	nbframes = 0;
	fps = nbframes;
	lastime = 0;
	fps++;
	currentime = ft_time();
	if ((currentime - lastime) >= 1.0)
	{
		fps = (currentime - lastime) / 10000000000;
		nbframes = 0;
		lastime = currentime;
	}
	str = ft_itoa(fps);
	disp_fps(game, str);
}
