/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:41:31 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/27 20:21:36 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putaddress_helper(unsigned long long int n)
{
    int count;
    char *symbol;
    
    count = 0;
    symbol = "0123456789abcdef";
    if (n < 16)
        count += ft_putchar(symbol[n]);
    else
    {
        count += ft_putaddress_helper(n / 16);
        count += ft_putchar(symbol[n % 16]);
    }
    return (count);
}
int ft_putaddress(unsigned long long int n)
{
    int count;
    
    count = 0;
    count = ft_putaddress_helper(n);
    if (count == -1)
        return (-1);
    return (count + 2);
}
