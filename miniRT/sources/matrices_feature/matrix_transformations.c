#include "../../includes/miniRT.h"

t_matrices	translation(float a, float b, float c)
{
	t_matrices	translation;

	translation = create_matrices(4, 4);
	translation.matrices[0][0] = 1;
	translation.matrices[1][1] = 1;
	translation.matrices[2][2] = 1;
	translation.matrices[3][3] = 1;
	translation.matrices[0][3] = a;
	translation.matrices[1][3] = b;
	translation.matrices[2][3] = c;
	return (translation);
}

t_matrices	scaling(float a, float b, float c)
{
	t_matrices	scaling;

	scaling = create_matrices(4, 4);
	scaling.matrices[0][0] = a;
	scaling.matrices[1][1] = b;
	scaling.matrices[2][2] = c;
	scaling.matrices[3][3] = 1;
	return (scaling);
}

t_matrices	rotate_x(float r)
{
	t_matrices	rotate_x;

	rotate_x = create_matrices(4, 4);
	rotate_x.matrices[0][0] = 1;
	rotate_x.matrices[1][1] = cos(r);
	rotate_x.matrices[1][2] = sin(r * -1);
	rotate_x.matrices[2][1] = sin(r);
	rotate_x.matrices[2][2] = cos(r);
	rotate_x.matrices[3][3] = 1;
	return (rotate_x);
}

t_matrices	rotate_y(float r)
{
	t_matrices	rotate_y;

	rotate_y = create_matrices(4, 4);
	rotate_y.matrices[0][0] = cos(r);
	rotate_y.matrices[0][2] = sin(r);
	rotate_y.matrices[1][1] = 1;
	rotate_y.matrices[2][0] = sin(r * -1);
	rotate_y.matrices[2][2] = cos(r);
	rotate_y.matrices[3][3] = 1;
	return (rotate_y);
}

t_matrices	rotate_z(float r)
{
	t_matrices	rotate_z;

	rotate_z = create_matrices(4, 4);
	rotate_z.matrices[0][0] = cos(r);
	rotate_z.matrices[0][1] = sin(r * -1);
	rotate_z.matrices[1][0] = sin(r);
	rotate_z.matrices[1][1] = cos(r);
	rotate_z.matrices[2][2] = 1;
	rotate_z.matrices[3][3] = 1;
	return (rotate_z);
}

t_matrices	shearing(t_shear shear)
{
	t_matrices	shearing;

	shearing = create_matrices(4, 4);
	shearing.matrices[0][0] = 1;
	shearing.matrices[1][1] = 1;
	shearing.matrices[2][2] = 1;
	shearing.matrices[3][3] = 1;
	shearing.matrices[0][1] = shear.xy;
	shearing.matrices[0][2] = shear.xz;
	shearing.matrices[1][0] = shear.yx;
	shearing.matrices[1][2] = shear.yz;
	shearing.matrices[2][0] = shear.zx;
	shearing.matrices[2][1] = shear.zy;
	return (shearing);
}