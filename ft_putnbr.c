/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:57:56 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/05 16:39:02 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
	}
	ft_putchar(nbr % 10 + '0', count);
}
