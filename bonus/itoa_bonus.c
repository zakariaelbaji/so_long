/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:16 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 14:59:22 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	alloc_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;
	int		len;

	nb = n;
	len = alloc_len(n);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	len--;
	while (nb != 0)
	{
		ptr[len] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (ptr);
}

void	free_enemies_fail(t_game *game)
{
	if (game->enemies == NULL)
	{
		ft_print_error("Error: allocate memory\n");
		free_mlx(game, 1);
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
