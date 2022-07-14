/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:38:27 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:38:30 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rows_in_map(char *map_path, t_long *sl)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		showerror("Error: non valid map!\n", sl);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

char	**clear_new_lines_from_end_of_strings(char **map)
{
	int		i;
	char	*str;
	char	**new_map;

	i = -1;
	str = NULL;
	while (map[++i])
		str = ft_strjoin(str, map[i]);
	tabfree(map);
	new_map = ft_split(str, '\n');
	free(str);
	return (new_map);
}

int	create_map(char *map_path, t_long *sl)
{
	int		fd;
	int		y;
	int		i;

	fd = open(map_path, O_RDONLY);
	y = rows_in_map(map_path, sl);
	sl->map = (char **)malloc(sizeof(char *) * (y + 1));
	if (!(sl->map))
		showerror("Error: map can't be created!\n", sl);
	i = -1;
	while (++i < y)
		sl->map[i] = get_next_line(fd);
	close(fd);
	sl->map[i] = NULL;
	sl->map = clear_new_lines_from_end_of_strings(sl->map);
	sl->map_x = ft_strlen(sl->map[0]);
	sl->map_y = maplen(sl->map);
	return (0);
}

int	maplen(char **map)
{
	int	len;

	if (!map)
		return (0);
	len = 0;
	while (map[len])
		len++;
	return (len);
}

void	map_values_check(t_long *sl)
{
	char	*s;
	int		i;
	int		y;

	s = NULL;
	y = maplen(sl->map);
	i = -1;
	while (sl->map[++i])
		s = ft_strjoin(s, sl->map[i]);
	check_symbols(s, sl);
	free(s);
	i = -1;
	while (++i < y)
	{
		if (i == 0 || i == y - 1)
			first_or_last_str(sl->map[i], sl);
		else
			mid_str(sl->map[i], sl);
	}
}
