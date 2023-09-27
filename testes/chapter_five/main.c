#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

// void testePOSITION()
// {
//     t_rays r;

//     r = ray(point(2, 3, 4), vector(1,0,0));
//     if (compare_tuple(position(r, 0), point(2, 3, 4)))
//         printf("TESTE 1 SUCESS\n");
//     if (compare_tuple(position(r, 1), point(3, 3, 4)))
//         printf("TESTE 2 SUCESS\n");
//     if (compare_tuple(position(r, -1), point(1, 3, 4)))
//         printf("TESTE 3 SUCESS\n");
//     if (compare_tuple(position(r, 2.5), point(4.5, 3, 4)))
//         printf("TESTE 4 SUCESS\n");
    
// }

// void testeRAYS()
// {
//     t_tuple origin;
//     t_tuple direction;
//     t_rays  r;

//     origin = point(1, 2, 3);
//     direction = vector(4, 5, 6);
//     r = ray(origin, direction);
//     if (compare_tuple(r.origin, origin) == TRUE)
//         printf("Origin são iguais\n");
//     if (compare_tuple(r.direction, direction) == TRUE)
//         printf("Direction são iguais\n");
// }

// void    testeSphereIntersect()
// {
//     t_rays r;
//     t_sphere s;
//     t_xs    xs;

//     r = ray(point(0, 0, -5), vector(0, 0, 1));
//     s = sphere();
//     xs = intersect(s, r);
    
//     if (equal(xs.count, 2))
//         printf("TESTE 1 OK xs.count = %i\n", xs.count);
//     else
//         printf("FALHA teste 1 xs.count = %d\n", xs.count);
//     if (equal(xs.data[0].t, 4))
//         printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
//     else
//         printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
//     if (equal(xs.data[1].t, 6))
//         printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
//     else
//         printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// }

// // void    testeSphereIntersect2()
// // {
// //     t_rays      r;
// //     t_sphere    s;
// //     t_xs        xs;

//         // xs.count = 0;
// //     r = ray(point(0, 1, -5), vector(0, 0, 1));
// //     s = sphere();
// //     xs = intersect(s, r);
    
// //     if (equal(xs.count, 2))
// //         printf("TESTE 1 OK xs.count = %i\n", xs.count);
// //     else
// //         printf("FALHA teste 1 xs.count = %d\n", xs.count);
// //     if (equal(xs.data[0].t, 5))
// //         printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
// //     else
// //         printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
// //     if (equal(xs.data[1].t, 5))
// //         printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
// //     else
// //         printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// // }

// // void    testeSphereIntersect3()
// // {
// //     t_rays      r;
// //     t_sphere    s;
// //     t_xs        xs;

// //     r = ray(point(0, 0, 0), vector(0, 0, 1));
// //     s = sphere();
// //     xs = intersect(s, r);
    
// //     if (equal(xs.count, 2))
// //         printf("TESTE 1 OK xs.count = %i\n", xs.count);
// //     else
// //         printf("FALHA teste 1 xs.count = %d\n", xs.count);
// //     if (equal(xs.data[0].t, -1))
// //         printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
// //     else
// //         printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
// //     if (equal(xs.data[1].t, 1))
// //         printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
// //     else
// //         printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// // }

// void    testeSphereIntersect4()
// {
//     t_rays      r;
//     t_sphere    s;
//     t_xs        xs;

//     r = ray(point(0, 2, -5), vector(0, 0, 1));
//     s = sphere();
//     xs = intersect(s, r);
    
//     if (equal(xs.count, 0))
//         printf("TESTE 1 OK xs.count = %i\n", xs.count);
//     else
//         printf("FALHA teste 1 xs.count = %d\n", xs.count);
//     // if (equal(xs.data[0].t, -1))
//     //     printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
//     // else
//     //     printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
//     // if (equal(xs.data[1].t, 1))
//     //     printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
//     // else
//     //     printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// }

