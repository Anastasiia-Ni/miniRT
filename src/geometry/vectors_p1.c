/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:28:13 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 16:28:14 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Vector.h"

t_vect	new_vect(float x, float y, float z)
{
	t_vect	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vect	subtr_vec(t_vect v1, t_vect v2)
{
	t_vect	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

float	length_vect(t_vect res)
{
	float	temp;

	temp = sqrt((res.x * res.x) + (res.y * res.y) + (res.z * res.z));
	return (temp);
}

void	normalize_vect(t_vect *vect)
{
	float	length;

	length = length_vect(*vect);
	vect->x /= length;
	vect->y /= length;
	vect->z /= length;
}
