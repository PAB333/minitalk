/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:18 by pibreiss          #+#    #+#             */
/*   Updated: 2025/03/04 17:55:16 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	if (signum == SIGUSR1)
		character |= (0 << bit_count);
	else if (signum == SIGUSR2)
		character |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		bit_count = 0;
		character = 0;
	}
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
