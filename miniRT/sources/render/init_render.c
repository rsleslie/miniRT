/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:33:43 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:04:49 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_render(t_data *data)
{
	t_c_world	c;
	t_tuple		up;

	data->w->ligth = point_light(data->w->rt->l.coordinates,
			color_scale(data->w->rt->l.brightness, data->w->rt->l.color));
	up = vector(0, 1, 0);
	c = camera(data->canvas.height, data->canvas.width, data->w->rt->c.fov);
	if (equal(dot(data->w->rt->c.vector, up), 1))
		up = vector(1, 0, 0);
	else if (equal(dot(data->w->rt->c.vector, up), -1))
		up = vector(-1, 0, 0);
	c.transform = view_transform(data->w->rt->c.coordinates,
			data->w->rt->c.vector, up);
	render_img(c, data);
	world_free(data->w);
}
