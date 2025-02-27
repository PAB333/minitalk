/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:48 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:10 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_format(const char *format, int i, int *count, va_list arg)
{
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ft_putnbr((int)va_arg(arg, int), count);
	if (format[i + 1] == 'u')
		ft_putnbr_ui((unsigned int)va_arg(arg, unsigned int), count);
	if (format[i + 1] == 'x')
		ft_putexa_lcase((unsigned int)va_arg(arg, unsigned int), count);
	if (format[i + 1] == 'X')
		ft_putexa_ucase((unsigned int)va_arg(arg, unsigned int), count);
	if (format[i + 1] == 's')
		ft_putstr((char *)va_arg(arg, char *), count);
	if (format[i + 1] == 'c')
		ft_putchar((int)va_arg(arg, int), count);
	if (format[i + 1] == 'p')
		ft_putptr((void *)va_arg(arg, void *), count);
	if (format[i + 1] == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = -1;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			search_format(format, i, &count, arg);
			i++;
		}
		else
			ft_putchar(format[i], &count);
	}
	va_end(arg);
	return (count);
}
