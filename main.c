/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:14 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 16:13:20 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	copy_map_valid(char **map, char **map_copy)
{
	if (!map_copy)
	{
		ft_print_error("Error: Failed to allocate memory for map copy\n");
		free_map(map);
		exit(1);
	}
}

static	char	**parse_input(char *file)
{
	char	**map;
	char	*content;
	t_pos	player_pos;
	char	**map_copy;

	if (!check_map(file))
	{
		ft_print_error("Error :invalid file : it should be .ber\n");
		exit(1);
	}
	content = read_map(file);
	validate_map_content(content);
	map = ft_split(content, '\n');
	free(content);
	if_map_fails(map);
	row_walls_map_validation_is_valid(map);
	player_pos = find_pos_player(map);
	map_copy = copy_map(map);
	copy_map_valid(map, map_copy);
	is_reachable_valid(map_copy, player_pos.x, player_pos.y, map);
	free_map(map_copy);
	return (map);
}

static	void	key_hook_helper(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_mlx(game, 0);
	else if (keycode == LEFT || keycode == A)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1')
		{
			game->player.x -= 1;
			write(1, "MOVES: ", 7);
			ft_putnbr_fd(++game->moves, 1);
			write(1, "\n", 1);
		}
	}
	else if (keycode == RIGHT || keycode == D)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->player.x += 1;
			write(1, "MOVES: ", 7);
			ft_putnbr_fd(++game->moves, 1);
			write(1, "\n", 1);
		}
	}
}

static	int	key_hook(int keycode, t_game *game)
{
	if (keycode == UP || keycode == W)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->player.y -= 1;
			write(1, "MOVES: ", 7);
			ft_putnbr_fd(++game->moves, 1);
			write(1, "\n", 1);
		}
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1')
		{
			game->player.y += 1;
			write(1, "MOVES: ", 7);
			ft_putnbr_fd(++game->moves, 1);
			write(1, "\n", 1);
		}
	}
	key_hook_helper(keycode, game);
	render_map(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	if (ac != 2)
	{
		ft_print_error("Usage: ./so_long <map_file>\n");
		exit(1);
	}
	game.map = parse_input(av[1]);
	open_window_and_file_to_image(&game);
	game.player = find_pos_player(game.map);
	game.map[game.player.y][game.player.x] = '0';
	game.collectibles_count = count_collectibles(game.map);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, free_mlx, &game);
	mlx_loop(game.mlx);
	return (0);
}
