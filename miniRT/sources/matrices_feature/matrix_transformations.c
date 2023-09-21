/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:31:10 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 13:48:51 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrices	translation(double a, double b, double c)
{
	t_matrices	translation;

	translation = create_matrices(4, 4);
	translation.matrices[0][0] = (double)1;
	translation.matrices[1][1] = (double)1;
	translation.matrices[2][2] = (double)1;
	translation.matrices[3][3] = (double)1;
	translation.matrices[0][3] = a;
	translation.matrices[1][3] = b;
	translation.matrices[2][3] = c;
	return (translation);
}

t_matrices	scaling(double a, double b, double c)
{
	t_matrices	scaling;

	scaling = create_matrices(4, 4);
	scaling.matrices[0][0] = a;
	scaling.matrices[1][1] = b;
	scaling.matrices[2][2] = c;
	scaling.matrices[3][3] = 1.0;
	return (scaling);
}

t_matrices	rotate_x(double r)
{
	t_matrices	rotate_x;

	rotate_x = create_matrices(4, 4);
	rotate_x.matrices[0][0] = (double)1;
	rotate_x.matrices[1][1] = (double)cos(r);
	rotate_x.matrices[1][2] = (double)-sin(r);
	rotate_x.matrices[2][1] = (double)sin(r);
	rotate_x.matrices[2][2] = (double)cos(r);
	rotate_x.matrices[3][3] = (double)1;
	return (rotate_x);
}

t_matrices	rotate_y(double r)
{
	t_matrices	rotate_y;

	rotate_y = create_matrices(4, 4);
	rotate_y.matrices[0][0] = (double)cos(r);
	rotate_y.matrices[0][2] = (double)sin(r);
	rotate_y.matrices[1][1] = (double)1;
	rotate_y.matrices[2][0] = (double)-sin(r);
	rotate_y.matrices[2][2] = (double)cos(r);
	rotate_y.matrices[3][3] = (double)1;
	return (rotate_y);
}

t_matrices	rotate_z(double r)
{
	t_matrices	rotate_z;

	rotate_z = create_matrices(4, 4);
	rotate_z.matrices[0][0] = cos(r);
	rotate_z.matrices[0][1] = -sin(r);
	rotate_z.matrices[1][0] = sin(r);
	rotate_z.matrices[1][1] = cos(r);
	rotate_z.matrices[2][2] = 1;
	rotate_z.matrices[3][3] = 1;
	return (rotate_z);
}
