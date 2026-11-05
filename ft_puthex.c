/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:45:10 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/03 13:01:00 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, int *count, char *base)
{
	if (nb >= 16)
		ft_puthex(nb / 16, count, base);
	ft_putchar(base[nb % 16], count);
}
