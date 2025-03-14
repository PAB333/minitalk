/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:28 by pibreiss          #+#    #+#             */
/*   Updated: 2025/03/14 16:03:09 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_received_check;

void	received_checker(int signal)
{
	g_received_check = 1;
}

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

	i = -1;
	while (message[++i])
	{
		char_to_binary(message[i], binary);
		j = -1;
		while (binary[++j])
		{
			if (binary[j] == '0')
				kill(PID, SIGUSR1);
			else if (binary[j] == '1')
				kill(PID, SIGUSR2);
			while (!g_received_check)
				;
		}
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, received_checker);
		if (!pid || only_number(av[1]) || kill(pid, 0) == -1)
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
		send_message(pid, message);
		send_message(pid, "\0");
	}
	else
		ft_printf("Parameter error : ./client [PID] [Message] \n");
	return (0);
}
