/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-hou <soel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:40:02 by soel-hou          #+#    #+#             */
/*   Updated: 2026/11/05 20:43:41 by soel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(long nbr, int *count);
void	ft_puthex(unsigned int nb, int *count, char *base);
void	ft_putptr(void *add, int *count, char *base);
int		ft_printf(const char *format, ...);

#endif
