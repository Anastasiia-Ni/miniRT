/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:43:57 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:38:38 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	closest_its(t_vect origin, t_rt *rt, t_vect dir, t_inter *its)
{
	its->hit_flag = -1;
	its->c_cylndr = NULL;
	its->c_plane = NULL;
	its->c_sphere = NULL;
	its->c_parab = NULL;
	its->closest_t = INF;
	check_sphere(origin, rt, dir, its);
	check_cylinder(origin, rt, dir, its);
	check_plane(origin, rt, dir, its);
	check_paraboloid(origin, rt, dir, its);
}

t_ray	set_ray(t_vect origin, t_vect dir, float min, float max)
{
	t_ray	temp;

	temp.origin = origin;
	temp.dir = dir;
	temp.min = min;
	temp.max = max;
	return (temp);
}

t_vect	clamp(float min, float max, t_vect value)
{
	if (value.x > max)
		value.x = max;
	else if (value.x < min)
		value.x = min;
	if (value.y > max)
		value.y = max;
	else if (value.y < min)
		value.y = min;
	if (value.z > max)
		value.z = max;
	else if (value.z < min)
		value.z = min;
	return (value);
}

void	ft_putpixel(int x, int y, t_vect color, t_disp *display)
{
	char	*temp;
	int		position;

	x = WIDHT / 2 + x;
	y = HEIGHT / 2 - y - 1;
	position = x * 4 + 4 * WIDHT * y;
	temp = display->img.addr;
	temp[position] = color.z;
	temp[position + 1] = color.y;
	temp[position + 2] = color.x;
}
