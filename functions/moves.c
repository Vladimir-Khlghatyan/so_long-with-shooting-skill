/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:53:15 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:19 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_next_cell(t_long *sl, char c, int step)
{
	if (c == 'x')
	{
		sl->map[sl->pl_y][sl->pl_x + step] = 'P';
		sl->map[sl->pl_y][sl->pl_x] = '0';
		sl->pl_x = sl->pl_x + step;
	}
	else if (c == 'y')
	{
		sl->map[sl->pl_y + step][sl->pl_x] = 'P';
		sl->map[sl->pl_y][sl->pl_x] = '0';
		sl->pl_y = sl->pl_y + step;
	}
	sl->moves++;
	print_in_terminal(sl);
}

void	move_right(t_long *sl)
{
	if (sl->map[sl->pl_y][sl->pl_x + 1] == '0')
		move_to_next_cell(sl, 'x', 1);
	else if (sl->map[sl->pl_y][sl->pl_x + 1] == 'C')
	{
		sl->collected++;
		move_to_next_cell(sl, 'x', 1);
	}
	else if (sl->map[sl->pl_y][sl->pl_x + 1] == 'E')
	{
		if (sl->collected == sl->coins)
		{
			move_to_next_cell(sl, 'x', 1);
			showerror("\n\33[1;32mYou won!\n", sl);
		}
	}
	else if (sl->map[sl->pl_y][sl->pl_x + 1] == 'T')
	{
		move_to_next_cell(sl, 'x', 1);
		showerror("\n\33[1;31mYou lost!\n", sl);
	}
}

void	move_left(t_long *sl)
{
	if (sl->map[sl->pl_y][sl->pl_x - 1] == '0')
		move_to_next_cell(sl, 'x', -1);
	else if (sl->map[sl->pl_y][sl->pl_x - 1] == 'C')
	{
		sl->collected++;
		move_to_next_cell(sl, 'x', -1);
	}
	else if (sl->map[sl->pl_y][sl->pl_x - 1] == 'E')
	{
		if (sl->collected == sl->coins)
		{
			move_to_next_cell(sl, 'x', -1);
			showerror("\n\33[1;32mYou won!\n", sl);
		}
	}
	else if (sl->map[sl->pl_y][sl->pl_x - 1] == 'T')
	{
		move_to_next_cell(sl, 'x', -1);
		showerror("\n\33[1;31mYou lost!\n", sl);
	}
}

void	move_up(t_long *sl)
{
	if (sl->map[sl->pl_y - 1][sl->pl_x] == '0')
		move_to_next_cell(sl, 'y', -1);
	else if (sl->map[sl->pl_y - 1][sl->pl_x] == 'C')
	{
		sl->collected++;
		move_to_next_cell(sl, 'y', -1);
	}
	else if (sl->map[sl->pl_y - 1][sl->pl_x] == 'E')
	{
		if (sl->collected == sl->coins)
		{
			move_to_next_cell(sl, 'y', -1);
			showerror("\n\33[1;32mYou won!\n", sl);
		}
	}
	else if (sl->map[sl->pl_y - 1][sl->pl_x] == 'T')
	{
		move_to_next_cell(sl, 'y', -1);
		showerror("\n\33[1;31mYou lost!\n", sl);
	}
}

void	move_down(t_long *sl)
{
	if (sl->map[sl->pl_y + 1][sl->pl_x] == '0')
		move_to_next_cell(sl, 'y', 1);
	else if (sl->map[sl->pl_y + 1][sl->pl_x] == 'C')
	{
		sl->collected++;
		move_to_next_cell(sl, 'y', 1);
	}
	else if (sl->map[sl->pl_y + 1][sl->pl_x] == 'E')
	{
		if (sl->collected == sl->coins)
		{
			move_to_next_cell(sl, 'y', 1);
			showerror("\n\33[1;32mYou won!\n", sl);
		}
	}
	else if (sl->map[sl->pl_y + 1][sl->pl_x] == 'T')
	{
		move_to_next_cell(sl, 'y', 1);
		showerror("\n\33[1;31mYou lost!\n", sl);
	}
}
