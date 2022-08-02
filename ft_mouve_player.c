/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:28:54 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/20 08:32:14 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_pos_player(t_window *win, int x, int y, int search)
{
	if ((search == W_KEY && win->map[y - 1][x] == '1') || (search == S_KEY && \
		win->map[y + 1][x] == '1') || (search == D_KEY && win->map[y][x + 1] \
		== '1') || (search == A_KEY && win->map[y][x - 1] == '1'))
		return (0);
	if ((search == W_KEY && win->map[y - 1][x] == 'E') || (search == S_KEY && \
		win->map[y + 1][x] == 'E') || (search == D_KEY && win->map[y][x + 1] \
		== 'E') || (search == A_KEY && win->map[y][x - 1] == 'E'))
	{
		if (win->img.nbrc == 0)
			win->img.status_exit = 1;
		else
			win->img.status_exit = -1;
		return (win->img.status_exit);
	}
	if (search == W_KEY)
		win->map[y - 1][x] = 'P';
	if (search == S_KEY)
		win->map[y + 1][x] = 'P';
	if (search == D_KEY)
		win->map[y][x + 1] = 'P';
	if (search == A_KEY)
		win->map[y][x - 1] = 'P';
	win->map[y][x] = '0';
	win->img.ncout += 1;
	return (1);
}

void	ft_mouve_player_up(t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y] != NULL)
	{
		while (win->map[y][x++])
		{
			if (win->map[y][x] == 'P')
			{
				if (ft_check_pos_player(win, x, y, W_KEY))
					ft_fill_img_data(win, win->map);
				return ;
			}
		}
		x = 0;
		y++;
	}
	ft_fill_img_data(win, win->map);
}

void	ft_mouve_player_down(t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y] != NULL)
	{
		while (win->map[y][x++])
		{
			if (win->map[y][x] == 'P')
			{
				if (ft_check_pos_player(win, x, y, S_KEY))
					ft_fill_img_data(win, win->map);
				return ;
			}
		}
		x = 0;
		y++;
	}
}

void	ft_mouve_player_left(t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y] != NULL)
	{
		while (win->map[y][x++])
		{
			if (win->map[y][x] == 'P')
			{
				if (ft_check_pos_player(win, x, y, A_KEY))
					ft_fill_img_data(win, win->map);
				return ;
			}
		}
		x = 0;
		y++;
	}
}

void	ft_mouve_player_right(t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y] != NULL)
	{
		while (win->map[y][x++])
		{
			if (win->map[y][x] == 'P')
			{
				if (ft_check_pos_player(win, x, y, D_KEY))
					ft_fill_img_data(win, win->map);
				return ;
			}
		}
		x = 0;
		y++;
	}
}
