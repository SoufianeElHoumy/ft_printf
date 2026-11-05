/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:24:28 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/05 20:16:05 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *add, int *count, char *base)
{
	unsigned long	nb;

	if (add == NULL)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	nb = (unsigned long)add;
	if (nb >= 16)
		ft_putptr((void *)(nb / 16), count, base);
	if (nb < 16)
		ft_putstr("0x", count);
	ft_putchar(base[nb % 16], count);
}
