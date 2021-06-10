/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.f          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:47:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/10 22:14:25 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <libft.h>
#include <ft_printf.h>

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

void	handle_sigaction(int sig, siginfo_t *info, void *uap)
{
	static int	count;

	if (count == 0 && uap)
		count = 8;
	if (sig == SIGUSR1)
		binary_to_stdout(count--, 0);
	else if (sig == SIGUSR2)
		binary_to_stdout(count--, 1);
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	newDisp1;
	struct sigaction	newDisp2;

	pid = getpid();
	newDisp1.sa_sigaction = &handle_sigaction;
	newDisp2.sa_sigaction = &handle_sigaction;
	newDisp1.sa_flags = SA_SIGINFO;
	newDisp2.sa_flags = SA_SIGINFO;
	ft_printf("PID = %i\n", (int)pid);
	ft_putstr_fd("Waiting for string income...\n\n", 1);
	while (1)
	{
		sigemptyset(&newDisp1.sa_mask);
		sigaddset(&newDisp1.sa_mask, SIGUSR1);
		sigaddset(&newDisp2.sa_mask, SIGUSR2);
		sigaction(SIGUSR1, &newDisp1, NULL);
		sigaction(SIGUSR2, &newDisp2, NULL);
	}
	return (0);
}
