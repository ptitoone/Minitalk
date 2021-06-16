/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:53:02 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/02 08:55:19 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/ft_printf.h"

void	ft_putchar_pf(char c, int fd, t_conv *cv)
{
	char	ch;

	ch = c;
	if (write(fd, &ch, 1))
		cv->count++;
}
