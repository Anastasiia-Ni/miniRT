/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:13 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:34:09 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

float	get_disc(t_vect origin, t_vect dir, t_cylndr *cylndr)
{
	float	a;
	float	b;
	float	c;
	float	half_b;
	t_vect	oc;

	a = dot_product(dir, dir) - pow(dot_product(dir, cylndr->orient), 2);
	oc = subtr_vec(origin, cylndr->coord);
	half_b = dot_product(dir, oc) - (dot_product(oc, cylndr->orient) * \
			dot_product(dir, cylndr->orient));
	c = dot_product(oc, oc) - pow(dot_product(oc, cylndr->orient), 2) - \
			(cylndr->radius * cylndr->radius);
	b = half_b * half_b;
	return (b - (a * c));
}

float	get_roots1(t_vect origin, t_vect dir, t_cylndr *cylndr, float sqrtd)
{
	float	a;
	float	half_b;
	t_vect	oc;

	a = dot_product(dir, dir) - pow(dot_product(dir, cylndr->orient), 2);
	oc = subtr_vec(origin, cylndr->coord);
	half_b = dot_product(dir, oc) - (dot_product(oc, cylndr->orient)
			* dot_product(dir, cylndr->orient));
	return ((-half_b - sqrtd) / a);
}

float	get_roots2(t_vect origin, t_vect dir, t_cylndr *cylndr, float sqrtd)
{
	float	a;
	float	half_b;
	t_vect	oc;

	a = dot_product(dir, dir) - pow(dot_product(dir, cylndr->orient), 2);
	oc = subtr_vec(origin, cylndr->coord);
	half_b = dot_product(dir, oc) - (dot_product(oc, cylndr->orient)
			* dot_product(dir, cylndr->orient));
	return ((-half_b + sqrtd) / a);
}

int	intsect_cylinder(t_vect origin, t_vect dir, t_cylndr *cylndr, float *dist)
{
	float	tmp;
	float	h;
	float	discr;

	discr = get_disc(origin, dir, cylndr);
	if (discr < 0)
		return (0);
	tmp = get_roots1(origin, dir, cylndr, sqrt(discr));
	h = dot_product(origin, cylndr->orient) + tmp * dot_product(dir, \
		cylndr->orient) - dot_product(cylndr->coord, cylndr->orient);
	if (h < 0 || h > cylndr->height)
	{
		tmp = get_roots2(origin, dir, cylndr, sqrt(discr));
		h = dot_product(origin, cylndr->orient) + tmp * dot_product(dir, \
		cylndr->orient) - dot_product(cylndr->coord, cylndr->orient);
		if (h < 0 || h > cylndr->height)
			return (0);
	}
	*dist = tmp;
	return (1);
}

void	check_cylinder(t_vect origin, t_rt *rt, t_vect dir, t_inter *its)
{
	t_cylndr	*closest_cylndr;
	t_cylndr	*cylndr;
	float		closest_t;
	float		dist;

	closest_t = INF;
	cylndr = rt->cylndr;
	closest_cylndr = NULL;
	while (cylndr != NULL)
	{
		if (intsect_cylinder(origin, dir, cylndr, &dist))
		{
			if (dist < closest_t && its->min < dist && dist < its->max)
			{
				closest_cylndr = cylndr;
				closest_t = dist;
			}
		}
		cylndr = cylndr->next;
	}
	if (closest_cylndr != NULL && closest_t < its->closest_t)
	{
		its->c_cylndr = closest_cylndr;
		put_intersect(its, closest_t, 'c');
	}
}
