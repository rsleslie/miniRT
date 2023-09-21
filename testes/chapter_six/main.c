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
    printf("TESTE 1\nx: %f\ny: %f\nz: %f\nw: %f\n", v.x, v.y, v.z, v.w);
}

void    normal_translated_test(void)
{
    t_sphere    s;
    t_tuple     n;

    s = sphere();
    s = set_transform(s, translation((double)0, (double)1, 0));
    n = normal_at(s, point((double)0, (double)1.70711, (double)-0.70711));
    printf("\n\n\n TESTE 1\nx: %lf\ny: %lf\nz: %lf\nw: %lf\n", n.x, n.y, n.z, n.w);
}



void    normal_transformed_test(void)
{
    t_sphere    s;
    t_tuple     n;
    t_matrices  m;

    s = sphere();
    m = mult_matrices(scaling((double)1, (double)0.5, (double)1), rotate_z((double)PI/(double)5));
    s = set_transform(s, m);
    n = normal_at(s, point((double)0, (double)(sqrt((double)2) / (double)2), (double)-(sqrt((double)2) / (double)2)));
    printf("\n\nTESTE 2 transformelf\nx: %lf\ny: %lf\nz: %lf\nw: %lf\n", n.x, n.y, n.z, n.w);
}

int main()
{
    // normal_test1();
    // normal_test2();
    normal_translated_test();
    normal_transformed_test();
    return (0);
}