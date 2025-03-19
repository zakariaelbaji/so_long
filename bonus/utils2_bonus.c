/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:01 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 15:33:11 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map_helper1(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'X')
	{
		if (i == game->player.y && j == game->player.x)
		{
			write(1, "You Lost (\n", 11);
			free_mlx(game, 0);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, j * 32, i
			* 32);
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->collectibles_count == 0 && (i == game->player.y
				&& j == game->player.x))
		{
			write(1, "YOU WON!\n", 9);
			free_mlx(game, 0);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * 32, i
			* 32);
	}
}

void	render_map_helper(t_game *game, int i, int j)
{
	if (i == game->player.y && j == game->player.x)
	{
		if (game->animation_frame == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_player, j
				* 32, i * 32);
			game->animation_frame = 1;
		}
		else if (game->animation_frame == 1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_player1, j
				* 32, i * 32);
			game->animation_frame = 0;
		}
		if (game->map[i][j] == 'C')
		{
			game->collectibles_count--;
			game->map[i][j] = '0';
		}
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_ground,
					j * 32, i * 32);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j
					* 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, j * 32, i * 32);
			render_map_helper1(game, i, j);
			render_map_helper(game, i, j);
			j++;
		}
		i++;
	}
	render_moves(game);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	check_map(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i <= 4)
		return (0);
	i--;
	if (file[i--] != 'r')
		return (0);
	if (file[i--] != 'e')
		return (0);
	if (file[i--] != 'b')
		return (0);
	if (file[i--] != '.')
		return (0);
	if (file[i] == '/')
		return (0);
	return (1);
}
