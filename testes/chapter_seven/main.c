#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

void    creating_a_world(void)
{
    t_world w;

    w = world();
    // if (!w.s1 && !w.s2)
    //     prinft("Test Creating a world: SUCCESSFULLY\n");
    // else
    // {
    //     prinft("Test Creating a world: FAILED\n");
    // }
}

void    the_word(void)
{
    t_l         ligth;
    t_world     w;
    t_sphere    s1;
    t_sphere    s2;

    ligth = point_light(point(-10, 10, -10), get_color(1, 1, 1));
    s1 = sphere(1);
    s2 = sphere(1);
    s1.material.color = get_color(0.8, 1.0, 0.6);
    s1.material.diffuse = 0.7;
    s1.material.specular = 0.2;
    s2.transform = scaling(0.5, 0.5, 0.5);

    w = word();
    if(equal_tuple(w.ligth.position, ligth.position)
        && equal(w.ligth.color.r, ligth.color.r)
        && equal(w.ligth.color.g, ligth.color.g)
        && equal(w.ligth.color.b, ligth.color.b))
        printf("Test the default world: SUCCESSFULLY\n");
    else
    {
        printf("Test the default world: FAILED\n");
    }
}

void     Intersect_a_world_with_a_ray()
{
    t_world w;
    t_rays  r;
    t_xs    xs;

    w = word();
    r = ray(point(0, 0, -5), vector(0, 0, 1));
    xs = intersections_world(w, r);
    if (equal(xs.count, 4) && equal(xs.data[0].t, 4)
    && equal(xs.data[1].t, 4.5) && equal(xs.data[2].t, 5.5)
    && equal(xs.data[3].t, 6))
        printf("Test  Intersect a world with a ray: SUCCESSFULLY\n");
    else
    {
        printf("Test  Intersect a world with a ray: FAILED\n");
    }
}

void    precomputing_intersection_test(void)
{
    t_rays   r;
    t_sphere   shape;
    t_intersection  i;
    t_comps     comps;

    r = ray(point(0, 0, -5), vector(0, 0, 1));
    shape = sphere(1.0);
    i = intersection_world(4, shape);
    comps = prepare_computations(i, r);
    if (equal(i.s_world.radius, comps.object.radius) && equal_tuple(comps.point, point(0, 0, -1))
        && equal_tuple(comps.eyev, vector(0, 0, -1)) && equal_tuple(comps.normalv, vector(0, 0, -1)))
        printf("precomputing ok\n");
    else
        printf("precomputing KO\n");
}

void    hit_outside(void)
{
    t_rays  r;
    t_sphere    shape;
    t_intersection  i;
    t_comps         comps;

    r = ray(point(0, 0, -5), vector(0, 0, 1));
    shape = sphere(1.0);
    i = intersection_world(4, shape);
    comps = prepare_computations(i, r);
    if (comps.inside == FALSE)
        printf("hit outside ok\n");
    else
        printf("hit outside KO\n");
}

void    hit_inside(void)
{
    t_rays  r;
    t_sphere    shape;
    t_intersection  i;
    t_comps         comps;

    r = ray(point(0, 0, 0), vector(0, 0, 1));
    shape = sphere(1.0);
    i = intersection_world(1, shape);
    comps = prepare_computations(i, r);
    if (comps.inside == TRUE && equal_tuple(comps.point, point(0, 0, 1))
        && equal_tuple(comps.eyev, vector(0, 0, -1))
        && equal_tuple(comps.normalv, vector(0, 0, -1)))
        printf("hit inside ok\n");
    else
        printf("hit inside KO\n");
}

void shading_an_intersection(void)
{
    t_world         w;
    t_rays          r;
    t_intersection  i;
    t_c_world         c;
    t_comps         comps;

    w = word();
    r = ray(point(0, 0, -5), vector(0, 0, 1));
    i = intersection_world(4, w.s1);
    comps = prepare_computations(i, r);
    c.color = shade_hit(w, comps);
    if (equal(c.color.r, 0.38066) && equal(c.color.g, 0.47583) && equal(c.color.b, 0.2855))
        printf("Test  shading_an_intersection with a ray: SUCCESSFULLY\n");
    else
        printf("Test  shading_an_intersection with a ray: FAILED\n");
}