// // void    testeSphereIntersect5()
// // {
// //     t_rays      r;
// //     t_sphere    s;
// //     t_xs        xs;

// //     r = ray(point(0, 0, 5), vector(0, 0, 1));
// //     s = sphere();
// //     xs = intersect(s, r);
    
// //     if (equal(xs.count, 2))
// //         printf("TESTE 1 OK xs.count = %i\n", xs.count);
// //     else
// //         printf("FALHA teste 1 xs.count = %d\n", xs.count);
// //     if (equal(xs.data[0].t, -6))
// //         printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
// //     else
// //         printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
// //     if (equal(xs.data[1].t, -4))
// //         printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
// //     else
// //         printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// // }

// // void    testeSphereIntersection()
// // {
// //     t_xs                xs;
// //     t_sphere            s;
// //     t_intersection      i1;

// //     s = sphere();
// //     i1 = intersection(3.5, s);
  

// //     if (equal(i1.t, 3.5))
// //         printf("TESTE 1 OK i1.t = %f\n", i1.t);
// //     else
// //         printf("FALHA teste 1 i1.t = %f\n", i1.t);
// //     if (equal(i1.object.radius, s.radius))
// //         printf("TESTE 2 OK i1.object.radius] = %f\n", i1.object.radius);
// //     else
// //         printf("Falha teste 2 i1.object.radius = %f\n", i1.object.radius);
// // }

// // void    testeSphereIntersection1()
// // {
// //     t_xs                xs;
// //     t_sphere            s;
// //     t_intersection      i1;
// //     t_intersection      i2;

// //     s = sphere();
// //     i1 = intersection(1, s);
// //     i2 = intersection(2, s);
// //     write(1, "ola\n", 4);
// //     xs = intersections(i1, xs);
// //     xs = intersections(i2, xs);
// //     if (equal(xs.count, 2))
// //         printf("TESTE 1 OK xs.count = %i\n", xs.count);
// //     else
// //         printf("FALHA teste 1 xs.count = %d\n", xs.count);
// //     if (equal(xs.data[0].t, 1))
// //         printf("TESTE 2 OK xs[0] = %f\n", xs.data[0].t);
// //     else
// //         printf("Falha teste 2 xs[0] = %f\n", xs.data[0].t);
// //     if (equal(xs.data[1].t, 2))
// //         printf("TESTE 3 ok xs[1] = %f\n", xs.data[1].t);
// //     else
// //         printf("FALHA teste 3 xs[1] = %f\n", xs.data[1].t);
// // }

// // void    testeSphereIntersection2()
// // {
// //     t_xs                xs;
// //     t_sphere            s;
// //     t_rays               r;

// //     r = ray(point(0, 0, -5), vector(0, 0, 1));
// //     s = sphere();
// //     xs = intersect(s, r);
// //     if (equal(xs.count, 2))
// //     printf("TESTE 1 OK xs.count = %i\n", xs.count);
// //     else
// //         printf("FALHA teste 1 xs.count = %d\n", xs.count);

// //     if (equal(xs.data[0].object.radius, s.radius))
// //         printf("TESTE 2 OK s[0] = %i\n",xs.data[0].object.radius);
// //     else
// //         printf("Falha teste 2 s[0] = %i\n", xs.data[0].object.radius);
// //     if (equal(xs.data[1].object.radius, s.radius))
// //         printf("TESTE 3 ok s[1] = %i\n", xs.data[0].object.radius);
// //     else
// //         printf("FALHA teste 3 s[1] = %i\n", xs.data[0].object.radius);
// // }

// void    testeHit()
// {
//     t_sphere s;
//     t_intersection i;
//     t_intersection i1;
//     t_intersection i2;
//     t_intersection i3;
//     t_intersection i4;

//     t_xs           xs;

