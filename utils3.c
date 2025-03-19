/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:14:44 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/17 22:19:33 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	row_walls_map_validation_is_valid(char **map)
{
	if (!row_validation(map))
	{
		ft_print_error("Error: Map is not rectangular\n");
		free_map(map);
		exit(1);
	}
	if (!is_sorrounded_walls(map))
	{
		ft_print_error("Error: Map is not sorrounded by walls\n");
		free_map(map);
		exit(1);
	}
	if (!valid_map_content(map))
	{
		ft_print_error("Error: Missing required elements or Duplicate\n");
		free_map(map);
		exit(1);
	}
}

int	free_mlx(t_game *game, int flag)
{
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_ground)
		mlx_destroy_image(game->mlx, game->img_ground);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(flag);
}
