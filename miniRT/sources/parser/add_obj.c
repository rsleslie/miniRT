/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:47:57 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/12 20:32:31 by rleslie-         ###   ########.fr       */
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
	scal = scaling((float)(sp.diameter/2.0), (float)(sp.diameter/2.0), (float)(sp.diameter/2.0));
	sp.m = mult_matrices(sp.m, scal);
	sp.inverse = inverse(sp.m);
	return (sp);
}

t_pl	add_pl(char **str)
{
	t_pl	pl;

	pl.coordinates = get_coordenates(str[1]);
	pl.vector = get_vector(str[2]);
	pl.color = color_obj(str[3]);
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
