/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:20:05 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/15 14:20:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int error)
{
	if (error == -1)
		ft_putstr("error read / open\n");
	else if (error == 1)
		ft_putstr("error input data\n");
	else
		ft_putstr("error\n");
	exit(3);
}
