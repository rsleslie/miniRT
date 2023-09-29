/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:32:57 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 14:38:50 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	putting_it_in_the_window(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	init_render_mlx(t_data *data)
{
	t_color		color;

	data->canvas.height = 50;
	data->canvas.width = 50;
	color = get_color(1, 0.0, 0.0);
	data->canvas = create_canvas(data->canvas, data->canvas.height,
			data->canvas.width, color);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->win = mlx_new_window(data->mlx, data->canvas.width,
			data->canvas.height, "MiniRT \\o/");
	if (data->win == NULL)
		return ;
	data->img = mlx_new_image(data->mlx,
			data->canvas.width, data->canvas.height);
	if (data->img == NULL)
		return ;
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line_len, &data->endian);
	init_render(data);
	mlx_loop_hook(data->mlx, &putting_it_in_the_window, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, close_esc, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, close_x, data);
	mlx_loop(data->mlx);
}
