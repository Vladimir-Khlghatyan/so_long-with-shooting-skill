/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:38:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 00:56:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define RED_CROSS 17 

typedef struct s_long
{
	void	*mlx;
	void	*win;
	void	*xpm[12];
	void	*pxl;
	int		wxpm;
	int		hxpm;
	char	**map;
	int		map_x;
	int		map_y;
	int		pl_x;
	int		pl_y;
	int		coins;
	int		collected;
	int		moves;
	int		loop_cnt;
	int		shoot;
	int		shoot_cnt;
}				t_long;

/* libft_utils_1.c */
int		ft_putstr(char *str);
int		ft_numlen(int n);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putnmb(int n);

/* libft_utils_2.c */
char	**tabfree(char **tab);
char	**malloccheck(char **tab);
int		wordcount(const char *s, char c);
int		wordlen(const char *s, char c);
char	**ft_split(char const *s, char c);

/* get_next_line_utils.c */
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr_upd(const char *s, int c);
char	*ft_copy(char *s1, char *s2);
char	*read_from_file(int fd, char *temp);

/* get_next_line.c */
char	*upto_first_nl_or_0(char *str);
char	*after_nl(char *str);
char	*get_next_line(int fd);

/* map_name_and_lines_check.c */
void	map_name_check(char *map_path);
void	showerror(char *str, t_long *sl);
void	check_symbols(char *s, t_long *sl);
void	first_or_last_str(char *s, t_long *sl);
void	mid_str(char *s, t_long *sl);

/* map_values_check.c */
int		rows_in_map(char *map_path, t_long *sl);
char	**clear_new_lines_from_end_of_strings(char **map);
int		create_map(char *map_path, t_long *sl);
int		maplen(char **map);
void	map_values_check(t_long *sl);

/* check_and_create_map.c */
int		check_and_create_map(char *map_path, t_long *sl);
void	player_position(t_long *sl);
void	map_p_e_c_check(t_long *sl);
void	map_rectangle_check(t_long *sl);

/* createwindow.c */
int		ft_close(t_long *sl);
int		create_window(t_long *sl);
int		imagecode(char c);
int		load_xpm(t_long *sl);
int		load_xpm_with_animation(t_long *sl);

/* initiator.c */
void	initiator(t_long *sl);
void	initiator1(t_long *sl);
void	initiator2(t_long *sl);

/* moves.c */
void	move_to_next_cell(t_long *sl, char c, int step);
void	move_right(t_long *sl);
void	move_left(t_long *sl);
void	move_up(t_long *sl);
void	move_down(t_long *sl);

/* so_long.c */
void	print_in_terminal(t_long *sl);
int		key_hook(int keycode, t_long *sl);
int		so_long(t_long *sl);
void	reset_map(t_long *sl);

/* shoots.c */
void	shoot_up(t_long *sl);
void	shoot_down(t_long *sl);
void	shoot_left(t_long *sl);
void	shoot_right(t_long *sl);
void	shoot_reset_map(t_long *sl);

#endif
