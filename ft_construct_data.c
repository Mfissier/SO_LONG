/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:12:18 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/20 08:29:57 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_check_update_img(char **map, t_window *win, int x, int y)
{
	if (map[y][x] == 'P')
		mlx_put_image_to_window(win->mlx, win->pwin, win->img.iplayer, \
	x * 64, y * 64);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(win->mlx, win->pwin, win->img.iexit, \
	x * 64, y * 64);
	else if (map[y][x] == 'C')
	{
		win->img.nbrc++;
		mlx_put_image_to_window(win->mlx, win->pwin, win->img.icolect, \
		x * 64, y * 64);
	}
	else if (map[y][x] == '1')
		mlx_put_image_to_window(win->mlx, win->pwin, win->img.imur, \
		x * 64, y * 64);
	else if (map[y][x] == '0')
		mlx_put_image_to_window(win->mlx, win->pwin, win->img.isol, \
		x * 64, y * 64);
}

void	ft_fill_img_data(t_window *win, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	win->img.nbrc = 0;
	ft_register_img(win);
	while (map[y] != NULL)
	{
		while (map[y][x])
			ft_check_update_img(map, win, x++, y);
		x = 0;
		y++;
	}
	ft_free_img(win);
	if (win->img.status_exit == 1)
	{
		ft_putnbr_fd(win->img.ncout + 1, 1);
		ft_putstr_fd(": nombre de cout\n", 1);
		ft_putstr_fd("WIN !\n", 1);
		ft_close_with_mouse(win);
	}
	ft_putnbr_fd(win->img.ncout, 1);
	ft_putstr_fd(": nombre de cout\n", 1);
}

void	ft_construct_data(char **map, t_window	*win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	win->x_map = 0;
	win->y_map = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] && y == 0)
			x++;
		y++;
	}
	win->x_map = x;
	win->y_map = y;
}
