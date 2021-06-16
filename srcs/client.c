/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:38:51 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/16 07:52:29 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <libft.h>

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		;
}

void	char_to_bin_str(int pid, char c)
{
	char	ch;
	int		count;
	int		mask;

	count = 0;
	mask = 1;
	while (++count <= 8)
	{
		ch = c;
		ch = ch & mask;
		c = c >> 1;
		usleep(80);
		if (ch == 0)
			kill(pid, SIGUSR1);
		if (ch == 1)
			kill(pid, SIGUSR2);
		usleep(80);
	}
}

void	process_str(int pid, char *str)
{
	while (*str)
		char_to_bin_str(pid, *(str++));
	char_to_bin_str(pid, '\n');
}

int	main(int ac, char **av)
{
	int					pid;
	char				*str;
	struct sigaction	action;

	action.sa_handler = &handle_signal;
	action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &action, NULL);
	sigaddset(&action.sa_mask, SIGUSR1);
	pid = ft_atoi(av[1]);
	str = av[2];
	if (ac != 3)
		ft_putstr_fd("Error: Wrong argument count\n", 2);
	else if (pid <= 0)
		ft_putstr_fd("Error: Invalid PID\n", 2);
	else if (!*str)
		ft_putstr_fd("Error: String is NULL\n", 2);
	else
		process_str(pid, str);
	return (0);
}
