/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:35:23 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:28:43 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_vect	get_look_right(t_camera *camera)
{
	t_vect	rand;
	t_vect	right;

	rand = new_vect(0, 1, 0);
	normalize_vect(&rand);
	right = cross_product(rand, camera->orient);
	normalize_vect(&right);
	return (right);
}

t_vect	get_look_up(t_camera *camera, t_vect right)
{
	t_vect	up;

	up = cross_product(camera->orient, right);
	normalize_vect(&up);
	return (up);
}

t_vect	multiply_vectors(t_camera *cam, t_vect right, t_vect up, t_vect tmp)
{
	t_vect	res;

	res.x = tmp.x * right.x + tmp.y * up.x + \
			tmp.z * cam->orient.x + cam->coord.x;
	res.y = tmp.x * right.y + tmp.y * up.y + \
			tmp.z * cam->orient.y + cam->coord.y;
	res.z = tmp.x * right.z + tmp.y * up.z + \
			tmp.z * cam->orient.z + cam->coord.z;
	return (res);
}

t_vect	get_direction(int x, int y, t_rt *rt)
{
	float	fov;
	float	new_width;
	float	new_hight;
	float	x_pix;
	float	y_pix;

	fov = (float)rt->camera.fov;
	new_width = (tan(fov / 2 * (M_PI / 180))) * 2;
	new_hight = new_width / (WIDHT / HEIGHT);
	x_pix = new_width / WIDHT;
	y_pix = new_hight / HEIGHT;
	return (new_vect(x * x_pix, y * y_pix, 1.0));
}

t_vect	convert_viewport(int x, int y, t_rt *rt)
{
	t_vect	dir;
	t_vect	right;
	t_vect	up;
	t_vect	new_v;

	right = get_look_right(&rt->camera);
	up = get_look_up(&rt->camera, right);
	new_v = new_vect(0, 0, 0);
	rt->camera.origin = multiply_vectors(&rt->camera, right, up, new_v);
	dir = get_direction(x, y, rt);
	dir = multiply_vectors(&rt->camera, right, up, dir);
	dir = subtr_vec(dir, rt->camera.origin);
	normalize_vect(&dir);
	return (dir);
}
