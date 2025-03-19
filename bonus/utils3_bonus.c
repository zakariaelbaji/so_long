/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:17 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/12 22:05:36 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	free_enemies(t_enemy *head)
{
	t_enemy	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
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
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->img_player1)
		mlx_destroy_image(game->mlx, game->img_player1);
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
	free_enemies(game->enemies);
	exit(flag);
}

void	move_enemy(t_game *game)
{
	t_enemy	*current;
	int		new_y;

	current = game->enemies;
	while (current)
	{
		new_y = current->y + current->derection;
		if (game->map[new_y][current->x] != '1'
			&& game->map[new_y][current->x] != 'C')
		{
			game->map[current->y][current->x] = '0';
			current->y = new_y;
			game->map[current->y][current->x] = 'X';
		}
		else
		{
			current->derection *= -1;
		}
		current = current->next;
	}
}

void	check_read_bytes(ssize_t read_bytes)
{
	if (read_bytes <= 0)
	{
		ft_print_error("Error : Failed to read map\n");
		exit(1);
	}
}