//     xs.count = 0;
//     i1 = intersection(1, s);
//     i2 = intersection(2, s);
//     xs = intersections(i1, xs);
//     xs = intersections(i2, xs);
//     i = hit(xs);
//     printf("\nTESTE 1\n");
//     if (equal(i.t, i1.t))
//     {
//         printf("TESTE 1 SUCCESS\n\n");
//     }
//     else
//         printf("TESTE 1 FAILURE\n\n");

//     //------------------------
//     printf("TESTE 2\n");
//     i1 = intersection(-1, s);
//     i2 = intersection(1, s);
//     t_xs    xs1;
//     xs1.count = 0;
//     xs1 = intersections(i1, xs1);
//     xs1 = intersections(i2, xs1);
//     i = hit(xs1);
//      if (equal(i.t, i2.t))
//     {
//         printf("TESTE 2 SUCCESS\n\n");
//     }
//     else
//         printf("TESTE 2 FAILURE\n\n");

   
//     //-----------------
//      printf("TESTE 3\n");
//     i1 = intersection(-2, s);
//     i2 = intersection(-1, s);
//     t_xs    xs3;
//     xs3.count = 0;
//     xs3 = intersections(i1, xs3);
//     xs3 = intersections(i2, xs3);
//     i = hit(xs3);
   
//     printf("esperado --> is nothing\n\n");

//      //-----------------
//      printf("TESTE 4\n");
//     i1 = intersection(5, s);
//     i2 = intersection(7, s);
//     i3 = intersection(-3, s);
//     i4 = intersection(2, s);
//     t_xs    xs5;
//     xs5.count = 0;
//     xs5 = intersections(i1, xs5);
//     xs5 = intersections(i2, xs5);
//     xs5 = intersections(i3, xs5);
//     xs5 = intersections(i4, xs5);

//     i = hit(xs5);
//     if (equal(i.t, i4.t))
//     {
//         printf("TESTE 4 SUCCESS\n\n");
//     }
//     else
//         printf("TESTE 4 FAILURE\n\n");

    
// }

// void    testeTransform()
// {
//     t_rays r;
//     t_rays  r2;
//     t_matrices m;

//     r = ray(point(1, 2, 3), vector(0, 1, 0));
//     m = translation(3, 4, 5);
//     r2 = transform(r, m);
//     if (equal(r2.origin.x, 4) && equal(r2.origin.y, 6) && equal(r2.origin.z, 8)
//         && equal(r2.direction.x, 0) && equal(r2.direction.y, 1) && equal(r2.direction.z, 0))
//     {
//         printf("TESTE 1 SUCCESS\n\n");
//     }
//     else
//     {
//         printf("x: %f, y: %f, z: %f\n", r2.origin.x, r2.origin.y, r2.origin.z);
//         printf("TESTE 1 FAILURE\n\n");
//     }

//     //teste 2

//     r = ray(point(1, 2, 3), vector(0, 1, 0));
//     m = scaling(2, 3, 4);
//     r2 = transform(r, m);
//     if (equal(r2.origin.x, 2) && equal(r2.origin.y, 6) && equal(r2.origin.z, 12)
//         && equal(r2.direction.x, 0) && equal(r2.direction.y, 3) && equal(r2.direction.z, 0))
//     {
//         printf("TESTE 2 SUCCESS\n\n");
//     }
//     else
//     {
//         printf("TESTE 2 FAILURE\n\n");
//         printf("x: %f, y: %f, z: %f\n", r2.origin.x, r2.origin.y, r2.origin.z);
//         printf("x: %f, y: %f, z: %f\n", r2.direction.x, r2.direction.y, r2.direction.z);

//     }

//     //teste dois

//     t_sphere s;
//     t_matrices t;

//     t = translation(2, 3, 4);
//     s = sphere();
//     s = set_transform(s, t);
//     if (compare_matrix(s.transform, t))
//     {
//         printf("TESTE 3 SUCCESS\n");
//     }
//     else
//     {
//         printf("TESTE 3 FAILURE\n");
//     }

//     //teste 4
//     t_xs xs;

