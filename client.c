/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:38:51 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/08 21:05:59 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	if (str)
	{
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			j--;
			i++;
		}
	}
}

void	char_to_binary_string(char str[9], char c)
{
	int		div;
	int		mod;
	int		i;
	
	div = c / 2;
	mod = c % 2;
	i = 0;
	while (i < 8)
		str[i++] = '0';
	str[i] = 0;
	i = 0;
	while (str[i])
	{
		if (mod == 0)
			str[i++] = '0';
		else if (mod != 0)
			str[i++] = '1';
		mod = div % 2;
		div /= 2;
	}
	ft_strrev(str);
}

void	send_signal(int pid, char c)
{
	if (c == '0')
		kill(pid, SIGUSR1);
	if (c == '1')
		kill(pid, SIGUSR2);
}

int main(int ac, char **av)
{
	char	binary_str[9];
	int		i;
	int		j;

	i = 0;
	while (av[2][i])
	{
		j = 0;
		char_to_binary_string(binary_str, av[2][i]);
		while (binary_str[j])
		{
			usleep(80);
			send_signal(atoi(av[1]), binary_str[j]);
			j++;
		}
		i++;
	}
	return (0);
}
