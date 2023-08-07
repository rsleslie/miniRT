/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/07 19:50:01 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	compare_row_col(t_matrices a, t_matrices b)
{
	if ((a.x != b.x) || (a.y != b.y))
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
