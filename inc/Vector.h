/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:24:18 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 16:24:19 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vect
{
	float		x;
	float		y;
	float		z;
}				t_vect;

t_vect	subtr_vec(t_vect v1, t_vect v2);
float	length_vect(t_vect res);
void	normalize_vect(t_vect *vect);
float	dot_product(t_vect vect1, t_vect vect2);
t_vect	cross_product(t_vect v1, t_vect v2);
t_vect	add_vect(t_vect v1, t_vect v2);
t_vect	multiply_vect(float scalar, t_vect vect);
t_vect	new_vect(float x, float y, float z);

#endif