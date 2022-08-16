/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:22:49 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:35:27 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "Minilibx.h"
# include "Vector.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"

# define MAX_SIZE 10000
# define ERR_MEM_AL "Error: allocating memory\n"

typedef struct s_ambient
{
	float	ratio;
	t_vect	color;
}			t_ambient;

typedef struct s_camera
{
	t_vect	coord;
	t_vect	orient;
	int		fov;
	t_vect	origin;
}			t_camera;

typedef struct s_light
{
	t_vect	coord;
	float	ratio;
	t_vect	color;
}			t_light;

typedef struct s_sphere
{
	t_vect			coord;
	float			radius;
	float			specular;
	float			reflect;
	float			is_chess;
	t_vect			color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct s_plane
{
	t_vect			coord;
	t_vect			orient;
	t_vect			color;
	float			reflect;
	float			specular;
	float			is_chess;
	struct s_plane	*next;
}					t_plane;

typedef struct s_cylndr
{
	t_vect			coord;
	t_vect			orient;
	t_vect			color;
	float			radius;
	float			height;
	float			specular;
	float			reflect;
	float			is_chess;
	struct s_cylndr	*next;
}					t_cylndr;

typedef struct s_parab
{
	t_vect			extremum;
	t_vect			orient;
	t_vect			color;
	float			height;
	float			specular;
	float			reflect;
	float			is_chess;
	struct s_parab	*next;
}					t_parab;

typedef struct s_intersect
{
	t_plane		*c_plane;
	t_sphere	*c_sphere;
	t_cylndr	*c_cylndr;
	t_parab		*c_parab;
	float		closest_t;
	float		min;
	float		max;
	int			hit_flag;
}				t_inter;

typedef struct s_rt
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylndr	*cylndr;
	t_parab		*parab;
	t_disp		*display;
}				t_rt;

typedef struct s_traceray
{
	t_vect	origin;
	t_vect	dir;
	float	min;
	float	max;
}			t_ray;

typedef struct s_rayvars
{
	t_vect	point;
	t_vect	normal;
	t_vect	color;
	t_vect	view;
	t_inter	its;
	t_vect	r_ray;
	t_vect	reflect_color;
	t_vect	even_color;
	t_vect	odd_color;
}			t_ray_var;

typedef struct s_parsecheck
{
	int	ambient;
	int	light;
	int	camera;
}		t_parsecheck;

typedef struct s_lightvar
{
	float	intensity;
	t_vect	vec_light;
	float	normal_dot;
	float	length_n;
	float	length_v;
	t_vect	r;
	float	r_dot_v;
	float	t_max;
	t_inter	its;
	t_vect	normal;
	t_vect	point;
	float	specular;
	t_vect	view;
}			t_lightvar;

int			parse(t_rt *rt, char *arg);
double		rt_atod(const char *str, t_rt *rt);
void		init_window(t_disp *display, t_rt *rt);
double		ft_value(char *str, char delimeter, int reset, t_rt *rt);
int			comma_check(char *str);
int			alpha_check(char **line);
int			array_size(char **line);
int			parse_set_rt(t_rt *rt, int fd);
int			parse_ambient(char **line, t_rt *rt, t_parsecheck *min_check);
int			parse_camera(char **line, t_rt *rt, t_parsecheck *min_check);
int			parse_light(char **line, t_rt *rt, t_parsecheck *min_check);
int			parse_sphere(char **line, t_rt *rt);
int			parse_plane(char **line, t_rt *rt);
int			parse_cylinder(char **line, t_rt *rt);
int			parse_paraboloid(char **line, t_rt *rt);
void		ft_calculate(t_disp *display, t_rt *rt);
t_vect		trace_ray(t_rt *rt, t_ray ray, int recurse);
t_ray		set_ray(t_vect origin, t_vect dir, float min, float max);
void		error_exit(int code, char *str, t_rt *rt);
void		ray_tracing(t_rt *rt);
float		is_ray_sphere(t_camera camera, float *ray, t_sphere *sphere);
void		calculate(t_disp *display, t_rt *rt);
void		free_all(t_rt *ptr_rt);
void		free_cyl_parab(t_rt **ptr_rt);
void		free_plane_sphere(t_rt **ptr_rt);
t_vect		convert_viewport(int x, int y, t_rt *rt);
void		put_intersect(t_inter *its, float closest_t, char f);
int			trace_ray_plane(t_rt *rt, float *dir);
void		render_plane(t_ray_var *v, t_ray ray, int recurse, t_rt *rt);
void		render_sphere(t_ray_var *v, t_ray ray, int recurse, t_rt *rt);
void		render_parab(t_ray_var *v, t_ray ray, int recurse, t_rt *rt);
void		render_cylinder(t_ray_var *v, t_ray ray, int recurse, t_rt *rt);
void		parab_reflection(t_ray_var *v, int recurse, t_rt *rt);
void		sphere_reflection(t_ray_var *v, t_ray ray, int recurse, t_rt *rt);
void		cylinder_reflection(t_ray_var *v, int recurse, t_rt *rt);
void		plane_reflection(t_ray_var *v, int recurse, t_rt *rt);
t_vect		get_normal_for_parab(t_vect point, t_parab *parab);
t_vect		get_normal_for_cyl(t_vect point, t_cylndr *cylndr);
void		closest_its(t_vect origin, t_rt *rt, t_vect dir, t_inter *its);
void		check_sphere(t_vect origin, t_rt *rt, t_vect dir, t_inter *its);
void		check_cylinder(t_vect origin, t_rt *rt, t_vect dir, t_inter *its);
void		check_plane(t_vect origin, t_rt *rt, t_vect dir, t_inter *its);
void		check_paraboloid(t_vect origin, t_rt *rt, t_vect dir, t_inter *its);
t_vect		clamp(float min, float max, t_vect value);
void		ft_putpixel(int x, int y, t_vect color, t_disp *display);
t_vect		inverse_color(t_vect color);
t_vect		chessboard(t_ray ray, t_ray_var *v, float koef, int is_plane);
t_lightvar	light_var(t_vect point, t_vect normal, float specular, t_vect view);
float		lighting(t_lightvar v, t_rt *rt);

#endif