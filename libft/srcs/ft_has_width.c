/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:51:15 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/02 08:55:19 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/ft_printf.h"

int	ft_has_width(const char *conv)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = 0;
	tmp = NULL;
	while (conv[i])
	{
		if (conv[i] >= '1' && conv[i] <= '9')
		{
			while (ft_isdigit(conv[i + j]))
				j++;
			tmp = ft_substr(conv, i, j);
			len = ft_atoi(tmp);
			free(tmp);
			break ;
		}
		if (conv[i] == '.')
			break ;
		i++;
	}
	return (len);
}
