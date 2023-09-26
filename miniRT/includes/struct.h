#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct t_project
{
	t_tuple position;
	t_tuple velocity;
}	t_project;

typedef struct s_env
{
	t_tuple gravity;
	t_tuple wind;
}	t_env;

typedef struct s_color
{	
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_canvas
{
	int	width;
	int	height;
	t_color	color;
}	t_canvas;


typedef struct s_matrices
{
	int		x;
	int		y;
	double	matrices[4][4];
}	t_matrices;

typedef struct	s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shear;

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

typedef struct s_m
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_m;

typedef struct s_sphere
{
	double		radius;
	t_matrices	id;
	t_matrices	transpose;
	t_matrices	transform;
	t_m			material;
}	t_sphere;
typedef struct s_cy
{
	t_tuple	coordinates;
	t_tuple	vector;
	double	diameter;
	double	heigth;
	t_color	color;
}	t_cy;

typedef struct s_pl
{
	t_tuple	coordinates;
	t_tuple	vector;
	t_color	color;
}	t_pl;

typedef struct s_sp
{
	t_tuple		coordinates;
	double		diameter;
	t_color		color;
	t_matrices	inverse;
	t_matrices	transpose;
	t_matrices	m;
	t_m			material;
}	t_sp;

typedef struct s_l
{
	t_tuple	coordinates;
	t_tuple	position;
	t_color	intensity;
	double	brightness;
	t_color	color;
}	t_l;

typedef struct s_c
{
	t_tuple	coordinates;
	t_tuple	vector;
	int		fov;
}	t_c;

typedef struct s_a
{
	t_color	color;
	double	ratio;
}	t_a;


typedef struct s_objects
{
	t_a		a;
	t_c		c;
	t_l		l;
	int		n_sp;
	int		n_pl;
	int		n_cy;
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;
}	t_objects;

typedef struct s_world
{
    t_sphere	s1;
    t_sphere	s2;
    t_l			ligth;
	t_data		*data;
	t_objects	*rt;
}	t_world;

typedef struct s_rays
{
	t_tuple	origin;
	t_tuple	direction;
}	t_rays;


typedef struct s_intersection
{
	double		t;
	t_sp		object;
	t_sphere	s_world;
}	t_intersection;

typedef struct s_xs
{
	int				count;
	t_intersection	data[1024];
}	t_xs;



typedef struct  s_comps
{
    t_intersection  t;
	t_sp			sp;
    t_sphere        object;
    t_tuple         point;
    t_tuple         eyev;
    t_tuple         normalv;
    int             inside;
}   t_comps;

typedef struct s_c_world
{
    t_color     color;
    double      hsize;
    double      vsize;
    double      field_of_view;
    double      pixel_size;
    double      half_width;
    double      half_height;
    t_matrices  transform;
}   t_c_world;

#endif