/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:47:57 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 12:59:30 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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

t_sp	add_sp(char **str)
{
	t_sp	sp;
	t_matrices scal;
	
	sp.coordinates = get_coordenates(str[1]);
	sp.diameter = ft_atof(str[2]);
	sp.color = color_obj(str[3]);
	sp.m = translation(sp.coordinates.x, sp.coordinates.y, sp.coordinates.y);
	scal = scaling((double)(sp.diameter/2.0), (double)(sp.diameter/2.0), (double)(sp.diameter/2.0));
	sp.m = mult_matrices(sp.m, scal);
	sp.inverse = inverse(sp.m);
	sp.transpose = transpose(sp.inverse);
	sp.material = material();
	sp.material.color = rgb_to_double(sp.color);
	return (sp);
}

t_pl	add_pl(char **str)
{
	t_pl	pl;

	pl.coordinates = get_coordenates(str[1]);
	pl.vector = get_vector(str[2]);
	pl.color = color_obj(str[3]);

	//ordem da multiplação
	// S R T
	//cy.m = translation * rotation * scaling
	//pl.m = translation * rotate

	// pl.m = mult_matrices(translation(pl.coordinates.x, pl.coordinates.y,pl.coordinates.z),
	// 	calculate_rotation_matrices(pl.coordinates));
	pl.m = id_matrix(create_matrices(4, 4), 1);
	pl.inverse = inverse(pl.m);
	pl.transpose = transpose(pl.inverse);
	pl.material = material();
	pl.material.color = rgb_to_double(pl.color);
	return (pl);
}

t_cy	add_cy(char **str)
{
	t_cy	cy;

	cy.coordinates = get_coordenates(str[1]);
	cy.vector = get_vector(str[2]);
	cy.diameter = ft_atof(str[3]);
	cy.heigth = ft_atof(str[4]);
	cy.color = color_obj(str[5]);
	return (cy);
}