//     r = ray(point(0, 0, -5), vector(0, 0, 1));
//     s = sphere();
//     s = set_transform(s, scaling(2, 2, 2));
//     xs = intersect(s, r);
//     if (equal(xs.data[0].t, 3) && equal(xs.data[1].t, 7) && equal(xs.count, 2))
//     {
//         printf("TESTE 4 SUCCESS\n");
//     }
//     else
//         printf("TESTE 4 FAILURE\n");
    
//     //teste 5
//     //  t_xs xs;

//     r = ray(point(0, 0, -5), vector(0, 0, 1));
//     s = sphere();
//     s = set_transform(s, translation(5, 0, 0));
//     xs = intersect(s, r);
//     if (equal(xs.count, 0))
//     {
//         printf("TESTE 4 SUCCESS\n");
//     }
//     else
//         printf("TESTE 4 FAILURE\n");
// }

// int putting_it_together(t_data *data)
// {
//     double           wall_z;
//     double           wall_size;
//     double           pixel_size;
//     double           half;
//     t_xs            xs;
//     double           world_x = 0;
//     double           world_y = 0;
//     t_sphere        shape;
//     t_tuple         ray_origin;
//     t_tuple         posit;
//     t_rays          r;
//     t_intersection  i;
//     t_matrices      m;


//     xs.count = 0;
//     ray_origin = point(0, 0, -5);
//     wall_z = 10;
//     wall_size = 7;
//     pixel_size =  wall_size / data->canvas.width;
//     half = wall_size / 2;
//     shape = sphere();
//     for (double y = 0; y < data->canvas.width - 1; y++)
//     {
//         world_y = half - pixel_size * y;
//         for(double x = 0; x < data->canvas.width - 1; x++)
//         {
//             world_x = -half + pixel_size * x;
//             posit = point(world_x, world_y, wall_z);
//             r = ray(ray_origin, normalize(subtracting_tuple(posit, ray_origin)));
//             xs = intersect(shape, r);
//             i = hit(xs);
//             if (i.t > 0)
//             {
//                 if (x >= 0 && x < data->canvas.width && y >= 0 && y < data->canvas.width)
//                     img_pix_put(data, (int)x, (int)y, set_color(data->canvas.color));
//             }
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }

// void	test_print_sphere(void)
// {
// 	t_color		color;
// 	t_data		data;
    
//     data.canvas.height = 1000;
//     data.canvas.width = 1000;

// 	color = get_color(1, 0.0, 0.0);
// 	data.canvas = create_canvas(data.canvas, 1000, 1000, color);
// 	data.mlx = mlx_init();
// 	if (data.mlx == NULL)
// 		return ;
// 	data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "MiniRT \\o/");
// 	if (data.win == NULL)
// 		return ;
// 	data.img = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
// 	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
//     mlx_loop_hook(data.mlx, &putting_it_together, &data);
// 	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
//     mlx_loop(data.mlx);
// 	mlx_destroy_image(data.mlx, data.img);
// 	mlx_destroy_display(data.mlx);
// 	free(data.mlx);
// }




// int putting_it(t_data *data)
// {
//     double           wall_z;
//     double           wall_size;
//     double           pixel_size;
//     double           half;
//     t_xs            xs;
//     double           world_x = 0;
//     double           world_y = 0;
//     t_sphere        shape;
//     t_tuple         ray_origin;
//     t_tuple         posit;
//     t_rays          r;
//     t_intersection  i;
//     t_matrices      m;
//     t_tuple     light_position;
//     t_color     light_color;
//     t_l         light;
//     t_objects *rt;int putting_it(t_data *data)
// {
//     double           wall_z;
//     double           wall_size;
//     double           pixel_size;
//     double           half;
//     t_xs            xs;
//     double           world_x = 0;
//     double           world_y = 0;
//     t_sphere        shape;
//     t_tuple         ray_origin;
//     t_tuple         posit;
//     t_rays          r;
//     t_intersection  i;
//     t_matrices      m;
//     t_tuple     light_position;
//     t_color     light_color;
//     t_l         light;
//     t_objects *rt;
//     t_tuple     point_;
//     t_tuple     normal_;
//     t_tuple     eye_;
//     t_color     color;

