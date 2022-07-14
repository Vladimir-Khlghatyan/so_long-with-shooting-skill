/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_and_lines_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:13:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:13:42 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_name_check(char *map_path)
{
	int	l;
	int	fd;

	l = ft_strlen(map_path);
	if (l < 4 || map_path[l - 4] != '.' || map_path[l - 3] != 'b' \
		|| map_path[l - 2] != 'e' || map_path[l - 1] != 'r')
	{
		ft_putstr("Error: non valid name of map!\n");
		exit(1);
	}
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error: the map file is unreadable!\n");
		exit(1);
	}
	else
		close (fd);
}

void	showerror(char *str, t_long *sl)
{
	ft_putstr(str);
	if (sl->map != NULL)
		tabfree(sl->map);
	if (sl->mlx != NULL && sl->win != NULL)
		mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
}

void	check_symbols(char *s, t_long *sl)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'P' && s[i] != 'E' \
			&& s[i] != 'C' && s[i] != 'T')
		{
			free(s);
			showerror("Error: not valied symbol in map!\n", sl);
		}
	}
}

void	first_or_last_str(char *s, t_long *sl)
{
	int	i;

	if (!s)
		showerror("Error: non valid map!\n", sl);
	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			showerror("Error: non valid map (first or last line)!\n", sl);
		i++;
	}
}

void	mid_str(char *s, t_long *sl)
{
	int	l;

	if (!s)
		showerror("Error: non valid map!\n", sl);
	l = ft_strlen(s);
	if (s[0] != '1' || s[l - 1] != '1')
		showerror("Error: non valid map (missing wall in line)!\n", sl);
}
