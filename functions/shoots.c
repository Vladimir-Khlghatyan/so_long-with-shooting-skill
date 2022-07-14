/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:53:15 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:19 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	shoot_up(t_long *sl)
{
	int	y;

	y = 1;
	while (sl->map[sl->pl_y - y][sl->pl_x] == '0')
	{
		sl->map[sl->pl_y - y][sl->pl_x] = 'V';
		y++;
	}
	if (sl->map[sl->pl_y - y][sl->pl_x] == 'T')
		sl->map[sl->pl_y - y][sl->pl_x] = 'D';
	sl->shoot = 1;
}

void	shoot_down(t_long *sl)
{
	int	y;

	y = 1;
	while (sl->map[sl->pl_y + y][sl->pl_x] == '0')
	{
		sl->map[sl->pl_y + y][sl->pl_x] = 'V';
		y++;
	}
	if (sl->map[sl->pl_y + y][sl->pl_x] == 'T')
		sl->map[sl->pl_y + y][sl->pl_x] = 'D';
	sl->shoot = 1;
}

void	shoot_left(t_long *sl)
{
	int	x;

	x = 1;
	while (sl->map[sl->pl_y][sl->pl_x - x] == '0')
	{
		sl->map[sl->pl_y][sl->pl_x - x] = 'H';
		x++;
	}
	if (sl->map[sl->pl_y][sl->pl_x - x] == 'T')
		sl->map[sl->pl_y][sl->pl_x - x] = 'D';
	sl->shoot = 1;
}

void	shoot_right(t_long *sl)
{
	int	x;

	x = 1;
	while (sl->map[sl->pl_y][sl->pl_x + x] == '0')
	{
		sl->map[sl->pl_y][sl->pl_x + x] = 'H';
		x++;
	}
	if (sl->map[sl->pl_y][sl->pl_x + x] == 'T')
		sl->map[sl->pl_y][sl->pl_x + x] = 'D';
	sl->shoot = 1;
}

void	shoot_reset_map(t_long *sl)
{
	int	x;
	int	y;

	y = 0;
	while (y < sl->map_y)
	{
		x = 0;
		while (x < sl->map_x)
		{
			if (sl->map[y][x] == 'V' || sl->map[y][x] == 'H' || \
				sl->map[y][x] == 'D')
				sl->map[y][x] = '0';
			x++;
		}
		y++;
	}
}
