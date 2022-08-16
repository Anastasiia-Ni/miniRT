/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:22:17 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 10:48:38 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "../mlx/mlx.h"
# include "MiniRt.h"

# define WIDHT 1100.00
# define HEIGHT 680.00
# define INF 100000000
# define EPSILON 0.01

typedef struct s_rt	t_rt;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	float	width;
	float	height;
}			t_disp;

int		ft_key(int key, t_rt *rt);
int		exit_hook(t_rt *rt);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_free_display(t_disp	*display);

#endif
