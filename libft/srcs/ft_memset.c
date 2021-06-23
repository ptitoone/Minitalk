/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:20:47 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/20 13:45:46 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = n;
	while (n-- > 0)
		*(unsigned char *)str++ = c;
	return (str - i);
}
