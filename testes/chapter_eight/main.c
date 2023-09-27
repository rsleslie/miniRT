#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>


typedef struct s_inter
{
    double		t;
	t_sphere		sphere;
} t_inter;

t_inter	intersection_test(double n, t_sphere s)
{
	t_inter	t;

	t.t = n;
	t.sphere = s;
	return (t);
}

t_tuple	normal_at_teste(t_sphere s, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(inverse(s.transform), p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(transpose(inverse(s.transform)), object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

// t_comps	comps;
	
// 	comps.t.t = i.t;
	
// 	comps.point = position(r, comps.t.t);
// 	comps.eyev = negate(r.direction);
	
// 		comps.normalv = normal_at_world(comps.sp, comps.point);
	
// 	if (dot(comps.normalv, comps.eyev) < 0)
// 	{
// 		comps.inside = TRUE;
// 		comps.normalv = negate(comps.normalv);
// 	}
// 	else
// 		comps.inside = FALSE;
// 	comps.over_point = mult_tuple(comps.normalv, EPSILON);
// 	comps.over_point = adding_tuple(comps.point, comps.over_point);
// 	return (comps);
// }
t_comps	prepare_computations_teste(t_inter i, t_rays r)
{
	t_comps	comps;
	
	comps.t.t = i.t;
    comps.object = i.sphere;
	comps.point = position(r, comps.t.t);
	comps.eyev = negate(r.direction);
	comps.normalv = normal_at_teste(i.sphere, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate(comps.normalv);
	}
	else
		comps.inside = FALSE;
	comps.over_point = mult_tuple(comps.normalv, EPSILON);
	comps.over_point = adding_tuple(comps.point, comps.over_point);
	return (comps);
}

t_color	lighting_teste(t_m m, t_l light, t_tuple position, t_tuple eyev, t_tuple normalv, int in_shadow)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	t_color	ambient;
	t_color	diffuse;
	t_color specular;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;

	effective_color = hadamard_product(m.color, light.intensity);
	lightv = normalize(subtracting_point(light.position, position));
	ambient = color_scale(m.ambient, effective_color);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = get_color(0, 0, 0);
		specular = get_color(0, 0, 0);
	}
	else
	{
		diffuse = color_scale((m.diffuse * light_dot_normal), effective_color);
		reflectv = reflect(negate(lightv), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = get_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			specular = color_scale((m.specular * factor), light.intensity);
		}
	}
	if (in_shadow)
		return (ambient);
	return (add_colors(add_colors(ambient, diffuse), specular));
}


t_xs    *teste_intersect_t(t_sphere sp, t_rays r, t_xs *xs)
{
    t_tuple    sphere_to_ray;
    float    a;
    float    b;
    float    c;

    r = transform(r, sp.transform);
    sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
    a = dot(r.direction, r.direction);
    b = 2 * dot(r.direction, sphere_to_ray);
    c = dot(sphere_to_ray, sphere_to_ray) - 1;
    if (discriminant(a, b, c) < 0)
        return (xs);
    else
    {
        xs->count += 2;
        xs->data[xs->count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
        xs->data[xs->count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
        xs->data[xs->count -1].type = 1;
        xs->data[xs->count  - 2].type = 1;
        // xs->data[xs->count -1].sp = sp;
        // xs->data[xs->count  - 2].sp = sp;
    }
    return (xs);
}

t_xs *test_intersections_t(t_sphere sp, t_rays r, t_xs *xs)
{
    t_xs    *order;
    int        i;

    i = 0;
    xs->count = 0;
    xs = teste_intersect_t(sp, r, xs);
    

    return (xs);
}

int is_shadowed_teste(t_world w, t_tuple p)
{
    t_tuple v;
    t_tuple direction;
    double distance;
    t_rays  r;
    t_xs     *xs = malloc(sizeof(t_xs));
    t_intersection i;

    v = subtracting_tuple(w.ligth.position, p);
    distance = magnitude(v);
    direction = normalize(v);
    r = ray(p, direction);
    xs = test_intersections_t(w.s2, r, xs);
  
    if (xs->count == 0)
        return (FALSE);
    i = hit(*xs);
    //coloquei a parte de baixo
    if (i.t == -1)
        return (FALSE);
    free(xs);    
    if (i.t < distance)
        return (TRUE);
    else     
        return (FALSE);
}

t_color	shade_hit_teste(t_world w, t_comps comps)
{
	t_color color;
	int		s;
	
	s = is_shadowed_teste(w, comps.over_point);
     
    color = lighting_teste(comps.object.material, w.ligth, comps.point,
        comps.eyev, comps.normalv, s);
	return (color);	
}




void    lighting_with_the_surface_in_shadow(void)
{
    t_m m;
    t_tuple eyev = vector(0, 0, -1);
    t_tuple normalv = vector(0, 0, -1);
    t_l light = point_light(point(0, 0, -10), get_color(1, 1, 1));
    int in_shadow = TRUE;
    
   
    m = material();   
    
    t_color result = lighting(m, light, point(0, 0, -10), eyev, normalv, in_shadow);
    printf("%lf, %lf %lf\n ",result.r,result.g,result.b);
    if (equal(result.r, 0.1) && equal(result.g, 0.1) && equal(result.b, 0.1))
        printf("lighting_with_the_surface_in_shadow OK\n");
    else
        printf("lighting_with_the_surface_in_shadow K.O\n");
}


void an_object_is_behind_the_light_1(void)
{
    t_world w = word();
    t_tuple p = point(-20, 20, -20);
    if (!is_shadowed_teste(w, p))
        printf("1 - OK\n");
    else 
        printf("1 - K.O\n");
}

void an_object_is_behind_the_light_2(void)
{
    t_world w = word();
    t_tuple p = point(-2, 2, -2);
    if (!is_shadowed_teste(w, p))
        printf("2 = OK\n");
    else 
        printf("2 - K.O\n");
}

void is_given_an_intersection_in_shadow()
{
    t_world w;
    t_rays r;
    t_inter i;
    t_comps comps;
    t_color c;

    w = word();
    w.ligth = point_light(point(0, 0, -10), get_color(1, 1, 1));
    r = ray(point(0, 0, 5), vector(0, 0, 1));
    i = intersection_test(4, w.s2);
    comps = prepare_computations_teste(i, r);
    c = shade_hit_teste(w, comps);
    printf("%lf, %lf %lf\n ",c.r,c.g,c.b);
    if (equal(c.r, 0.1) && equal(c.g, 0.1) && equal(c.b, 0.1))
        printf("is_given_an_intersection OK\n");
    else
        printf("is_given_an_intersection K.O\n");
}


void comps_over_point_z()
{
    
    t_rays r;
    t_inter i;
    t_comps comps;
    t_sphere s;

   
    s = sphere(1);
    s.transform = translation(0, 0, 1) ;
    r = ray(point(0, 0, -5), vector(0, 0, 1));
    i = intersection_test(4, s);
 
    comps = prepare_computations_teste(i, r);

    printf("\n\n%lf %lf %lf\n", comps.over_point.x,comps.over_point.y,comps.over_point.z);
    printf("%lf %lf %lf\n\n", comps.point.x,comps.point.y,comps.point.z);

    // printf("%lf, %lf %lf\n ",c.r,c.g,c.b);
    if (comps.over_point.z < ((-EPSILON)/2))
        printf("over point OK\n");
    else
        printf("over point K.O\n");
    if (comps.point.z > comps.over_point.z)
        printf("comps.over_point.z OK\n");
    else
        printf("comps.over_point.z K.O\n");
}

int main()
{
    // an_object_is_behind_the_light_1();
    // an_object_is_behind_the_light_2();
    // comps_over_point_z();
    lighting_with_the_surface_in_shadow();
    is_given_an_intersection_in_shadow();
    return (0);
}
