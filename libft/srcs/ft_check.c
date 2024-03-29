/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:41:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/02 08:42:04 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/ft_printf.h"

int	ft_check(const char c)
{
	if (c == '-' || c == '.' || c == '*' || (c >= '0' && c <= '9'))
		return (1);
	if (ft_is_spec(c))
		return (1);
	return (0);
}
