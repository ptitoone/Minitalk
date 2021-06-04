/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:47:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/04 11:30:00 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	binary_to_stdout(int count)
{
	static int	ascii_code;
	static int	power;
	char		c;

	c = 0;
	if (power == 0)
		power = 7;
	ascii_code += pow(1, power);
	if (count == 7)
	{
		c = ascii_code;
		write (1, &c, 1);
	}

}

void	handle_signal(int signal)
{
	static int	count;

	if (count == 8)
		count = 0;
	if (signal == SIGUSR2)				// 1
		binary_to_stdout(count++);
	else if (signal == SIGUSR1) 		// 0
		count++;
}

int	main()
{
	pid_t	pid;
	int		ascii_code;

	pid = getpid();
	ascii_code = 0;
	pritnf("%i\n", atoi(pid));
	printf("Waiting for string income...\n\n");
	
	
	return (0);
}
