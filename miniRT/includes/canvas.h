#ifndef CANVAS_H
# define CANVAS_H

# include "colors.h"
# include "miniRT.h"

typedef struct s_color
{	
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	get_color(double r, double g, double b);
t_color	add_colors(t_color c1, t_color c2);
t_color	sub_colors(t_color c1, t_color c2);
t_color	hadamard_product(t_color c1, t_color c2);
t_color	color_scale(double f, t_color color);
int	set_color(t_color color);
t_color rgb_to_double(t_color color);

typedef struct s_canvas
{
	int	width;
	int	height;
	t_color	color;
}	t_canvas;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	t_canvas	canvas;
}	t_data;

void		init_canvas(t_data *data);
void		img_pix_put(t_data *data, int x, int y, int color);
int			terminate(t_data *data);
int			render(t_data *data);
int			handle_keypress(int keysym, t_data *data);
t_canvas	create_canvas(t_canvas canvas, int x, int y, t_color color);
int			render_canvas(t_data *data);

#endif
