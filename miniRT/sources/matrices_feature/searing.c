/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:32:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/30 21:33:06 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrices	shearing(t_shear shear)
{
	t_matrices	shearing;

	shearing = create_matrices(4, 4);
	shearing.matrices[0][0] = 1;
	shearing.matrices[1][1] = 1;
	shearing.matrices[2][2] = 1;
	shearing.matrices[3][3] = 1;
	shearing.matrices[0][1] = shear.xy;
	shearing.matrices[0][2] = shear.xz;
	shearing.matrices[1][0] = shear.yx;
	shearing.matrices[1][2] = shear.yz;
	shearing.matrices[2][0] = shear.zx;
	shearing.matrices[2][1] = shear.zy;
	return (shearing);
}