void shading_an_intersection_from_inside(void)
{
    t_world         w;
    t_rays          r;
    t_intersection  i;
    t_c_world         c;
    t_comps         comps;

    w = word();
    w.ligth = point_light(point(0, 0.25, 0), get_color(1, 1, 1));

    r = ray(point(0, 0, 0), vector(0, 0, 1));
    i = intersection_world(0.5, w.s2);
    comps = prepare_computations(i, r);
    c.color = shade_hit(w, comps);
    if (equal(c.color.r, 0.90498) && equal(c.color.g, 0.90498) && equal(c.color.b, 0.90498))
        printf("Test  shading_an_intersection_from_inside with a ray: SUCCESSFULLY\n");
    else
        printf("Test  shading_an_intersection_from_inside with a ray: FAILED\n");
}

void the_color_when_a_ray_misses(void)
{
    t_world w;
    t_rays  r;
    t_c_world c;

    w = word();
    r = ray(point(0, 0, -5), vector(0, 1, 0));
    c.color = color_at(w, r);
     if (equal(c.color.r, 0) && equal(c.color.g, 0) && equal(c.color.b, 0))
        printf("Test  the_color_when_a_ray_misses with a ray: SUCCESSFULLY\n");
    else
        printf("Test  the_color_when_a_ray_misses with a ray: FAILED\n");
}

void the_color_when_a_ray_hits(void)
{
    t_world w;
    t_rays  r;
    t_c_world c;

    w = word();
    r = ray(point(0, 0, -5), vector(0, 0, 1));
    c.color = color_at(w, r);
    if (equal(c.color.r, 0.38066) && equal(c.color.g, 0.47583) && equal(c.color.b, 0.2855))
        printf("Test  the_color_when_a_ray_hits with a ray: SUCCESSFULLY\n");
    else
        printf("Test  the_color_when_a_ray_hits with a ray: FAILED\n");
}

void    the_color_with_an_intersection_behind_the_ray(void)
{
    t_world     w;
    t_sphere    outer;
    t_sphere    inner;
    t_rays      r;
    t_c_world     c;

    w = word();
    w.s1.material.ambient = 1;
    w.s2.material.ambient = 1;
    outer = w.s1;
    inner = w.s2;
    r = ray(point(0, 0, 0.75), vector(0, 0, -1));
    c.color = color_at(w, r);
    if (equal(c.color.r, inner.material.color.r)
        && equal(c.color.g, inner.material.color.g)
        && equal(c.color.b, inner.material.color.b))
        printf("Test  the_color_with_an_intersection_behind_the_ray with a ray: SUCCESSFULLY\n");
    else
        printf("Test  the_color_with_an_intersection_behind_the_ray with a ray: FAILED\n");

}

void    the_transformation_matrix_for_the_default_orientation(void)
{
    t_tuple from;
    t_tuple to;
    t_tuple up;
    t_matrices t;

    from = point(0, 0, 0);
    to = point(0, 0, -1);
    up = vector(0, 1, 0);
    t = view_transform(from, to, up);
    if (compare_matrix(t, identity_matrix(t)))
        printf("Test  the_transformation_matrix_for_the_default_orientation with a ray: SUCCESSFULLY\n");
    else
        printf("Test  the_transformation_matrix_for_the_default_orientation with a ray: FAILED\n");

}

void    transformation_matrix_looking_in_positive_z_direction(void)
{
    t_tuple from;
    t_tuple to;
    t_tuple up;
    t_matrices t;
    t_matrices scal;

    from = point(0, 0, 0);
    to = point(0, 0, 1);
    up = vector(0, 1, 0);
    t = view_transform(from, to, up);
    if (compare_matrix(t, scaling(-1, 1, -1)))
        printf("Test  transformation_matrix_looking_in_positive_z_direction with a ray: SUCCESSFULLY\n");
    else
        printf("Test  transformation_matrix_looking_in_positive_z_direction with a ray: FAILED\n");

}

void    view_transformation_moves_the_world(void)
{
    t_tuple from;
    t_tuple to;
    t_tuple up;
    t_matrices t;

    from = point(0, 0, 8);
    to = point(0, 0, 0);
    up = vector(0, 1, 0);
    t = view_transform(from, to, up);
    if (compare_matrix(t, translation(0, 0, -8)))
        printf("Test  view_transformation_moves_the_world with a ray: SUCCESSFULLY\n");
    else
        printf("Test  view_transformation_moves_the_world with a ray: FAILED\n");

}

void    an_arbitrary_view_transformation(void)
{
    t_tuple from;
    t_tuple to;
    t_tuple up;
    t_matrices t;

    from = point(1, 3, 2);
    to = point(4, -2, 8);
    up = vector(1, 1, 0);
    t = view_transform(from, to, up);
    int i = -1;
    while (++i < 4)
    {
        int j = -1;
        while (++j < 4)
            printf("%lf\t", t.matrices[i][j]);
        printf("\n");
    }
}

