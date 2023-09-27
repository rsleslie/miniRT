/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:54:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:44:46 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	result;

	result = mult_tuple(normal, 2.0);
	result = mult_tuple(result, dot(in, normal));
	result = subtracting_vector(in, result);
	return (result);
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

t_var_lighting	init_values_lighting(t_m m,
	t_l light, t_comps comps, t_var_lighting	l)
{
	l.effective_color = hadamard_product(m.color, light.intensity);
	l.lightv = normalize(subtracting_point(light.position, comps.point));
	l.ambient = color_scale(m.ambient, l.effective_color);
	l.light_dot_normal = dot(l.lightv, comps.normalv);
	return (l);
}

t_color	lighting(t_m m, t_l light, t_comps comps, int in_shadow)
{
	t_var_lighting	l;

	l = init_values_lighting(m, light, comps, l);
	if (l.light_dot_normal < 0)
	{
		l.diffuse = get_color(0, 0, 0);
		l.specular = get_color(0, 0, 0);
	}
	else
	{
		l.diffuse = color_scale((m.diffuse * l.light_dot_normal),
				l.effective_color);
		l.reflectv = reflect(negate(l.lightv), comps.normalv);
		l.reflect_dot_eye = dot(l.reflectv, comps.eyev);
		if (l.reflect_dot_eye <= 0)
			l.specular = get_color(0, 0, 0);
		else
		{
			l.factor = pow(l.reflect_dot_eye, m.shininess);
			l.specular = color_scale((m.specular * l.factor), light.intensity);
		}
	}
	if (in_shadow)
		return (l.ambient);
	return (add_colors(add_colors(l.ambient, l.diffuse), l.specular));
}
