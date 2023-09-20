#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

void    normal_test1(void)
{
    t_sphere    s;
    t_tuple  v;

    s = sphere();
    v = normal_at(s, point(1, 0, 0));
    printf("x: %f\ny: %f\nz: %f\n", v.x, v.y, v.z);
}

void    normal_test2(void)
{
    t_sphere    s;
    t_tuple  v;

    s = sphere();
    v = normal_at(s, point((sqrt(3) / 3), (sqrt(3) / 3), (sqrt(3) / 3)));
    printf("x: %f\ny: %f\nz: %f\nw: %f\n", v.x, v.y, v.z, v.w);
}

void    normal_translated_test(void)
{
    t_sphere    s;
    t_tuple     n;

    // s = sphere();
    s = set_transform(s, translation(0, 1, 0));
    n = normal_at(s, point(0, 1.70711, -0.70711));
    printf("translated\nx: %f\ny: %f\nz: %f\nw: %f\n", n.x, n.y, n.z, n.w);
}

void    normal_transformed_test(void)
{
    t_sphere    s;
    t_tuple     n;
    t_matrices  m;

    s = sphere();
    // m = id_matrix(m);
    m = mult_matrices(scaling(1, 0.5, 1), rotate_z((float)(PI / 5.0)));
    s = set_transform(s, m);
    printf("%f\n", sqrt(2.0) / 2.0);
    n = normal_at(s, point(0, (float)(sqrt(2.0) / 2.0), (float)-(sqrt(2.0) / 2.0)));
    printf("transformed\nx: %f\ny: %f\nz: %f\nw: %f\n", n.x, n.y, n.z, n.w);
}

int main()
{
    normal_test1();
    normal_test2();
    normal_translated_test();
    normal_transformed_test();
    return (0);
}