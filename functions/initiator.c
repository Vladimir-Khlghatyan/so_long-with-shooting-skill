/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:33 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/17 17:40:42 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initiator(t_long *sl)
{
	initiator1(sl);
	initiator2(sl);
}

void	initiator1(t_long *sl)
{
	sl->mlx = mlx_init();
	if (!sl->mlx)
		showerror("MLX was not initialized!\n", sl);
	sl->win = NULL;
	sl->map = NULL;
	sl->wxpm = 40;
	sl->hxpm = 40;
	sl->moves = 0;
	sl->loop_cnt = 0;
	sl->collected = 0;
	sl->shoot = 0;
	sl->shoot_cnt = 0;
}

void	initiator2(t_long *sl)
{
	sl->xpm[0] = mlx_xpm_file_to_image(sl->mlx, "./xpm/0.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[1] = mlx_xpm_file_to_image(sl->mlx, "./xpm/1.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[2] = mlx_xpm_file_to_image(sl->mlx, "./xpm/p1.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[3] = mlx_xpm_file_to_image(sl->mlx, "./xpm/p2.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[4] = mlx_xpm_file_to_image(sl->mlx, "./xpm/e.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[5] = mlx_xpm_file_to_image(sl->mlx, "./xpm/c1.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[6] = mlx_xpm_file_to_image(sl->mlx, "./xpm/c2.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[7] = mlx_xpm_file_to_image(sl->mlx, "./xpm/t1.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[8] = mlx_xpm_file_to_image(sl->mlx, "./xpm/t2.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[9] = mlx_xpm_file_to_image(sl->mlx, "./xpm/v.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[10] = mlx_xpm_file_to_image(sl->mlx, "./xpm/h.xpm", &sl->wxpm, \
		&sl->hxpm);
	sl->xpm[11] = mlx_xpm_file_to_image(sl->mlx, "./xpm/d.xpm", &sl->wxpm, \
		&sl->hxpm);
}
