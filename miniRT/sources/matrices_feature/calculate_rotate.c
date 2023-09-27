/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:30:04 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 22:22:02 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrices	calculate_z_x_rotation_matrix(t_tuple v)
{
	t_matrices	rotation_x;
	t_matrices	rotation_z;
	t_matrices	rotation;

	rotation_x = rotate_x(atan(-v.z / v.y));
	rotation_z = rotate_x(atan(-v.x / v.y));
	rotation = mult_matrices(rotation_z, rotation_x);
	return (rotation);
}

t_matrices	calculate_z_y_rotation_matrix(t_tuple v)
{
	t_matrices	rotation_z;
	t_matrices	rotation_y;
	t_matrices	rotation;

	rotation_z = rotate_z(-PI / 2);
	rotation_y = rotate_y(atan(-v.x / v.z));
	rotation = mult_matrices(rotation_y, rotation_z);
	return (rotation);
}

t_matrices	calculate_rotation_matrices(t_tuple v)
{
	if (equal_tuple(vector(0, 1, 0), v))
		return (id_matrix(create_matrices(4, 4), 1));
	else if (equal_tuple(vector(0, -1, 0), v))
		return (rotate_x(PI));
	else if (equal_tuple(vector(1, 0, 0), v))
		return (rotate_z(-PI / 2));
	else if (equal_tuple(vector(-1, 0, 0), v))
		return (rotate_z(PI / 2));
	else if (equal_tuple(vector(0, 0, 1), v))
		return (rotate_x(PI / 2));
	else if (equal_tuple(vector(0, 0, -1), v))
		return (rotate_x(-PI / 2));
	if (equal(v.y, 0))
		return (calculate_z_y_rotation_matrix(v));
	else
		return (calculate_z_x_rotation_matrix(v));
}