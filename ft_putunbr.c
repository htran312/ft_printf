/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:09 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/28 15:57:04 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunbr(unsigned int n, unsigned int base)
{
	int		count;
	int		temp;
	char	*symbol;

	symbol = "0123456789abcdef";
	count = 0;
	temp = 0;
	if (n < base)
		temp += ft_putchar(symbol[n]);
	else
	{
		{
			temp += ft_putunbr((n / base), base);
			if (temp == -1)
				return (-1);
		}
		temp += ft_putchar(symbol[n % base]);
		if (temp == -1)
			return (-1);
	}
	return (temp + count);
}
