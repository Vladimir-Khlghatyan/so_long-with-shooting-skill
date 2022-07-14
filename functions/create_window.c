/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:53:15 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:19 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_long *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
	return (0);
}

int	create_window(t_long *sl)
{
	sl->win = mlx_new_window(sl->mlx, (sl->wxpm) * (sl->map_x), \
		(sl->hxpm) * (sl->map_y), "So long!");
	mlx_hook(sl->win, RED_CROSS, 0, ft_close, sl);
	mlx_key_hook(sl->win, key_hook, sl);
	ft_putstr("Coins: 0	Moves: 0");
	return (0);
}

int	imagecode(char c)
{
	int	i;

	i = 0;
	if (c == '0')
		i = 0;
	else if (c == '1')
		i = 1;
	else if (c == 'P')
		i = 2;
	else if (c == 'E')
		i = 4;
	else if (c == 'C')
		i = 5;
	else if (c == 'T')
		i = 7;
	else if (c == 'V')
		i = 9;
	else if (c == 'H')
		i = 10;
	else if (c == 'D')
		i = 11;
	return (i);
}

int	load_xpm(t_long *sl)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < sl->map_y)
	{
		x = 0;
		while (x < sl->map_x)
		{
			i = imagecode(sl->map[y][x]);
			if (i == 2 && sl->collected == sl->coins)
				i = 3;
			if (i == 5 && sl->loop_cnt % 30 <= 15)
				i = 6;
			if (i == 7 && sl->loop_cnt % 40 <= 20)
				i = 8;
			mlx_put_image_to_window(sl->mlx, sl->win, sl->xpm[i], x * sl->wxpm, \
				y * sl->wxpm);
			x++;
		}
		y++;
	}
	reset_map(sl);
	return (0);
}

int	load_xpm_with_animation(t_long *sl)
{
	sl->loop_cnt++;
	if (sl->loop_cnt == 40)
		sl->loop_cnt = 0;
	mlx_clear_window(sl->mlx, sl->win);
	load_xpm(sl);
	return (0);
}
