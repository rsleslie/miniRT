#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

// void    normal_test1(void)
// {
//     t_sphere    s;
//     t_tuple  v;

//     s = sphere();
//     v = normal_at(s, point(1, 0, 0));
//     printf("x: %f\ny: %f\nz: %f\n", v.x, v.y, v.z);
// }

// void    normal_test2(void)
// {
//     t_sphere    s;
//     t_tuple  v;

//     s = sphere();
//     v = normal_at(s, point((sqrt(3) / 3), (sqrt(3) / 3), (sqrt(3) / 3)));
//     printf("TESTE 1\nx: %f\ny: %f\nz: %f\nw: %f\n", v.x, v.y, v.z, v.w);
// }

// void    normal_translated_test(void)
// {
//     t_sphere    s;
//     t_tuple     n;

//     s = sphere();
//     s = set_transform(s, translation((double)0, (double)1, 0));
//     n = normal_at(s, point((double)0, (double)1.70711, (double)-0.70711));
//     printf("\n\n\n TESTE 1\nx: %lf\ny: %lf\nz: %lf\nw: %lf\n", n.x, n.y, n.z, n.w);
// }

// void    normal_transformed_test(void)
// {
//     t_sphere    s;
//     t_tuple     n;
//     t_matrices  m;

//     s = sphere();
//     m = mult_matrices(scaling((double)1, (double)0.5, (double)1), rotate_z((double)PI/(double)5));
//     s = set_transform(s, m);
//     n = normal_at(s, point((double)0, (double)(sqrt((double)2) / (double)2), (double)-(sqrt((double)2) / (double)2)));
//     printf("\n\nTESTE 2 transformelf\nx: %lf\ny: %lf\nz: %lf\nw: %lf\n", n.x, n.y, n.z, n.w);
// }

void    reflecting_vector_45_test(void)
{
    t_tuple v;
    t_tuple n;
    t_tuple r;

    v = vector(1.0, -1.0, 0.0);
    n = vector(0.0, 1.0, 0.0);
    r = reflect(v, n);
    if (equal(r.x, 1) && equal(r.y, 1) && equal(r.z, 0))
        printf("reflecting 45 ok\n");
    else
        printf("reflecting 45 ko\n");
}

void    reflecting_slanted_test(void)
{
    t_tuple v;
    t_tuple n;
    t_tuple r;

    v = vector(0, -1.0, 0);
    n = vector((sqrt(2.0) / 2.0), (sqrt(2.0) / 2.0), 0.0);
    r = reflect(v, n);
    if (equal(r.x, 1) && equal(r.y, 0) && equal(r.z, 0))
        printf("reflecting slanted ok\n");
    else
        printf("reflecting slanted KO\n");
}

void    point_light_test(void)
{
    t_color intensity;
    t_tuple position;
    t_l     light;

    intensity = get_color(1, 1, 1);
    position = point(0, 0, 0);
    light = point_light(position, intensity);
    if (equal_tuple(light.position, position) && equal(light.intensity.r, intensity.r) && equal(light.intensity.g, intensity.g) && equal(light.intensity.b, intensity.b))
        printf("point light ok\n");
    else
        printf("point light KO\n");
}

void    default_material_test(void)
{
    t_m m;

    m = material();
    printf("color: %lf, %lf, %lf\n", m.color.r, m.color.g, m.color.b);
    if(equal(m.ambient, 0.1) && equal(m.diffuse, 0.9) && equal(m.specular, 0.9) && equal(m.shininess, 200.0))
        printf("material ok\n");
    else
        printf("material KO\n");
    
}

void    sphere_material_test(void)
{
    t_sphere    s;
    
    s = sphere();
    printf("color: %lf, %lf, %lf\n", s.material.color.r, s.material.color.g, s.material.color.b);
    if(equal(s.material.ambient, 0.1) && equal(s.material.diffuse, 0.9) && equal(s.material.specular, 0.9) && equal(s.material.shininess, 200.0))
        printf("material ok\n");
    else
        printf("material KO\n");
}

void    eye_between_test(void)
{
    t_tuple eyev;
    t_tuple normalv;
    t_l     light;
    t_color result;
    t_tuple position;

    eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    position = point (0, 0, 0);
    light = point_light(point(0, 0, -10), get_color(1, 1, 1));
    result = lighting(material(), light, position, eyev, normalv);
    if (equal(result.r, 1.9) && equal(result.g, 1.9) && equal(result.b, 1.9))
        printf("eye between ok\n");
    else
        printf("eye between KO\n");
}

void    eye_45_test(void)
{
    t_tuple eyev;
    t_tuple normalv;
    t_l     light;
    t_color result;
    t_tuple position;

    eyev = vector(0, (sqrt(2) / 2), -(sqrt(2) / 2));
    normalv = vector(0, 0, -1);
    position = point (0, 0, 0);
    light = point_light(point(0, 0, -10), get_color(1, 1, 1));
    result = lighting(material(), light, position, eyev, normalv);
     if (equal(result.r, 1.0) && equal(result.g, 1.0) && equal(result.b, 1.0))
        printf("eye 45 ok\n");
    else
        printf("eye 45 KO\n");
}

void    light_45_test(void)
{
    t_tuple eyev;
    t_tuple normalv;
    t_l     light;
    t_color result;
    t_tuple position;

    eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    position = point (0, 0, 0);
    light = point_light(point(0, 10, -10), get_color(1, 1, 1));
    result = lighting(material(), light, position, eyev, normalv);
   printf("color: %0.4lf, %lf, %lf\n", result.r, result.g, result.b);
    if (equal(result.r, 0.7364) && equal(result.g, 0.7364) && equal(result.b, 0.7364))
        printf("light 45 ok\n");
    else
        printf("light 45 KO\n");
}

void    light_eye_opposite_test(void)
{
    t_tuple eyev;
    t_tuple normalv;
    t_l     light;
    t_color result;
    t_tuple position;

    eyev = vector(0, -(sqrt(2) / 2), -(sqrt(2) / 2));
    normalv = vector(0, 0, -1);
    position = point (0, 0, 0);
    light = point_light(point(0, 10, -10), get_color(1, 1, 1));
    result = lighting(material(), light, position, eyev, normalv);
   printf("color: %0.4lf, %lf, %lf\n", result.r, result.g, result.b);
    if (equal(result.r, 1.6364) && equal(result.g, 1.6364) && equal(result.b, 1.6364))
        printf("light eye opposite ok\n");
    else
        printf("light eye opposite KO\n");
}

void    light_behind_test(void)
{
    t_tuple eyev;
    t_tuple normalv;
    t_l     light;
    t_color result;
    t_tuple position;

    eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    position = point (0, 0, 0);
    light = point_light(point(0, 0, 10), get_color(1, 1, 1));
    result = lighting(material(), light, position, eyev, normalv);
    if (equal(result.r, 0.1) && equal(result.g, 0.1) && equal(result.b, 0.1))
        printf("light behind ok\n");
    else
        printf("light behind KO\n");
}

int main()
{
    // normal_test1();
    // normal_test2();
    normal_translated_test();
    normal_transformed_test();
    reflecting_vector_45_test();
    reflecting_slanted_test();
    point_light_test();
    default_material_test();
    sphere_material_test();
    eye_between_test();
    eye_45_test();
    light_45_test();
    light_eye_opposite_test();
    light_behind_test();
    return (0);
}