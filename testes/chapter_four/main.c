#include "../../miniRT/includes/miniRT.h"
#include "../../miniRT/includes/colors.h"
#include "../../miniRT/includes/canvas.h"
#include <stdio.h>

void	test_translation(void)
{
	t_tuple	point;
	t_matrices	t;

	t = translation(5.0, -3.0, 2.0);
	point = tuples(-3.0, 4.0, 5.0, 1.0);

	point = mult_matrix_tuple(t, point);
	printf("===test 1===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	test_translation_inv(void)
{
	t_tuple	point;
	t_matrices	inv;
	
	inv = translation(5.0, -3.0, 2.0);
	point = tuples(-3.0, 4.0, 5.0, 1.0);
	inv = inverse(inv);
	point = mult_matrix_tuple(inv, point);
	printf("===test 2===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	test_translation_vector(void)
{
	t_tuple	vector;
	t_matrices	t;

	t = translation(5.0, -3.0, 2.0);
	vector = tuples(-3.0, 4.0, 5.0, 0.0);
	vector = mult_matrix_tuple(t, vector);
	printf("===test 3===\nx: %f\ny: %f\nz: %f\n", vector.x, vector.y, vector.z);
}

void	test_scaling(void)
{
	t_matrices	transform;
	t_tuple	point;

	transform = scaling(2.0, 3.0, 4.0);
	point = tuples(-4.0, 6.0, 8.0, 1.0);
	point = mult_matrix_tuple(transform, point);
	printf("===test 4===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	test_scaling_vector(void)
{
	t_tuple	vector;
	t_matrices	transform;

	transform = scaling(2.0, 3.0, 4.0);
	vector = tuples(-4.0, 6.0, 8.0, 0.0);
	vector = mult_matrix_tuple(transform, vector);
	printf("===test 5===\nx: %f\ny: %f\nz: %f\n", vector.x, vector.y, vector.z);
}

void	test_scaling_inv(void)
{
	t_tuple	point;
	t_matrices	inv;
	
	inv = scaling(2.0, 3.0, 4.0);
	point = tuples(-4.0, 6.0, 8.0, 1.0);
	inv = inverse(inv);
	point = mult_matrix_tuple(inv, point);
	printf("===test 6===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	reflection_test(void)
{
	t_matrices	transform;
	t_tuple	point;

	transform = scaling(-1.0, 1.0, 1.0);
	point = tuples(-4.0, 6.0, 8.0, 1.0);
	point = mult_matrix_tuple(transform, point);
	printf("===test 7===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	test_rotate_x(void)
{
	t_matrices	half_quarter;
	t_matrices	full_quarter;
	t_tuple		point;

	point = tuples(0.0, 1.0, 0.0, 1.0);
	half_quarter = rotate_x(PI / 4);
	full_quarter = rotate_x(PI / 2);
	point = mult_matrix_tuple(half_quarter, point);
	printf("===test 8.1===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
	point = tuples(0.0, 1.0, 0.0, 1.0);
	point = mult_matrix_tuple(full_quarter, point);
	printf("===test 8.2===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

void	test_shearing(void)
{
	t_shear	shear;
	t_matrices	transform;
	t_tuple	point;

	shear.xy = 1.0;
	shear.xz = 0;
	shear.yx = 0;
	shear.yz = 0;
	shear.zx = 0;
	shear.zy = 0;
	transform = shearing(shear);
	// printf("xy: %f\n", transform.matrices[0][1]);
	point = tuples(2.0, 3.0, 4.0, 1.0);
	point = mult_matrix_tuple(transform, point);
	printf("===test 9===\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
}

int	main(void)
{
	test_translation();
	test_translation_inv();
	test_translation_vector();
	test_scaling();
	test_scaling_vector();
	test_scaling_inv();
	reflection_test();
	test_rotate_x();
	test_shearing();
}
