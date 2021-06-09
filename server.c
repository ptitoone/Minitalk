/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:47:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/08 21:20:25 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>

void	binary_to_stdout(int count, int base)
{
	static int	ascii_code;
	char		c;

	c = 0;
	if (count - 1 == 0)
	{
		ascii_code += (base * pow(2, count - 1));
		c = ascii_code;
		write (1, &c, 1);
		ascii_code = 0;
	}
	else
		ascii_code += (base * pow(2, count - 1));
	
}

void	handle_signal(int signal)
{
	static int	count;

	if (count == 0)
		count = 8;
	if (signal == SIGUSR1)				// 0
		binary_to_stdout(count--, 0);
	else if (signal == SIGUSR2) 		// 1
		binary_to_stdout(count--, 1);
}

int	main()
{
	pid_t	pid;
	struct sigaction newDisp1;
	struct sigaction newDisp2;
  
	newDisp1.sa_handler = handle_signal;
	newDisp2.sa_handler = handle_signal;
	sigemptyset(&newDisp1.sa_mask);
	sigemptyset(&newDisp2.sa_mask);

	sigaddset(&newDisp1.sa_mask, SIGUSR2);
	sigaddset(&newDisp2.sa_mask, SIGUSR1);

	newDisp1.sa_flags = SA_RESTART;
	newDisp2.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &newDisp1, NULL);
	sigaction(SIGUSR2, &newDisp2, NULL);

	pid = getpid();

	printf("%i\n", (int)pid);
	printf("Waiting for string income...\n\n");
//	signal(SIGUSR1, handle_signal);
//	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
