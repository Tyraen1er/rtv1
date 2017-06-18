/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_ratio_to_quad.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 21:34:57 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/15 14:21:26 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	ft_point_ratio_to_quad(t_point ratio, t_quad quad)
{
	t_point	point;

	ratio.x = point.x * (quad.br.x - quad.tl.x) + quad.tl.x;
	ratio.y = point.y * (quad.br.y - quad.tl.y) + quad.tl.y;
	return (ratio);
}