//     light_position = point(-10, 10, -10);
//     light_color = get_color (1, 1, 1);
//     light = point_light(light_position, light_color);
//     rt = (t_objects *)malloc(sizeof(t_objects));
//     rt->sp = NULL;
//     rt->cy = NULL;
//     rt->pl = NULL;
//     if (!parser(&rt, "arquivo3/arq1.rt"))
//         printf("deu ruim!");
//     // rt->sp[0].material.color = get_color(1, 0.2, 1);
    
//     xs.count = 0;
//     ray_origin = point(0, 0, -5);
//     wall_z = 10;
//     wall_size = 7;
//     pixel_size =  wall_size / data->canvas.width;
//     half = wall_size / 2;
//     for (double y = 0; y < data->canvas.width - 1; y++)
//     {
//         world_y = half - pixel_size * y;
//         for(double x = 0; x < data->canvas.width - 1; x++)
//         {
//             world_x = -half + pixel_size * x;
//             posit = point(world_x, world_y, wall_z);
//             r = ray(ray_origin, normalize(subtracting_tuple(posit, ray_origin)));
//             xs = intersections(rt, r);
//             i = hit(xs);
//             if (i.t > 0)
//             {
//                 point_ = position(r, i.t);
//                 normal_ = normal_at(i.object, point_);
//                 eye_ = negate(r.direction);
//                 color = lighting(i.object.material, light, point_, eye_, normal_);
//                 if (x >= 0 && x < data->canvas.width && y >= 0 && y < data->canvas.width)
//                     img_pix_put(data, (int)x, (int)y, set_color(color));
//             }
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }

//     t_tuple     point_;
//     t_tuple     normal_;
//     t_tuple     eye_;
//     t_color     color;

//     light_position = point(-10, 10, -10);
//     light_color = get_color (1, 1, 1);
//     light = point_light(light_position, light_color);
//     rt = (t_objects *)malloc(sizeof(t_objects));
//     rt->sp = NULL;
//     rt->cy = NULL;
//     rt->pl = NULL;
//     if (!parser(&rt, "arquivo3/arq1.rt"))
//         printf("deu ruim!");
//     // rt->sp[0].material.color = get_color(1, 0.2, 1);
    
//     xs.count = 0;
//     ray_origin = point(0, 0, -5);
//     wall_z = 10;
//     wall_size = 7;
//     pixel_size =  wall_size / data->canvas.width;
//     half = wall_size / 2;
//     for (double y = 0; y < data->canvas.width - 1; y++)
//     {
//         world_y = half - pixel_size * y;
//         for(double x = 0; x < data->canvas.width - 1; x++)
//         {
//             world_x = -half + pixel_size * x;
//             posit = point(world_x, world_y, wall_z);
//             r = ray(ray_origin, normalize(subtracting_tuple(posit, ray_origin)));
//             xs = intersections(rt, r);
//             i = hit(xs);
//             if (i.t > 0)
//             {
//                 point_ = position(r, i.t);
//                 normal_ = normal_at(i.object, point_);
//                 eye_ = negate(r.direction);
//                 color = lighting(i.object.material, light, point_, eye_, normal_);
//                 if (x >= 0 && x < data->canvas.width && y >= 0 && y < data->canvas.width)
//                     img_pix_put(data, (int)x, (int)y, set_color(color));
//             }
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }


