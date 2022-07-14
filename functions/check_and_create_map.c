/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:05:09 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 17:05:15 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_and_create_map(char *map_path, t_long *sl)
{
	map_name_check(map_path);
	create_map(map_path, sl);
	map_values_check(sl);
	map_p_e_c_check(sl);
	map_rectangle_check(sl);
	return (1);
}

void	player_position(t_long *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == 'P')
			{
				sl->pl_x = x;
				sl->pl_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	map_p_e_c_check(t_long *sl)
{
	char	*s;
	int		i;
	int		pe[2];

	s = NULL;
	pe[0] = 0;
	pe[1] = 0;
	sl->coins = 0;
	i = -1;
	while (sl->map[++i])
		s = ft_strjoin(s, sl->map[i]);
	i = -1;
	while (s[++i])
	{
		if (s[i] == 'P')
			pe[0]++;
		if (s[i] == 'E')
			pe[1]++;
		if (s[i] == 'C')
			sl->coins++;
	}
	free(s);
	if (pe[0] != 1 || pe[1] != 1 || sl->coins < 1)
		showerror("Error: invalid number or players, exits or coins!\n", sl);
	player_position(sl);
}

void	map_rectangle_check(t_long *sl)
{
	int	y;
	int	i;

	y = maplen(sl->map);
	if (y < 3)
		showerror("Error: non valid map!\n", sl);
	i = 0;
	while (sl->map[i + 1])
	{
		if (ft_strlen(sl->map[i]) != ft_strlen(sl->map[i + 1]))
			showerror("Error: map is not rectangle!\n", sl);
		i++;
	}
}
