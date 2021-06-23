/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:53:14 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/02 08:55:19 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/ft_printf.h"

void	ft_putstr_len(const char *s, size_t len, t_conv *cv)
{
	unsigned long	i;

	i = 0;
	if (s)
		while (i < len)
			if (write(1, &s[i++], 1))
				cv->count++;
}
