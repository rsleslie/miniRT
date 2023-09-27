#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>


// void    lighting_with_the_surface_in_shadow(void)
// {
//     t_m m;
//     t_tuple eyev = vector(0, 0, -1);
//     t_tuple normalv = vector(0, 0, -1);
//     t_l light = point_light(point(0, 0, -10), get_color(1, 1, 1));
//     int in_shadow = TRUE;

//     t_color result = lighting(m, light, point(0, 0, -10), eyev, normalv, in_shadow);
    
//     if (equal(result.r, 0.1) && equal(result.g, 0.1) && equal(result.b, 0.1))
//         printf("lighting_with_the_surface_in_shadow OK\n");
//     else
//         printf("lighting_with_the_surface_in_shadow K.O");
// }

void an_object_is_behind_the_light(void)
{
    t_world w = default_world();
    t_tuple p = point(-2, 2, -2);
    if (!is_shadowed(w, p))
        printf("OK");
    else 
        printf("K.O");
}
int main()
{
    an_object_is_behind_the_light();
    // lighting_with_the_surface_in_shadow();
    return (0);
}
