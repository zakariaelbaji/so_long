/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:36:05 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:54 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_reachable_valid(char **map_copy, int x, int y, char **map)
{
	flood_fill(map_copy, x, y);
	if (!is_reachable(map_copy))
	{
		ft_print_error("Error: Not all collectibles are reachable\n");
		free_map(map);
		free_map(map_copy);
		exit(1);
	}
}

void	if_map_fails(char **map)
{
	if (!map)
	{
		ft_print_error("Error: Failed to allocate memory for map\n");
		exit(1);
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

void	free_copy(char **copy, int rows_allocated)
{
	int	j;

	j = 0;
	while (j < rows_allocated)
	{
		free(copy[j]);
		j++;
	}
	free(copy);
}
