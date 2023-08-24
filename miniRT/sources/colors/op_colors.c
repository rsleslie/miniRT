#include "../../includes/miniRT.h"

t_color	get_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	color_scale(double f, t_color color)
{
	return ((t_color){f * color.r, f * color.g, f * color.b});
}

int	set_color(t_color color)
{
	int	r;
	int	g;
	int	b;
	// t_color	nu_color;

	if (color.b < 0.0)
		color.b = 0.0;
	if (color.g < 0.0)
		color.g = 0.0;
	if (color.r < 0.0)
		color.r = 0.0;
	if (color.b > 1.0)
		color.b = 1.0;
	if (color.g > 1.0)
		color.g = 1.0;
	if (color.r > 1.0)
		color.r = 1.0;
	r = (int)(color.r * 255.0);
	g = (int)(color.g * 255.0);
	b = (int)(color.b * 255.0);
	// if (color.b > 1.0 && color.b >= color.r && color.b >= color.g)
	// 	nu_color = color_scale(1.0 / color.b, color);
	// if (color.g > 1.0 && color.g >= color.r && color.g >= color.b)
	// 	nu_color = color_scale(1.0 / color.g, color);
	// if (color.r > 1.0 && color.r >= color.g && color.r >= color.b)
	// 	nu_color = color_scale(1.0 / color.r, color);
	// r = (int)nu_color.r;
	// g = (int)nu_color.g;
	// b = (int)nu_color.b;

	return (0xFF << 24 | r << 16 | g << 8 | b);
}

t_color	add_colors(t_color c1, t_color c2)
{
	t_color	c3;
	
	c3.r = c1.r + c2.r;
	c3.g = c1.g + c2.g;
	c3.b = c1.b + c2.b;
	return (c3);	
}

t_color	sub_colors(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r - c2.r;
	c3.g = c1.g - c2.g;
	c3.b = c1.b - c2.b;
	return (c3);
}

t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r * c2.r;
	c3.g = c1.g * c2.g;
	c3.b = c1.b * c2.b;
	return (c3);
}
