/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:10:36 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	determinant(t_matrices a)
{
	double	result;

	if (equal(a.x, 2))
	{
		result = (a.matrices[0][0] * a.matrices[1][1])
			- (a.matrices[0][1] * a.matrices[1][0]);
	}
	else
	{
		result = a.matrices[0][0] * cofactor(a, 0, 0);
		result += a.matrices[0][1] * cofactor(a, 0, 1);
		result += a.matrices[0][2] * cofactor(a, 0, 2);
		if (equal(a.x, 4))
			result += a.matrices[0][3] * cofactor(a, 0, 3);
	}
	return (result);
}

t_matrices	submatrix(t_matrices a, int line, int col)
{
	t_matrices	result;
	int			i_line;
	int			i_col;
	int			i;
	int			j;

	i_line = -1;
	i = 0;
	result = create_matrices(a.x - 1, a.y - 1);
	while (++i_line < a.x)
	{
		if (i_line == line)
			continue ;
		j = 0;
		i_col = -1;
		while (++i_col < a.y)
		{
			if (i_col == col)
				continue ;
			result.matrices[i][j++] = a.matrices[i_line][i_col];
		}
		i++;
	}
	return (result);
}

double	minor(t_matrices a, int line, int col)
{
	t_matrices	b;
	double		result;

	b = submatrix(a, line, col);
	result = determinant(b);
	return (result);
}

double	cofactor(t_matrices a, int row, int col)
{
	double		m;

	m = minor(a, row, col);
	if (((row + col) % 2))
		m *= -1;
	return (m);
}

t_matrices	inverse(t_matrices m)
{
	t_matrices	m2;
	int			row;
	int			col;
	double		c;

	if (equal(determinant(m), (double)0))
	{
		ft_putendl_fd("matrix is not invertible", 2);
		exit (1);
	}
	row = -1;
	m2 = create_matrices(m.x, m.y);
	while (++row < m.x)
	{
		col = -1;
		while (++col < m.y)
		{
			c = cofactor(m, row, col);
			m2.matrices[col][row] = c / determinant(m);
		}
	}
	return (m2);
}
