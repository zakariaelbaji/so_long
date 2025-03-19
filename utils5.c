/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:28:32 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 17:42:48 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar(n + '0', fd);
	}
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
