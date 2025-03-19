/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:54 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 21:12:05 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_moves(t_game *game)
{
	char	*moves_str;
	char	*display_str;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
	{
		ft_print_error("Error: itoa failed\n");
		free_mlx(game, 1);
	}
	display_str = ft_strjoin("MOVES: ", moves_str);
	free(moves_str);
	if (!display_str)
	{
		ft_print_error("Error: strjoin failed\n");
		free_mlx(game, 1);
	}
	mlx_string_put(game->mlx, game->win, 12, 12, 0xFFFFFF, display_str);
	free(display_str);
}

static	void	open_window_and_file_to_image_helper2(t_game *game)
{
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_enemy)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
	game->img_player1 = mlx_xpm_file_to_image(game->mlx, "textures/player1.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_player1)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
}

static	void	open_window_and_file_to_image_helper1(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->img_width, &game->img_height);
	if (!game->img_collectible)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
	open_window_and_file_to_image_helper2(game);
}

static	void	open_window_and_file_to_image_helper(t_game *game)
{
	game->img_ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_ground)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_player)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_exit)
	{
		ft_print_error("Error: mlx_xpm_file_to_image failed\n");
		free_mlx(game, 1);
	}
}

void	open_window_and_file_to_image(t_game *game)
{
	int	map_width;
	int	map_height;

	map_width = ft_strlen(game->map[0]);
	map_height = 0;
	while (game->map[map_height])
		map_height++;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_print_error("Error: mlx_failed failed\n");
		free_mlx(game, 1);
	}
	game->win = mlx_new_window(game->mlx, map_width * 32, map_height * 32,
			"so_long");
	if (!game->win)
	{
		ft_print_error("Error: mlx_new_window failed\n");
		free_mlx(game, 1);
	}
	open_window_and_file_to_image_helper(game);
	open_window_and_file_to_image_helper1(game);
}
