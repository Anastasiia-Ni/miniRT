/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:38:18 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:27:10 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	init_screen(t_disp	*display)
{
	display->img.img = mlx_new_image(display->mlx, WIDHT, HEIGHT);
	if (display->img.img)
	{
		display->img.addr = mlx_get_data_addr(display->img.img,
				&display->img.bits_per_pixel,
				&display->img.line_length,
				&display->img.endian);
		return (1);
	}
	else
		return (0);
}

void	init_window(t_disp *display, t_rt *rt)
{
	display = (t_disp *)ft_calloc(1, sizeof(t_disp));
	if (!display)
		error_exit(-1, ERR_MEM_AL, rt);
	display->mlx = mlx_init();
	if (!display->height)
		display->height = HEIGHT;
	if (!display->width)
		display->width = WIDHT;
	if (!display->mlx)
		error_exit(-1, "Error: Init mlx failed", rt);
	display->mlx_win = mlx_new_window(display->mlx, WIDHT, HEIGHT, "MiniRt");
	if (!display->mlx_win)
		error_exit(-1, "Error: Init window failed", rt);
	if (!init_screen(display))
		error_exit(-1, "Error: Init screen failed", rt);
	calculate(display, rt);
}
