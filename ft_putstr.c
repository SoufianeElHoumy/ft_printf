/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:37:32 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/05 19:15:57 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}
