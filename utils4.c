/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:24:26 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 18:09:39 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	open_window_and_file_to_image_helper1(t_game *game)
{
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
		ft_print_error("Error: mlx_unit failed\n");
		free_mlx(game, 1);
	}
	game->win = mlx_new_window(game->mlx, map_width * 32, map_height * 32,
			"so_long");
	if (!game->win)
	{
		ft_print_error("Error: mlx_new_window failed\n");
		free_mlx(game, 1);
	}
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	open_window_and_file_to_image_helper1(game);
	open_window_and_file_to_image_helper(game);
}
