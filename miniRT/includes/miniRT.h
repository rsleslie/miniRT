/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:33:32 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 15:59:12 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define FALSE 0
# define TRUE 1
# define EPSILON 0.00001
# define PI 3.141593

# include "../libft/libft.h"
# include "struct.h"
# include <math.h>
# include "tuple.h"
# include "matrices.h"
# include "rays.h"
# include "canvas.h"
# include "colors.h"
# include <fcntl.h>
# include  <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "object.h"
# include "parser.h"
# include "world.h"
# include "render.h"

#endif