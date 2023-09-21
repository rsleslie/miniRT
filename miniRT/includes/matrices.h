/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:55:22 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 13:47:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "tuple.h"

typedef struct s_matrices
{
	int		x;
	int		y;
	double	matrices[4][4];
}	t_matrices;

typedef struct	s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shear;

int			compare_matrix(t_matrices a, t_matrices b);
double		determinant(t_matrices a);
double		minor(t_matrices a, int line, int col);
double		cofactor(t_matrices a, int line, int col);
t_tuple		mult_matrix_tuple(t_matrices matrix, t_tuple tuple);
t_matrices	create_matrices(int line, int col);
t_matrices	mult_matrices(t_matrices a, t_matrices b);
t_matrices	identity_matrix(t_matrices a);
t_matrices	transpose(t_matrices a);
t_matrices	submatrix(t_matrices a, int line, int col);
t_matrices	inverse(t_matrices m);
t_matrices	translation(double a, double b, double c);
t_matrices	scaling(double a, double b, double c);
t_matrices	rotate_x(double r);
t_matrices	rotate_y(double r);
t_matrices	rotate_z(double r);
t_matrices	shearing(t_shear shear);
t_matrices	id_matrix(t_matrices a);

#endif