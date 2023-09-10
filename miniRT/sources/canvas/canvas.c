/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:39:38 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 17:49:37 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_canvas(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->win = mlx_new_window(data->mlx,
			data->canvas.width, data->canvas.height, "MiniRT");
	if (data->win == NULL)
		return ;
	data->img = mlx_new_image(data->mlx,
			data->canvas.width, data->canvas.height);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line_len, &data->endian);
	mlx_loop_hook(data->mlx, &render_canvas, &data);
	mlx_loop(data->mlx);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	data->addr[x * 4 + y * data->canvas.width * 4] = color;
	data->addr[x * 4 + y * data->canvas.width * 4 + 1] = color >> 8;
	data->addr[x * 4 + y * data->canvas.width * 4 + 2] = color >> 16;
	data->addr[x * 4 + y * data->canvas.width * 4 + 3] = color >> 24;
}

t_canvas	create_canvas(t_canvas canvas, int x, int y, t_color color)
{
	canvas.width = x;
	canvas.height = y;
	canvas.color.r = color.r;
	canvas.color.g = color.g;
	canvas.color.b = color.b;
	return (canvas);
}

int	render_canvas(t_data *data)
{
	int			i;
	int			j;

	if (data->win == NULL)
		return (1);
	i = 0;
	while (i < data->canvas.height)
	{
		j = 0;
		while (j < data->canvas.width)
			img_pix_put(data, j++, i, set_color(data->canvas.color));
		++i;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
