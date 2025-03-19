/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:29 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/12 22:34:18 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*create_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
		return (NULL);
	new_enemy->x = x;
	new_enemy->y = y;
	new_enemy->next = NULL;
	new_enemy->derection = 1;
	return (new_enemy);
}

void	*free_nodes(t_enemy *head)
{
	t_enemy	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return (NULL);
}

t_enemy	*find_enemy(char **map)
{
	t_enemy	*head;
	t_enemy	*new_enemy;
	int		i;
	int		j;

	head = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
			{
				new_enemy = create_enemy(j, i);
				if (!new_enemy)
					free_nodes(head);
				new_enemy->next = head;
				head = new_enemy;
			}
			j++;
		}
		i++;
	}
	return (head);
}

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

int	has_enemy_on_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
