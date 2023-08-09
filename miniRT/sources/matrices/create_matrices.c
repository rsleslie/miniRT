/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/09 19:17:03 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	compare_row_col(t_matrices a, t_matrices b)
{
	if (!(equal(a.x, b.x)) || !(equal(a.y, b.y)))
	{
		ft_putendl_fd("different sizes of columns of the"
			"first matrix and rows of the second matrix", 2);
		return (FALSE);
	}
	return (TRUE);
}

t_matrices	mult_matrices(t_matrices a, t_matrices b)
{
	int			i;
	int			col;
	int			line;
	int			value;
	t_matrices	m_matrix;

	if (!compare_row_col(a, b))
		exit(1);
	line = -1;
	m_matrix.x = a.x;
	m_matrix.y = a.y;
	m_matrix = create_matrices(a.x, a.y);
	while (++line < a.x)
	{
		col = -1;
		while (++col < a.y)
		{
			i = -1;
			value = 0;
			while (++i < a.y)
				value += (a.matrices[line][i] * b.matrices[i][col]);
			m_matrix.matrices[line][col] = value;
		}
	}
	return (m_matrix);
}

t_tuple	mult_matrix_tuple(t_matrices m, t_tuple t)
{
	int		line;
	int		col;
	t_tuple	new_t;

	line = 0;
	new_t.x = ((m.matrices[line][0] * t.x) + (m.matrices[line][1] * t.y)
			+ (m.matrices[line][2] * t.z) + (m.matrices[line][3] * t.w));
	line++;
	new_t.y = ((m.matrices[line][0] * t.x) + (m.matrices[line][1] * t.y)
			+ (m.matrices[line][2] * t.z) + (m.matrices[line][3] * t.w));
	line++;
	new_t.z = ((m.matrices[line][0] * t.x) + (m.matrices[line][1] * t.y)
			+ (m.matrices[line][2] * t.z) + (m.matrices[line][3] * t.w));
	line++;
	new_t.w = ((m.matrices[line][0] * t.x) + (m.matrices[line][1] * t.y)
			+ (m.matrices[line][2] * t.z) + (m.matrices[line][3] * t.w));
	return (new_t);
}

int	compare_matrix(t_matrices a, t_matrices b)
{
	int	i;
	int	j;

	i = -1;
	if ((a.x != b.x) || (a.y != b.y))
		return (FALSE);
	while (++i < a.x)
	{
		j = -1;
		while (++j < a.y)
		{
			if (a.matrices[i][j] != b.matrices[i][j])
				return (FALSE);
		}
	}
	return (TRUE);
}

t_matrices	identity_matrix(t_matrices a)
{
	int			line;
	int			col;
	t_matrices	id_matrix;
	t_matrices	result;

	line = -1;
	col = -1;
	id_matrix = create_matrices(a.x, a.y);
	while (++line < id_matrix.x)
	{
		if (++col < id_matrix.y)
			id_matrix.matrices[line][col] = 1; 
	}
	result = mult_matrices(id_matrix, a);
	return (result);
}

t_matrices	transpose(t_matrices a)
{
	int			line;
	int			col;
	t_matrices	m_transposing;

	line = -1;
	m_transposing = create_matrices(a.x, a.y);
	while (++line < a.x)
	{
		col = -1;
		while (++col < a.y)
			m_transposing.matrices[col][line] = a.matrices[line][col];
	}
	return (m_transposing);
}

float	determinant(t_matrices a)
{
	float	result;

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
				continue;
			result.matrices[i][j++] = a.matrices[i_line][i_col];
		}
		i++;
	}
	return (result);
}


float	minor(t_matrices a, int line, int col)
{
	t_matrices	b;
	float		result;

	b = submatrix(a, line, col);
	result = determinant(b);
	return (result);
}

float	cofactor(t_matrices a, int row, int col)
{
	t_matrices	cof;
	float		m;

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
	float		c;
	
	if (equal(determinant(m), (float)0))
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

t_matrices	create_matrices(int line, int col)
{
	int			i;
	int			j;
	t_matrices	matrix;

	i = -1;
	matrix.x = line;
	matrix.y = col;
	while (++i != line)
	{
		j = -1;
		while (++j < col)
			matrix.matrices[i][j] = 0;
	}
	return (matrix);
}
