/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:12:41 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 14:15:21 by rleslie-         ###   ########.fr       */
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
	int			col;
	int			line;
	double		value;
	t_matrices	m_matrix;

	if (!compare_row_col(a, b))
		exit(1);
	line = -1;
	m_matrix = create_matrices(a.x, a.y);
	while (++line < a.x)
	{
		col = -1;
		while (++col < a.y)
		{
			value = 0;
			value = a.matrices[line][0] * b.matrices[0][col]
				+ ((a.matrices[line][1]) * (b.matrices[1][col])
					+ ((a.matrices[line][2]) * (b.matrices[2][col])))
				+ ((a.matrices[line][3]) * (b.matrices[3][col]));
			m_matrix.matrices[line][col] = value;
		}
	}
	return (m_matrix);
}

t_tuple	mult_matrix_tuple(t_matrices m, t_tuple t)
{
	t_tuple	new_t;

	new_t.x = ((m.matrices[0][0] * t.x) + (m.matrices[0][1] * t.y)
			+ (m.matrices[0][2] * t.z) + (m.matrices[0][3] * t.w));
	new_t.y = ((m.matrices[1][0] * t.x) + (m.matrices[1][1] * t.y)
			+ (m.matrices[1][2] * t.z) + (m.matrices[1][3] * t.w));
	new_t.z = ((m.matrices[2][0] * t.x) + (m.matrices[2][1] * t.y)
			+ (m.matrices[2][2] * t.z) + (m.matrices[2][3] * t.w));
	new_t.w = ((m.matrices[3][0] * t.x) + (m.matrices[3][1] * t.y)
			+ (m.matrices[3][2] * t.z) + (m.matrices[3][3] * t.w));
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
