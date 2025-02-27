/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:28 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/27 19:30:14 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_message(int PID, char *message)
{
	
}

int	main(int ac, char **av)
{
	int	PID;
	char *message;
	
	if (ac == 3)
	{
		PID = ft_atoi(av[1]);
		if (!PID)
		{
			ft_printf("PID formulation error\n");
			return (0);
		}
		message = av[2];
		if (!message)
		{
			ft_printf("No message, please write a massage \n");
			return (0);
		}
		send_message(PID, message);
	}
	else
	{
		ft_printf("Parameter error : ./client [PID] [Message] \n");
	}
	return (0);
}
