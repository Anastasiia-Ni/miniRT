/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:44:22 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:36:11 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	render_sphere(t_ray_var *v, t_ray ray, int recurse, t_rt *rt)
{
	v->point = add_vect(ray.origin, multiply_vect(v->its.closest_t, ray.dir));
	v->normal = subtr_vec(v->point, v->its.c_sphere->coord);
	v->normal = multiply_vect(1.0 / length_vect(v->normal), v->normal);
	v->view = multiply_vect(-1, ray.dir);
	if (v->its.c_sphere->is_chess)
	{
		v->even_color = v->its.c_sphere->color;
		v->odd_color = inverse_color(v->even_color);
		v->color = chessboard(ray, v, v->its.c_sphere->is_chess, 0);
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
			v->its.c_sphere->specular, v->view), rt), v->color);
	}
	else
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
		v->its.c_sphere->specular, v->view), rt), v->its.c_sphere->color);
	sphere_reflection(v, ray, recurse, rt);
}

void	render_plane(t_ray_var *v, t_ray ray, int recurse, t_rt *rt)
{
	v->point = add_vect(rt->camera.coord, \
		multiply_vect(v->its.closest_t, ray.dir));
	v->normal = v->its.c_plane->orient;
	v->normal = multiply_vect(1.0 / length_vect(v->normal), v->normal);
	v->view = multiply_vect(-1, ray.dir);
	if (v->its.c_plane->is_chess)
	{
		v->even_color = v->its.c_plane->color;
		v->odd_color = inverse_color(v->even_color);
		v->color = chessboard(ray, v, v->its.c_plane->is_chess, 1);
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
			v->its.c_plane->specular, v->view), rt), v->color);
	}
	else
		v->color = multiply_vect(lighting(light_var(v->point, v->normal, \
		v->its.c_plane->specular, v->view), rt), v->its.c_plane->color);
	plane_reflection(v, recurse, rt);
}

t_vect	trace_ray(t_rt *rt, t_ray ray, int recurse)
{
	t_ray_var	v;

	v.its.min = ray.min;
	v.its.max = ray.max;
	closest_its(ray.origin, rt, ray.dir, &v.its);
	if (v.its.hit_flag == -1)
		return (new_vect(0, 0, 0));
	if (v.its.c_sphere != NULL)
		render_sphere(&v, ray, recurse, rt);
	else if (v.its.c_plane != NULL)
		render_plane(&v, ray, recurse, rt);
	else if (v.its.c_cylndr != NULL)
		render_cylinder(&v, ray, recurse, rt);
	else if (v.its.c_parab != NULL)
		render_parab(&v, ray, recurse, rt);
	if (rt->ambient.ratio > 0.0)
	{
		v.color.x += (rt->ambient.color.x * rt->ambient.ratio) * \
			v.color.x / 255;
		v.color.y += (rt->ambient.color.y * rt->ambient.ratio) * \
			v.color.y / 255;
		v.color.z += (rt->ambient.color.z * rt->ambient.ratio) * \
			v.color.z / 255;
	}
	return (v.color);
}
