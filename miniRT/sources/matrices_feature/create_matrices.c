/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/11 12:12:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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
