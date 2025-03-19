/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:03:43 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/19 21:53:14 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	row_validation(char **map)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != row_len)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	valid_map_content(char **map)
{
	t_help	help;

	help = (t_help){0};
	while (map[help.i])
	{
		help.j = 0;
		while (map[help.i][help.j])
		{
			if (map[help.i][help.j] == 'P')
				help.player++;
			else if (map[help.i][help.j] == 'E')
				help.exitt++;
			else if (map[help.i][help.j] == 'C')
				help.collectible++;
			else if (map[help.i][help.j] != '1' && map[help.i][help.j] != '0'
				&& map[help.i][help.j] != 'X')
				return (0);
			help.j++;
		}
		help.i++;
	}
	if ((help.player < 1 && help.collectible < 1)
		||  help.exitt > 1 || help.player > 1 || help.exitt > 1)
		return (0);
	return (1);
}

int	is_sorrounded_walls(char **map)
{
	int	i;
	int	j;
	int	last_row;
	int	last_col;

	last_row = 0;
	i = 0;
	j = 0;
	while (map[last_row])
		last_row++;
	last_row--;
	while (map[0][i] && map[last_row][i])
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (0);
		i++;
	}
	last_col = i - 1;
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][last_col] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'X')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
