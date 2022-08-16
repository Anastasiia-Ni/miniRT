/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:46:52 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 22:07:31 by Sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	free_all(t_rt *ptr_rt)
{
	if (ptr_rt && ptr_rt->display)
		ft_free_display(ptr_rt->display);
	if (ptr_rt)
	{
		free_plane_sphere(&ptr_rt);
		free_cyl_parab(&ptr_rt);
		free (ptr_rt);
	}
}

int	exit_hook(t_rt *rt)
{
	free_all(rt);
	exit(1);
}

int	ft_key(int key, t_rt *rt)
{
	if (key == 53)
	{
		free_all(rt);
		exit(1);
	}
	return (0);
}

void	ft_free_display(t_disp	*display)
{
	if (display)
	{
		if (display->img.img)
			mlx_destroy_image(display->mlx, display->img.img);
		if (display->mlx_win)
			mlx_destroy_window(display->mlx, display->mlx_win);
		if (display->mlx)
			free(display->mlx);
		free(display);
	}
}
