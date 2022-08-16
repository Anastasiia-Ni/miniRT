/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:28:19 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 16:28:27 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Vector.h"

float	dot_product(t_vect vect1, t_vect vect2)
{
	float	res;

	res = (vect1.x * vect2.x) + (vect1.y * vect2.y) + (vect1.z * vect2.z);
	return (res);
}

t_vect	cross_product(t_vect v1, t_vect v2)
{
	t_vect	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vect	add_vect(t_vect v1, t_vect v2)
{
	t_vect	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vect	multiply_vect(float scalar, t_vect vect)
{
	t_vect	res;

	res.x = vect.x * scalar;
	res.y = vect.y * scalar;
	res.z = vect.z * scalar;
	return (res);
}