void constructing_a_camera(void)
{
    double  hsize;
    double  vsize;
    double  field_of_view;
    t_c_world c;

    hsize = 160;
    vsize = 120;
    field_of_view = PI / 2.0;
    c = camera(hsize, vsize, field_of_view);
    if (equal(c.hsize, 160) && equal(c.vsize, 120)
        && equal(c.field_of_view, (PI / 2.0))
        && compare_matrix(c.transform, id_matrix(create_matrices(4,4), 1)))
            printf("Test  constructing_a_camera with a ray: SUCCESSFULLY\n");
    else
        printf("Test  constructing_a_camera with a ray: FAILED\n");
}

void    pixel_size_for_a_horizontal_canvas(void)
{
    t_c_world c;
    t_c_world c1;
    c = camera(200, 125, PI/2.0);
    if (equal(c.pixel_size, 0.01))
        printf("Test 1  pixel_size_for_a_horizontal_canvas with a ray: SUCCESSFULLY\n");
    else
        printf("Test 1 pixel_size_for_a_horizontal_canvas a ray: FAILED\n");
    
    c1 = camera(125, 200, PI/2.0);
    if (equal(c1.pixel_size, 0.01))
        printf("Test 2  pixel_size_for_a_vertical_canvas with a ray: SUCCESSFULLY\n");
    else
        printf("Test 2 pixel_size_for_a_vertical_canvas a ray: FAILED\n");
    
}

void    through_the_center_of_the_canvas(void)
{
    t_c_world   c;
    t_rays      r;

    c = camera(201, 101, PI/2);
    r = ray_for_pixel(c, 100, 50);
    if (equal_tuple(r.origin, point(0, 0, 0))
        && equal_tuple(r.direction, vector(0, 0, -1)))
        printf("Test  through_the_center_of_the_canvas with a ray: SUCCESSFULLY\n");
    else
        printf("Test through_the_center_of_the_canvas a ray: FAILED\n");
}

void    through_the_corner_of_the_canvas(void)
{
    t_c_world   c;
    t_rays      r;

    c = camera(201, 101, PI/2);
    r = ray_for_pixel(c, 0, 0);
    if (equal_tuple(r.origin, point(0, 0, 0))
        && equal_tuple(r.direction, vector(0.66519, 0.33259, -0.66851)))
        printf("Test  through_the_corner_of_the_canvas with a ray: SUCCESSFULLY\n");
    else
        printf("Test through_the_corner_of_the_canvas a ray: FAILED\n");
}

void    ray_when_the_camera_is_transformed(void)
{
    t_c_world   c;
    t_rays      r;

    c = camera(201, 101, PI/2);
    c.transform = mult_matrices(rotate_y(PI/4), translation(0, -2, 5));
    r = ray_for_pixel(c, 100, 50);
    if (equal_tuple(r.origin, point(0, 2, -5))
        && equal_tuple(r.direction, vector(0.707107, 0, -0.707107)))
        printf("Test  ray_when_the_camera_is_transformed with a ray: SUCCESSFULLY\n");
    else
        printf("Test ray_when_the_camera_is_transformed a ray: FAILED\n");
}

void    rendering_a_world_with_a_camera(void)
{
    t_world         w;
    t_c_world   c;
    t_tuple     from;
    t_tuple     to;
    t_tuple     up;
    t_canvas    image;

    w = word();
    c = camera(11, 11, PI/2);
    from = point(0, 0, -5);
    to = point(0, 0, 0);
    up = vector(0, 1, 0);
    c.transform = view_transform(from, to, up);
    image = render_img(c, w);
}

int main()
{
    // creating_a_world();
    // the_word();
    // Intersect_a_world_with_a_ray();
    // precomputing_intersection_test();
    // hit_outside();
    // hit_inside();
    // shading_an_intersection();
    // shading_an_intersection_from_inside();
    // the_color_when_a_ray_hits();
    // the_color_with_an_intersection_behind_the_ray();
    // the_transformation_matrix_for_the_default_orientation();
    // transformation_matrix_looking_in_positive_z_direction();
    // view_transformation_moves_the_world();
    // an_arbitrary_view_transformation();
    // constructing_a_camera();
    // pixel_size_for_a_horizontal_canvas();
    // through_the_center_of_the_canvas();
    // through_the_corner_of_the_canvas();
    // ray_when_the_camera_is_transformed();
    rendering_a_world_with_a_camera();
}
