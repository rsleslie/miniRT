#include "../../miniRT/includes/miniRT.h"
#include "../../miniRT/includes/colors.h"
#include "../../miniRT/includes/canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	char	*addr;
// 	int		bpp; /* bits per pixel */
// 	int		line_len;
// 	int		endian;
// }	t_img;

// typedef struct s_data
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_img	img;
// 	int		cur_img;
// }	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = data->bpp - 8;
    pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

// int render_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(data, j++, i, color);
		}
		++i;
	}
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

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background(data, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

	/* Setup hooks */ 
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	data.addr = mlx_get_data_addr(data.img, &data.bpp,
			&data.line_len, &data.endian);

	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}