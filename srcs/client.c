/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:38:51 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/10 22:15:41 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <libft.h>

int	g_pause_flow = 0;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_pause_flow = 0;
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
		usleep(30);
		ch = c;
		ch = ch & mask;
		c = c >> 1;
		if (ch == 0)
			kill(pid, SIGUSR1);
		if (ch == 1)
			kill(pid, SIGUSR2);
		g_pause_flow = 1;
		while (g_pause_flow)
			;
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
	int		pid;
	char	*str;

	signal(SIGUSR1, handle_signal);
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
