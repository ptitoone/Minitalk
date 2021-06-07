/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:47:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/07 23:19:59 by akotzky          ###   ########.fr       */
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
//	struct sigaction newDisp;
//	struct sigaction oldDisp;
	
//	newDisp.sa_handler = handle_signal;
//	sigemptyset(&newDisp.sa_mask);
//	newDisp.sa_flags = 0;
//	sigaction(SIGUSR1, NULL, &oldDisp);
//	if (oldDisp.sa_handler != SIG_IGN)
//		sigaction(SIGUSR1, &newDisp, NULL);
//	sigaction(SIGUSR2, NULL, &oldDisp);
//	if (oldDisp.sa_handler != SIG_IGN)
//		sigaction(SIGUSR2, &newDisp, NULL);

	pid = getpid();

	printf("%i\n", (int)pid);
	printf("Waiting for string income...\n\n");
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}
