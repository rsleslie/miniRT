#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

void testePOSITION()
{
    t_rays r;

    r = ray(point(2, 3, 4), vector(1,0,0));
    if (compare_tuple(position(r, 0), point(2, 3, 4)))
        printf("TESTE 1 SUCESS\n");
    if (compare_tuple(position(r, 1), point(3, 3, 4)))
        printf("TESTE 2 SUCESS\n");
    if (compare_tuple(position(r, -1), point(1, 3, 4)))
        printf("TESTE 3 SUCESS\n");
    if (compare_tuple(position(r, 2.5), point(4.5, 3, 4)))
        printf("TESTE 4 SUCESS\n");
    
}

void testeRAYS()
{
    t_tuple origin;
    t_tuple direction;
    t_rays  r;

    origin = point(1, 2, 3);
    direction = vector(4, 5, 6);
    r = ray(origin, direction);
    if (compare_tuple(r.origin, origin) == TRUE)
        printf("Origin são iguais\n");
    if (compare_tuple(r.direction, direction) == TRUE)
        printf("Direction são iguais\n");
}

void    testeSphereIntersect()
{
    t_rays r;
    t_sphere s;
    t_xs    xs;

    r = ray(point(0, 0, -5), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    
    if (equal(xs.count, 2))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    if (equal(xs.data[0].t, 4))
        printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    else
        printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    if (equal(xs.data[1].t, 6))
        printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    else
        printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersect2()
{
    t_rays      r;
    t_sphere    s;
    t_xs        xs;

    r = ray(point(0, 1, -5), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    
    if (equal(xs.count, 2))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    if (equal(xs.data[0].t, 5))
        printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    else
        printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    if (equal(xs.data[1].t, 5))
        printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    else
        printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersect3()
{
    t_rays      r;
    t_sphere    s;
    t_xs        xs;

    r = ray(point(0, 0, 0), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    
    if (equal(xs.count, 2))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    if (equal(xs.data[0].t, -1))
        printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    else
        printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    if (equal(xs.data[1].t, 1))
        printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    else
        printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersect4()
{
    t_rays      r;
    t_sphere    s;
    t_xs        xs;

    r = ray(point(0, 2, -5), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    
    if (equal(xs.count, 0))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    // if (equal(xs.data[0].t, -1))
    //     printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    // else
    //     printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    // if (equal(xs.data[1].t, 1))
    //     printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    // else
    //     printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersect5()
{
    t_rays      r;
    t_sphere    s;
    t_xs        xs;

    r = ray(point(0, 0, 5), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    
    if (equal(xs.count, 2))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    if (equal(xs.data[0].t, -6))
        printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    else
        printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    if (equal(xs.data[1].t, -4))
        printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    else
        printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersection()
{
    t_xs                xs;
    t_sphere            s;
    t_intersection      i1;

    s = sphere();
    i1 = intersection(3.5, s);
  

    if (equal(i1.t, 3.5))
        printf("TESTE 1 OK i1.t = %f\n", i1.t);
    else
        printf("FALHA teste 1 i1.t = %f\n", i1.t);
    if (equal(i1.object.radius, s.radius))
        printf("TESTE 2 OK i1.object.radius] = %f\n", i1.object.radius);
    else
        printf("Falha teste 2 i1.object.radius = %f\n", i1.object.radius);
}

void    testeSphereIntersection1()
{
    t_xs                xs;
    t_sphere            s;
    t_intersection      i1;
    t_intersection      i2;

    s = sphere();
    i1 = intersection(1, s);
    i2 = intersection(2, s);
    write(1, "ola\n", 4);
    xs = intersections(i1, i2);
    if (equal(xs.count, 2))
        printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);
    if (equal(xs.data[0].t, 1))
        printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
    else
        printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
    if (equal(xs.data[1].t, 2))
        printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
    else
        printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
}

void    testeSphereIntersection2()
{
    t_xs                xs;
    t_sphere            s;
    t_rays               r;

    r = ray(point(0, 0, -5), vector(0, 0, 1));
    s = sphere();
    xs = intersect(s, r);
    if (equal(xs.count, 2))
    printf("TESTE 1 OK xs.count = %i\n", xs.count);
    else
        printf("FALHA teste 1 xs.count = %d\n", xs.count);

    if (equal(xs.data[0].object.radius, s.radius))
        printf("TESTE 2 OK s[0] = %i\n",xs.data[0].object.radius);
    else
        printf("Falha teste 2 s[0] = %i\n", xs.data[0].object.radius);
    if (equal(xs.data[1].object.radius, s.radius))
        printf("TESTE 3 ok s[1] = %i\n", xs.data[0].object.radius);
    else
        printf("FALHA teste 3 s[1] = %i\n", xs.data[0].object.radius);
}


int main()
{
    // testePOSITION();
    // testeRAYS();
    // testeSphereIntersect();
    // testeSphereIntersect2();
    // testeSphereIntersect3();
    // testeSphereIntersect4();
    // testeSphereIntersect5();
    testeSphereIntersection();
    testeSphereIntersection1();
    // testeSphereIntersection2();
    

    return (0);
}