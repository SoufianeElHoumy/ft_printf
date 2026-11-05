/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:40:35 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/05 20:11:12 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char c, int *count, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), count, "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), count, "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			i++;
			check_format(format[i], &count, args);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
