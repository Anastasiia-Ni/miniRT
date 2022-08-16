/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:09 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:38:21 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	cylinder_reflection(t_ray_var *v, int recurse, t_rt *rt)
{
	if (v->its.c_cylndr->reflect > 0 && recurse > 0)
	{
		v->r_ray = subtr_vec(multiply_vect(2.0 * dot_product(v->view, \
			v->normal), v->normal), v->view);
		v->reflect_color = trace_ray(rt, set_ray(v->point, v->r_ray, \
			EPSILON, INF), recurse - 1);
		v->color = add_vect(multiply_vect(1.0 - v->its.c_cylndr->reflect, \
		v->color), multiply_vect(v->its.c_cylndr->reflect, v->reflect_color));
	}
}

void	sphere_reflection(t_ray_var *v, t_ray ray, int recurse, t_rt *rt)
{
	(void)rt;
	(void)ray;
	if (v->its.c_sphere->reflect > 0 && recurse > 0)
	{
		v->r_ray = subtr_vec(multiply_vect(2.0 * dot_product(v->view, \
			v->normal), v->normal), v->view);
		v->reflect_color = trace_ray(rt, set_ray(v->point, v->r_ray, \
			EPSILON, INF), recurse - 1);
		v->color = add_vect(multiply_vect(1.0 - v->its.c_sphere->reflect, \
		v->color), multiply_vect(v->its.c_sphere->reflect, v->reflect_color));
	}
}

void	render_cylinder(t_ray_var *v, t_ray ray, int recurse, t_rt *rt)
{
	v->point = add_vect(rt->camera.coord, multiply_vect(v->its.closest_t, \
		ray.dir));
	v->normal = get_normal_for_cyl(v->point, v->its.c_cylndr);
	v->view = multiply_vect(-1, ray.dir);
	if (v->its.c_cylndr->is_chess)
	{
		v->even_color = v->its.c_cylndr->color;
		v->odd_color = inverse_color(v->even_color);
		v->color = chessboard(ray, v, v->its.c_cylndr->is_chess, 0);
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
			v->its.c_cylndr->specular, v->view), rt), v->color);
	}
	else
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
			v->its.c_cylndr->specular, v->view), rt), v->its.c_cylndr->color);
	cylinder_reflection(v, recurse, rt);
}

void	parab_reflection(t_ray_var *v, int recurse, t_rt *rt)
{
	if (v->its.c_parab->reflect > 0 && recurse > 0)
	{
		v->r_ray = subtr_vec(multiply_vect(2.0 * dot_product(v->view, \
			v->normal), v->normal), v->view);
		v->reflect_color = trace_ray(rt, set_ray(v->point, v->r_ray, \
			EPSILON, INF), recurse - 1);
		v->color = add_vect(multiply_vect(1.0 - v->its.c_parab->reflect, \
		v->color), multiply_vect(v->its.c_parab->reflect, v->reflect_color));
	}
}

void	render_parab(t_ray_var *v, t_ray ray, int recurse, t_rt *rt)
{
	v->point = add_vect(ray.origin, multiply_vect(v->its.closest_t, ray.dir));
	v->normal = get_normal_for_parab(v->point, v->its.c_parab);
	v->view = multiply_vect(-1, ray.dir);
	if (v->its.c_parab->is_chess)
	{
		v->even_color = v->its.c_parab->color;
		v->odd_color = inverse_color(v->even_color);
		v->color = chessboard(ray, v, v->its.c_parab->is_chess, 0);
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
		v->its.c_parab->specular, v->view), rt), v->color);
	}
	else
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
		v->its.c_parab->specular, v->view), rt), v->its.c_parab->color);
	parab_reflection(v, recurse, rt);
}
