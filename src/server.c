/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:18 by pibreiss          #+#    #+#             */
/*   Updated: 2025/03/05 05:03:35 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	binary_to_ascii(char *c)
{
	int	ascii;
	int	base;
	int	i;

	ascii = 0;
	base = 1;
	i = 7;
	while (i >= 0)
	{
		if (c[i] == '1')
			ascii += base;
		base *= 2;
		i--;
	}
	return (ascii);
}

void	signal_handler(int signum)
{
	static int		count = 0;
	static int		ascii;
	static char		c[9];

	if (signum == SIGUSR1)
		c[count] = '0';
	else if (signum == SIGUSR2)
		c[count] = '1';
	count++;
	if (count == 8)
	{
		c[count] = '\0';
		ascii = binary_to_ascii(c);
		if (ascii == '\0')
			ft_printf("\n");
		else
			write(1, &ascii, 1);
		count = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("Welcome, you are on the server\n");
	ft_printf("The PID to connect from the client is : %d\n", getpid());
	signal.sa_handler = signal_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		usleep(100);
	}
}
