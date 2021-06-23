/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.f          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:47:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/16 07:54:19 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

void	binary_to_stdout(int count, int base)
{
	static unsigned int		ascii_code;
	char					c;
	unsigned int			mask;

	c = 0;
	mask = 128;
	if (count - 1 == 0)
	{
		if (base)
			ascii_code = ascii_code >> 1 | mask;
		else
			ascii_code = ascii_code >> 1;
		c = ascii_code;
		write (1, &c, 1);
		ascii_code = 0;
	}
	else
	{
		if (base)
			ascii_code = ascii_code >> 1 | mask;
		else
			ascii_code = ascii_code >> 1;
	}
}

void	handle_sigaction(int sig)
{
	static int	count;

	usleep(80);
	if (count == 0)
		count = 8;
	if (sig == SIGUSR1)
		binary_to_stdout(count--, 0);
	else if (sig == SIGUSR2)
		binary_to_stdout(count--, 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action1;
	struct sigaction	action2;

	pid = getpid();
	action1.sa_handler = &handle_sigaction;
	action2.sa_handler = &handle_sigaction;
	action1.sa_flags = SA_RESTART;
	action2.sa_flags = SA_RESTART;
	sigemptyset(&action1.sa_mask);
	sigaddset(&action1.sa_mask, SIGUSR1);
	sigaddset(&action2.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action1, NULL);
	sigaction(SIGUSR2, &action2, NULL);
	ft_printf("PID = %i\n", (int)pid);
	ft_putstr_fd("Waiting for string income...\n\n", 1);
	while (1)
		;
	return (0);
}
