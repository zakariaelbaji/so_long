/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:17:17 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 18:18:13 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_help
{
	int				collectible;
	int				player;
	int				exitt;
	int				i;
	int				j;
}					t_help;
# define ESC 65307
# define UP 65362
# define W 119
# define A 97
# define LEFT 65361
# define RIGHT 65363
# define D 100
# define S 115
# define DOWN 65364

typedef struct s_enemy
{
	int				x;
	int				y;
	int				derection;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	void			*img_wall;
	void			*img_ground;
	void			*img_player;
	void			*img_player1;
	int				animation_frame;
	void			*img_collectible;
	void			*img_exit;
	void			*img_enemy;
	int				img_width;
	t_pos			player;
	int				img_height;
	int				moves;
	int				collectibles_count;
	t_enemy			*enemies;
}					t_game;

int					row_validation(char **map);
int					is_sorrounded_walls(char **map);
int					valid_map_content(char **map);
void				ft_print_error(char *s);
void				flood_fill(char **map, int x, int y);
int					is_reachable(char **map);
char				**copy_map(char **map);
char				*ft_strdup(char *s);
int					ft_strlen(char *s);
t_pos				find_pos_player(char **map);
void				render_map(t_game *game);
int					count_collectibles(char **map);
void				free_map(char **map);
int					free_mlx(t_game *game, int flag);
void				is_reachable_valid(char **map_copy, int x, int y,
						char **map);
void				row_walls_map_validation_is_valid(char **map);
void				open_window_and_file_to_image(t_game *game);
void				move_enemy(t_game *game);
char				*ft_itoa(int n);
void				free_enemies(t_enemy *head);
int					game_loop(t_game *game);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *s1, char *s2);
int					check_map(char *file);
void				render_moves(t_game *game);
char				*read_map(char *file);
void				ft_putnbr_fd(int n, int fd);
t_enemy				*find_enemy(char **map);
void				free_enemies_fail(t_game *game);
void				if_map_fails(char **map);
void				check_read_bytes(ssize_t read_bytes);
int					has_enemy_on_map(char **map);
void				free_copy(char **copy, int rows_allocated);
void				validate_map_content(char *content);

#endif
