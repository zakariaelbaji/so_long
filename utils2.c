/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:02:28 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 18:12:14 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	render_map_helper1(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
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

static	void	render_map_helper(t_game *game, int i, int j)
{
	if (i == game->player.y && j == game->player.x)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * 32,
			i * 32);
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
