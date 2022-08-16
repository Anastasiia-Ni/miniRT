/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:33:59 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:19:52 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_lightvar	light_var(t_vect point, t_vect normal, float specular, t_vect view)
{
	t_lightvar	var;

	var.point = point;
	var.normal = normal;
	var.specular = specular;
	var.view = view;
	return (var);
}

void	init_light_var(t_lightvar *var, t_rt *rt, t_vect point)
{
	var->intensity = 0.0;
	if (rt->ambient.ratio > 0)
		var->intensity += rt->ambient.ratio;
	var->vec_light = subtr_vec(rt->light.coord, point);
	var->its.min = EPSILON;
	var->its.max = 1.0;
}

float	lighting(t_lightvar v, t_rt *rt)
{
	v.length_n = length_vect(v.normal);
	v.length_v = length_vect(v.view);
	init_light_var(&v, rt, v.point);
	closest_its(v.point, rt, v.vec_light, &v.its);
	if (v.its.hit_flag != -1)
		return (v.intensity);
	v.normal_dot = dot_product(v.normal, v.vec_light);
	if (v.normal_dot > 0)
		v.intensity += rt->light.ratio * v.normal_dot / \
			(v.length_n * length_vect(v.vec_light));
	if (v.specular != -1)
	{
		v.r = subtr_vec(multiply_vect(2.0 * dot_product(v.normal, \
		v.vec_light), v.normal), v.vec_light);
		v.r_dot_v = dot_product(v.r, v.view);
		if (v.r_dot_v > 0)
			v.intensity += rt->light.ratio * pow(v.r_dot_v / \
				(length_vect(v.r) * v.length_v), v.specular);
	}
	return (v.intensity);
}

void	calculate(t_disp *display, t_rt *rt)
{
	int		x;
	int		y;
	t_vect	color;
	t_vect	dir;

	y = -HEIGHT / 2;
	x = 0;
	while (y < HEIGHT / 2)
	{
		x = -WIDHT / 2;
		while (x < WIDHT / 2)
		{
			dir = convert_viewport(x, y, rt);
			color = trace_ray(rt, set_ray(rt->camera.coord, dir, 1, INF), 3);
			ft_putpixel(x, y, clamp(0.0, 255.0, color), display);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(display->mlx, display->mlx_win, \
	display->img.img, 0, 0);
	mlx_hook(display->mlx_win, 17, 0, exit_hook, rt);
	mlx_key_hook(display->mlx_win, ft_key, rt);
	mlx_loop(display->mlx);
}
