/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:39:52 by mafissie          #+#    #+#             */
/*   Updated: 2022/07/04 15:13:30 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_EXIT		17
# define A_KEY		97
# define W_KEY		119
# define S_KEY		115
# define D_KEY		100
# define ESC		65307

typedef struct s_img
{
	void	*icolect;
	void	*iexit;
	void	*iplayer;
	void	*imur;
	void	*isol;
	int		y;
	int		x;
	int		nbrc;
	int		ncout;
	int		status_exit;
}				t_img;

typedef struct s_player
{
	int		y;
	int		x;
}				t_player;

typedef struct s_window
{
	void		*mlx;
	void		*pwin;
	int			x_map;
	int			y_map;
	char		**map;
	t_img		img;
}				t_window;

typedef struct s_error
{
	int	check_p;
	int	check_e;
	int	check_c;
	int	count;
	int	line;
}				t_error;

void	ft_check_update_img(char **map, t_window *win, int x, int y);
void	ft_fill_img_data(t_window *win, char **map);
void	ft_construct_data(char **map, t_window	*win);
int		ft_free_map(char **map);
int		ft_free_img(t_window *win);
void	ft_name_map_error(char *file, int fd);
char	**ft_get_map(char *file);
int		ft_error(char *str);
int		ft_check_map_is_quadrilatere(char **map);
int		ft_check_config_map(char **map);
int		ft_len_map(char **map);
int		ft_get_map_error(char **map);
int		ft_error(char *str);
int		ft_check_map_is_quadrilatere(char **map);
int		ft_check_config_map(char **map);
int		ft_len_map(char **map);
int		ft_get_map_error(char **map);
void	ft_init_struct(t_error *error);
int		ft_check_pos_player(t_window *win, int x, int y, int search);
void	ft_mouve_player_up(t_window *win);
void	ft_mouve_player_down(t_window *win);
void	ft_mouve_player_left(t_window *win);
void	ft_mouve_player_right(t_window *win);
void	ft_register_img(t_window *win);
int		ft_close_with_mouse(t_window *win);

#endif
