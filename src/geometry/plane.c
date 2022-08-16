/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:27:49 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 21:35:19 by Sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	put_intersect_cont(t_inter *its, char f)
{
	if (f == 'c')
	{
		its->c_sphere = NULL;
		its->c_plane = NULL;
		its->c_parab = NULL;
	}
	else if (f == 'b')
	{
		its->c_sphere = NULL;
		its->c_plane = NULL;
		its->c_cylndr = NULL;
	}
}

void	put_intersect(t_inter *its, float closest_t, char f)
{
	if (f == 'p')
	{
		its->c_cylndr = NULL;
		its->c_sphere = NULL;
		its->c_parab = NULL;
	}
	else if (f == 's')
	{
		its->c_cylndr = NULL;
		its->c_plane = NULL;
		its->c_parab = NULL;
	}
	else
		put_intersect_cont(its, f);
	its->closest_t = closest_t;
	its->hit_flag = 1;
}

float	intersect_plane(t_vect origin, t_vect dir, t_plane *plane, float *ip)
{
	float	denom;
	t_vect	pl;

	denom = dot_product(plane->orient, dir);
	if (denom != 0)
	{
		pl = subtr_vec(plane->coord, origin);
		*ip = dot_product(pl, plane->orient) / denom;
		return (*ip >= 0);
	}
	return (0);
}

void	check_plane(t_vect origin, t_rt *rt, t_vect dir, t_inter *its)
{
	t_plane	*plane;
	t_plane	*closest_plane;
	float	ip;
	float	closest_t;

	closest_t = INF;
	closest_plane = NULL;
	plane = rt->plane;
	ip = 0;
	while (plane != NULL)
	{
		intersect_plane(origin, dir, plane, &ip);
		if (ip < closest_t && its->min < ip && ip < its->max)
		{
			closest_t = ip;
			closest_plane = plane;
		}
		plane = plane->next;
	}
	if (closest_plane != NULL && closest_t < its->closest_t)
	{
		its->c_plane = closest_plane;
		put_intersect(its, closest_t, 'p');
	}
}
