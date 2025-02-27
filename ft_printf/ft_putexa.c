/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:15:26 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/27 19:17:27 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putexa_lcase(unsigned int nb, int *count)
{
	if (nb >= 16)
	{
		ft_putexa_lcase(nb / 16, count);
		ft_putexa_lcase(nb % 16, count);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + 48, count);
		else
			ft_putchar(nb - 10 + 'a', count);
	}
}

void	ft_putexa_ucase(unsigned int nb, int *count)
{
	if (nb >= 16)
	{
		ft_putexa_ucase(nb / 16, count);
		ft_putexa_ucase(nb % 16, count);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + 48, count);
		else
			ft_putchar(nb - 10 + 'A', count);
	}
}
