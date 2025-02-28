/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:28 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/28 17:59:52 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	char_to_binary(char c, char *binary)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		binary[7 - i] = '0' + ((c >> i) & 1);
		i--;
	}
	binary[8] = '\0';
}

void	send_message(int PID, char *message)
{
	int		i;
	int		j;
	char	binary[9];

	i = 0;
	while (message[i])
	{
		char_to_binary(message[i], binary);
		j = 0;
		while (binary[j])
		{
			if (binary[j] == '0')
				kill(PID, SIGUSR1);
			else if (binary[j] == '1')
				kill(PID, SIGUSR2);
			j++;
		}
		i++;
	}
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
