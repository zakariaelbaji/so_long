/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:01:50 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 16:45:19 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_ln;
	int		s2_ln;
	char	*result;
	char	*start;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_ln = ft_strlen(s1);
	s2_ln = ft_strlen(s2);
	result = (char *)malloc((s1_ln + s2_ln + 1) * sizeof(char));
	if (!result)
		return (NULL);
	start = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (start);
}

int	game_loop(t_game *game)
{
	usleep(150000);
	move_enemy(game);
	render_map(game);
	return (0);
}

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
