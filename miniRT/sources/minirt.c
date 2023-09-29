/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:52:20 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 11:43:02 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void    world_free(t_world *w)
{
    if (w->rt->sp != NULL)
        free(w->rt->sp);
    if (w->rt->cy != NULL)
        free(w->rt->cy);
    if (w->rt->pl != NULL)
        free(w->rt->pl);
    free(w->rt);
    free(w);
}
int	close_esc(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	close_x(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int putting_it_in_the_window(t_data *data)
{ 
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

void    init_render(t_data *data)
{
    t_c_world   c;

    data->w->ligth = point_light(data->w->rt->l.coordinates, color_scale(data->w->rt->l.brightness, data->w->rt->l.color));
    c = camera(data->canvas.height, data->canvas.width, data->w->rt->c.fov);
    c.transform = view_transform(data->w->rt->c.coordinates, data->w->rt->c.vector, vector(0, 1, 0));
    render_img(c, data);
    world_free(data->w);
}

void	init_render_mlx(t_data *data)
{
	t_color		color;

    data->canvas.height = 400;
    data->canvas.width = 400;
	color = get_color(1, 0.0, 0.0);
	data->canvas = create_canvas(data->canvas, data->canvas.height, data->canvas.width, color);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->win = mlx_new_window(data->mlx, data->canvas.width, data->canvas.height, "MiniRT \\o/");
	if (data->win == NULL)
		return ;
	data->img = mlx_new_image(data->mlx, data->canvas.width, data->canvas.height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    init_render(data);
    mlx_loop_hook(data->mlx, &putting_it_in_the_window, data);
    mlx_hook(data->win, KeyPress, KeyPressMask, close_esc, &data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, close_x, &data);
    mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int main(int argc, char **argv)
{
    t_data *data;
    t_world *w;

    if (argc != 2)
    {
        ft_putendl_fd("Error\nWrong number of arguments.", 2);
        return (0);
    }
    data = (t_data *)malloc(sizeof(t_data));
    w = (t_world *)malloc(sizeof(t_world));
    w->rt = (t_objects *)malloc(sizeof(t_objects));
    w->rt->sp = NULL;
    w->rt->cy = NULL;
    w->rt->pl = NULL;
    if (!parser(&w->rt, argv[1]))
    {
        world_free(w);
        exit(0);
    }
    data->w = w;
    data->has_rendered = FALSE;
    init_render_mlx(data);
    return (0);
}
