/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:56 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 03:05:58 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map_h(char *file, ssize_t read_bytes, size_t total_size,
		int fd)
{
	char	*buffer;

	buffer = malloc(total_size + 1);
	if (!buffer)
	{
		ft_print_error("Error: Memory allocation failed\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		ft_print_error("Error: Failed to reopen map file\n");
		exit(1);
	}
	read_bytes = read(fd, buffer, total_size);
	if (read_bytes < 0)
	{
		free(buffer);
		close(fd);
		ft_print_error("Error: Incomplete read of map file\n");
		exit(1);
	}
	buffer[total_size] = '\0';
	return (close(fd), buffer);
}

static void	read_map_helper1(ssize_t read_bytes, int fd)
{
	if (read_bytes < 0)
	{
		close(fd);
		ft_print_error("Error: Failed to read map file\n");
		exit(1);
	}
}

static void	validate_map_format(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] == '\n')
		{
			ft_print_error("Error: Map contains an invalid empty line\n");
			exit(1);
		}
		i++;
	}
}

void	validate_map_content(char *content)
{
	size_t	len;

	len = ft_strlen(content);
	if (len > 0 && content[len - 1] == '\n')
	{
		ft_print_error("Error: Map ends with empty line\n");
		free(content);
		exit(1);
	}
}

char	*read_map(char *file)
{
	int		fd;
	char	temp_buffer[1024];
	char	*buffer;
	ssize_t	read_bytes;
	size_t	total_size;

	total_size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error("Error: Failed to open map file\n");
		exit(1);
	}
	read_bytes = read(fd, temp_buffer, sizeof(temp_buffer));
	check_read_bytes(read_bytes);
	while (read_bytes > 0)
	{
		total_size += read_bytes;
		read_bytes = read(fd, temp_buffer, sizeof(temp_buffer));
	}
	read_map_helper1(read_bytes, fd);
	close(fd);
	buffer = read_map_h(file, read_bytes, total_size, fd);
	validate_map_format(buffer);
	return (buffer);
}
