#include "../../miniRT/includes/miniRT.h"
#include "../../miniRT/includes/colors.h"
#include "../../miniRT/includes/canvas.h"
#include <stdio.h>

void	test_pixel_put(void);

int	check_color(t_color color)
{
	if (!equal(color.r, -0.5))
		return (0);
	if (!equal(color.g, 0.4))
		return (0);
	if (!equal(color.b, 1.7))
		return (0);
	return (1);
}

void	test_color()
{
	t_color color;
	
	color = get_color(-0.5, 0.4, 1.7);
	if (!check_color(color))
	{
		printf("colors do not match!\n");
	}
	else
		printf("colors match!\n");
}

void	add_colors_test(void)
{
	t_color	c1;
	t_color	c2;
	t_color	c3;

	c1 = get_color(0.9, 0.6, 0.75);
	c2 = get_color(0.7, 0.1, 0.25);
	c3 = add_colors(c1, c2);
	if (!equal(c3.r, 1.6) || !equal(c3.g, 0.7) || !equal(c3.b, 1.0))
		printf("addition fail!\n");
	else
		printf("addition success!\n");
}

void	sub_colors_test(void)
{
	t_color c1;
	t_color c2;
	t_color c3;

	c1 = get_color(0.9, 0.6, 0.75);
	c2 = get_color(0.7, 0.1, 0.25);
	c3 = sub_colors(c1, c2);
	if (!equal(c3.r, 0.2) || !equal(c3.g, 0.5) || !equal(c3.b, 0.5))
		printf("subtraction fail!\n");
	else
		printf("subtraction success!\n");
}

void	hadamard_product_test(void)
{
	t_color c1, c2, c3;

	c1 = get_color(1, 0.2, 0.4);
	c2 = get_color(0.9, 1, 0.1);
	c3 = hadamard_product(c1, c2);
	if (!equal(c3.r, 0.9) || !equal(c3.g, 0.2) || !equal(c3.b, 0.04))
		printf("hadamard product fail!\n");
	else
		printf("hadamard product success!\n");
}


int	render(t_data *data)
{
	int	i;
	int	j;

	t_color c1, c2, c3, c4;

	c1 = get_color(0.0, 0.4, 0.3);
	c2 = get_color(1.5, 0.0, 0.0);
	c3 = get_color(0, 0.5, 0);
	c4 = get_color(-0.5, 0, 1);

	if (data->win == NULL)
		return (1);
	i = 0;
	while (i < data->canvas.height)
	{
		j = 0;
		while (j < data->canvas.width)
			img_pix_put(data, j++, i, set_color(c1));
		++i;
	}
	img_pix_put(data, 1, 1, set_color(c2));
	img_pix_put(data, 2, 1, set_color(c3));
	img_pix_put(data, 4, 2, set_color(c4));
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	test_pixel_put(void)
{
	t_data data;

	data.canvas.width = 500;
	data.canvas.height = 300;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return ; //exit
	data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "MiniRT \\o/");
	if (data.win == NULL)
		return ; //exit
	data.img = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

int	render_test(t_data *data)
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

void	test_canvas_init(void)
{
	t_color		color;
	t_data		data;

	color = get_color(0.0, 0.0, 0.0);
	data.canvas = create_canvas(data.canvas, 20, 10, color);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return ; //exit
	data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "MiniRT \\o/");
	if (data.win == NULL)
		return ; //exit
	data.img = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    mlx_loop_hook(data.mlx, &render_test, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

// int	projectile_print(t_data *data)
// {
//     t_project   p, p1;
//     t_env       e, e1;

//     p = projectile(point(0, 1, 0), normalize(mult_tuple(vector(1, 1.8, 0), 11.25)));
//     e = environment(vector(0,-0.1,0), vector(-0.01,0,0));
//     int ticks = 0;
// 	int	i = 0;
//     while ((int)p.position.y > 0)
//     {
// 		if (((int)p.position.x) < 400 && ((int)p.position.y + 200)  < 400)
// 			img_pix_put(data, (int)p.position.x, (int)p.position.y +300, set_color(data->canvas.color));
//         // printf("Tick %d: Posição = (%f, %f, %f)\n", ticks, p.position.x, p.position.y, p.position.z);
// 		// if ((int)p.position.x < 1 || (int)p.position.y < 1)
// 		// 	break ;
//         p = tick(e, p);
//         ticks++;
//     }
// 	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// 	return (0);
// }



void draw_line(void *mlx, void *win, t_tuple start, t_tuple end) 
{
    int dx = (int)end.x - (int)start.x;
    int dy = (int)end.y - (int)start.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    double xIncrement = (double)dx / steps;
    double yIncrement = (double)dy / steps;

    double x = start.x;
    double y = start.y;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(mlx, win, (int)x, (int)y, 0xFFFFFF); // Desenhar pixel na cor branca
        x += xIncrement;
        y += yIncrement;
    }
}

int projectile_print(t_data *data)
{
    t_project p;
    t_env e;

    p = projectile(point(0, 1, 0), normalize(vector(1, 1.8, 0))); // Posição inicial à esquerda
    e = environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));
    
    while (p.position.x < 400)
    {
        int y_pos = (int)(p.position.y + 0.5); // Arredondar para a posição Y mais próxima

        if (y_pos >= 0 && y_pos < 400)
            draw_line(data->mlx, data->win, point(p.position.x, y_pos, 0), point(p.position.x + 1, y_pos, 0)); // Desenhar a linha do ponto atual para o próximo ponto

        p = tick(e, p);
    }
    
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

void	test_projectile_print(void)
{
	t_color		color;
	t_data		data;

	color = get_color(1, 0.0, 0.0);
	data.canvas = create_canvas(data.canvas, 400, 400, color);
	data.canvas.height = 400;
	data.canvas.width = 400;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return ; //exit
	data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "MiniRT \\o/");
	if (data.win == NULL)
		return ; //exit
	data.img = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    mlx_loop_hook(data.mlx, &projectile_print, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

int	main(void)
{
	// test_color();
	// add_colors_test();
	// sub_colors_test();
	// hadamard_product_test();
	// test_pixel_put();
	// test_canvas_init();
	test_projectile_print();
}
