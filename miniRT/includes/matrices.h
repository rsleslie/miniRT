/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:55:22 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/11 12:18:07 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "tuple.h"

typedef struct s_matrices
{
	int		x;
	int		y;
	float	matrices[4][4];
}	t_matrices;

int			compare_matrix(t_matrices a, t_matrices b);
float		determinant(t_matrices a);
float		minor(t_matrices a, int line, int col);
float		cofactor(t_matrices a, int line, int col);
t_tuple		mult_matrix_tuple(t_matrices matrix, t_tuple tuple);
t_matrices	create_matrices(int line, int col);
t_matrices	mult_matrices(t_matrices a, t_matrices b);
t_matrices	identity_matrix(t_matrices a);
t_matrices	transpose(t_matrices a);
t_matrices	submatrix(t_matrices a, int line, int col);
t_matrices	inverse(t_matrices m);

#endif