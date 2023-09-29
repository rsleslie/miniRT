/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:47:57 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	counter_obj(char *obj, char **args)
{
	int		i;
	int		counter;
	char	**aux;

	i = -1;
	counter = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], obj, ft_strlen(obj)) == 0)
			counter++;
	}
	ft_free_tab(aux);
	return (counter);
}

t_sp	add_sp(t_objects **rt, char **str)
{
	t_sp		sp;
	t_matrices	scal;

	sp.coordinates = get_coordenates(str[1]);
	sp.diameter = ft_atof(str[2]);
	sp.color = color_obj(str[3]);
	sp.m = translation(sp.coordinates.x, sp.coordinates.y, sp.coordinates.y);
	scal = scaling((double)(sp.diameter / 2.0),
			(double)(sp.diameter / 2.0), (double)(sp.diameter / 2.0));
	sp.m = mult_matrices(sp.m, scal);
	sp.inverse = inverse(sp.m);
	sp.transpose = transpose(sp.inverse);
	sp.material = material();
	sp.material.ambient = (*rt)->a.ratio;
	sp.material.color = rgb_to_double(sp.color);
	return (sp);
}

t_pl	add_pl(t_objects **rt, char **str)
{
	t_pl	pl;

	pl.coordinates = get_coordenates(str[1]);
	pl.vector = get_vector(str[2]);
	pl.color = color_obj(str[3]);
	pl.m = mult_matrices(translation(pl.coordinates.x,
				pl.coordinates.y, pl.coordinates.z),
			calculate_rotation_matrices(pl.vector));
	pl.inverse = inverse(pl.m);
	pl.transpose = transpose(pl.inverse);
	pl.material = material();
	pl.material.ambient = (*rt)->a.ratio;
	pl.material.color = rgb_to_double(pl.color);
	return (pl);
}

t_cy	add_cy(t_objects **rt, char **str)
{
	t_cy		cy;
	t_matrices	rotate;

	cy.coordinates = get_coordenates(str[1]);
	cy.vector = get_vector(str[2]);
	cy.diameter = ft_atof(str[3]);
	cy.height = ft_atof(str[4]);
	cy.color = color_obj(str[5]);
	cy.min = -1 * (cy.height / 2);
	cy.max = cy.height / 2;
	rotate = mult_matrices(translation(cy.coordinates.x,
				cy.coordinates.y, cy.coordinates.z),
			calculate_rotation_matrices(cy.vector));
	cy.m = mult_matrices(rotate, scaling(cy.diameter / 2,
				cy.diameter / 2, cy.diameter / 2));
	cy.inverse = inverse(cy.m);
	cy.transpose = transpose(cy.inverse);
	cy.material = material();
	cy.material.ambient = (*rt)->a.ratio;
	cy.material.color = rgb_to_double(cy.color);
	return (cy);
}