// int putting_it(t_data *data)
// {
//     double           wall_z;
//     double           wall_size;
//     double           pixel_size;
//     double           half;
//     t_xs            xs;
//     double           world_x = 0;
//     double           world_y = 0;
//     t_sphere        shape;
//     t_tuple         ray_origin;
//     t_tuple         posit;
//     t_rays          r;
//     t_intersection  i;
//     t_matrices      m;
//     t_tuple     light_position;
//     t_color     light_color;
//     t_l         light;
//     t_objects *rt;
//     t_tuple     point_;
//     t_tuple     normal_;
//     t_tuple     eye_;
//     t_color     color;

//     light_position = point(-10, 10, -10);
//     light_color = get_color (1, 1, 1);
//     light = point_light(light_position, light_color);
//     rt = (t_objects *)malloc(sizeof(t_objects));
//     rt->sp = NULL;
//     rt->cy = NULL;
//     rt->pl = NULL;
//     if (!parser(&rt, "arquivo3/arq1.rt"))
//         printf("deu ruim!");
//     // rt->sp[0].material.color = get_color(1, 0.2, 1);
//     xs.count = 0;
//     ray_origin = point(0, 0, -5);
//     wall_z = 10;
//     wall_size = 7;
//     pixel_size =  wall_size / data->canvas.width;
//     half = wall_size / 2;
//     for (double y = 0; y < data->canvas.width - 1; y++)
//     {
//         world_y = half - pixel_size * y;
//         for(double x = 0; x < data->canvas.width - 1; x++)
//         {
//             world_x = -half + pixel_size * x;
//             posit = point(world_x, world_y, wall_z);
//             r = ray(ray_origin, normalize(subtracting_tuple(posit, ray_origin)));
//             xs = intersections(rt, r);
//             i = hit(xs);
//             if (i.t > 0)
//             {
//                 point_ = position(r, i.t);
//                 normal_ = normal_at(i.object, point_);
//                 eye_ = negate(r.direction);
//                 color = lighting(i.object.material, light, point_, eye_, normal_);
//                 if (x >= 0 && x < data->canvas.width && y >= 0 && y < data->canvas.width)
//                 {
//                     img_pix_put(data, (int)x, (int)y, set_color(color));
//                 }
//             }
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }

void    world_free(t_world *w)
{
    if (w->rt->sp != NULL)
        free(w->rt->sp);
    if (w->rt->cy != NULL)
        free(w->rt->cy);
    if (w->rt->pl != NULL)
        free(w->rt->pl);
    free(w->rt);
    free(w);
}

int putting_it(t_data *data)
{ 
    t_world     *w;
    t_c_world   c;

    w = (t_world *)malloc(sizeof(t_world));
    w->rt = (t_objects *)malloc(sizeof(t_objects));
    w->rt->sp = NULL;
    w->rt->cy = NULL;
    w->rt->pl = NULL;
    if (!parser(&w->rt, "arquivo3/arq1.rt"))
        printf("deu ruim!");
    w->data = data;
    w->ligth = point_light(w->rt->l.coordinates, color_scale(w->rt->l.brightness, w->rt->l.color));
    c = camera(w->data->canvas.height, w->data->canvas.width, w->rt->c.fov);
    c.transform = view_transform(w->rt->c.coordinates, w->rt->c.vector, vector(0, 1, 0));
    render_img(c, w);
    world_free(w);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

void	test_print_sphere(void)
{
	t_color		color;
	t_data		data = (t_data){0};
    
    data.canvas.height = 100;
    data.canvas.width = 100;

	color = get_color(1, 0.0, 0.0);
	data.canvas = create_canvas(data.canvas, data.canvas.height, data.canvas.width, color);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return ;
	data.win = mlx_new_window(data.mlx, data.canvas.width, data.canvas.height, "MiniRT \\o/");
	if (data.win == NULL)
		return ;
	data.img = mlx_new_image(data.mlx, data.canvas.width, data.canvas.height);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    mlx_loop_hook(data.mlx, &putting_it, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
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
    // testeSphereIntersection();
    // testeSphereIntersection1();
    // testeSphereIntersection2();
    // testeHit();
    // testeTransform();
    test_print_sphere();

    return (0);
}