#include "../../includes/miniRT.h"

t_tuple	normal_at(t_sphere s, t_tuple p)
{
	t_tuple p1;
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	int i = -1;
	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			printf("%f\t", s.transform.matrices[i][j]);
		printf("\n");
	}
	
	object_point = mult_matrix_tuple(inverse(s.transform), p);
	p1 = point(0, 0, 0);
	object_normal = subtracting_point(p, p1);
	world_normal = mult_matrix_tuple(transpose(inverse(s.transform)), object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}
