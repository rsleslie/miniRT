/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:54:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 19:57:20 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	normal_at(t_sp s, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(s.inverse, p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(s.transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	result;

	result = mult_tuple(normal, 2.0);
	result = mult_tuple(result, dot(in, normal));
	result = subtracting_vector(in, result);
	return(result);
}

t_l	point_light(t_tuple	position, t_color intensity)
{
	t_l	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}

t_m	material(void)
{
	t_m	m;

	m.color = get_color(1, 1, 1);
    m.ambient = 0.1;
    m.diffuse = 0.9;
    m.specular = 0.9;
    m.shininess = 200.0;
	return (m);
}

t_color	lighting(t_m m, t_l light, t_tuple position, t_tuple eyev, t_tuple normalv, int in_shadow)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	t_color	ambient;
	t_color	diffuse;
	t_color specular;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;

	effective_color = hadamard_product(m.color, light.intensity);
	lightv = normalize(subtracting_point(light.position, position));
	ambient = color_scale(m.ambient, effective_color);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = get_color(0, 0, 0);
		specular = get_color(0, 0, 0);
	}
	else
	{
		if (!in_shadow)
			diffuse = color_scale((m.diffuse * light_dot_normal), effective_color);
		reflectv = reflect(negate(lightv), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = get_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			if (!in_shadow)
				specular = color_scale((m.specular * factor), light.intensity);
		}
	}
	return (add_colors(add_colors(ambient, diffuse), specular));
}
