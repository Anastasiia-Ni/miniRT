/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shape_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:38:28 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:35:20 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_vect	get_normal_for_cyl(t_vect point, t_cylndr *cylndr)
{
	t_vect	tmp;
	t_vect	normal;

	tmp = subtr_vec(point, cylndr->coord);
	normal = subtr_vec(tmp, multiply_vect(dot_product(cylndr->orient, tmp), \
	cylndr->orient));
	normalize_vect(&normal);
	return (normal);
}

t_vect	get_normal_for_parab(t_vect point, t_parab *parab)
{
	t_vect	tmp;
	t_vect	normal;

	tmp = subtr_vec(point, parab->extremum);
	normal = subtr_vec(tmp, multiply_vect(dot_product(parab->orient, tmp), \
	parab->orient));
	normalize_vect(&normal);
	return (normal);
}

void	plane_reflection(t_ray_var *v, int recurse, t_rt *rt)
{
	if (v->its.c_plane->reflect > 0 && recurse > 0)
	{
		v->r_ray = subtr_vec(multiply_vect(2.0 * \
			dot_product(v->view, v->normal), v->normal), v->view);
		v->reflect_color = trace_ray(rt, \
			set_ray(v->point, v->r_ray, EPSILON, INF), recurse - 1);
		v->color = add_vect(multiply_vect(1.0 - v->its.c_plane->reflect, \
		v->color), multiply_vect(v->its.c_plane->reflect, v->reflect_color));
	}
}
