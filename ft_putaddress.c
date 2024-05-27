/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:41:31 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/24 18:39:37 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putaddress(unsigned long long int n)
{
    int count;
    char *symbol;

    count = 0;
    symbol = "0123456789abcdef";
    if (n == 0)
		count += write(1, "0", 1);
    else if (n < 16)
        count += ft_putchar(symbol[n]);
    else
    {
        count += ft_putaddress(n / 16);
        count += ft_putchar(symbol[n % 16]);
    }
    return (count);
}
