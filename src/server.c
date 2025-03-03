/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:18 by pibreiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:26:52 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum)
{
	
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("Welcome you are on the server\n");
	ft_printf("The PID to connect from the client is : %d\n", getpid());
	signal.sa_handler = signal_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flag = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		pause();
	}
}
