/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:02:41 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/27 20:22:35 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>*/


/*static int ft_putchar(char c)
{
    if (write(1, &c, 1) != 1)
        return (-1);
    else
        return (1);
}
static int ft_putstr(char *str)
{
    int i;
    int res;
    int temp;
    
    res = 0;
    temp = 0;
    if (!str)
    {
        temp = ft_putstr("(null)");
        if (temp == -1)
            return (-1);
    }
    else
    {
        i = 0;
        while(str[i] != '\0')
        {
            temp += ft_putchar(str[i]);
            if (temp == -1)
                return (-1);
            else
                i++;
        }
    }
    return (res + temp);
}
static unsigned int ft_putunbr(unsigned int n, unsigned int base)
{
    int count;
    int temp;
    char *symbol;

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
static int ft_putnbr(int n)
{
    int count;
    int temp;

    count = 0;
    temp = 0;
    if (n < 0)
    {
        {
            if (ft_putchar('-') == -1)
                return (-1);
            temp++;
            n *= -1;
        }
        temp += ft_putunbr(n, 10);
        if (temp == -1)
            return (-1);
    }
    else
        temp += ft_putunbr(n, 10);
        if (temp == -1)
            return (-1);
    return (count + temp);
}
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
static int ft_putaddress(unsigned long long int n)
{
    int count;
    
    count = 0;
    count = ft_putaddress_helper(n);
    if (count == -1)
        return (-1);
    return (count + 2);
}
static unsigned int ft_putxnbr_uppercase(unsigned int n, unsigned int base)
{
    int count;
    int temp;
    char *symbol;

    symbol = "0123456789ABCDEF";
    count = 0;
    temp = 0;
    if (n < base)
        temp += ft_putchar(symbol[n]);
    else
    {
        {
            temp += ft_putxnbr_uppercase((n / base), base);
            if (temp == -1)
                return (-1);
        }
        temp += ft_putchar(symbol[n % base]);
        if (temp == -1)
            return (-1);
    }
    return (temp + count);
}*/

int ft_check_format(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c == 'p')
    {
        if (ft_putstr("0x") == -1)
            return (-1);
        return (ft_putaddress(va_arg(args, unsigned long long int)));
    }
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (c == 'u')
        return (ft_putunbr((va_arg(args, unsigned int)), 10));
    else if (c == 'x')
        return (ft_putunbr((va_arg(args, unsigned int)), 16));
    else if (c == 'X')
        return (ft_putxnbr_uppercase((va_arg(args, unsigned int)), 16));
    else if (c == '%')
        return (ft_putchar('%'));
    else
        return (-1);
}

int ft_printf(const char *format, ...)
{
    int i;
    int count;
    int temp;
    va_list list;
    va_start (list, format);
    
    i = 0;
    count = 0;
    temp = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] != '\0')
            {
                temp = ft_check_format(list, (format[i]));
                if (temp == -1)
                    return (-1);
            }
            count += temp;
        }
        else
        {
            if (ft_putchar(format[i]) == -1)
                return (-1);
            count++;
        }
        i++;
    }
    va_end(list);
    return (count);
}

/*int main(void)
{
    int printf_count;
    
    //Print a single character
    //printf_count = ft_printf("hello %c\n", 'K');
    //printf("(Printf)%c\n", 'K');
    
    
    //Print a string of characters
    //char *str = "ABC";
    ///printf_count = ft_printf("%s\n", str);
    //printf("(Printf)%s\n", str);

    //Print an address
    char *str = "ABC";
    printf_count = ft_printf("%p\n", &str);
    printf("(Printf)%p\n", &str);

    //Printf a decimal (base 10) number
    //int n = -2147483648;
    //printf_count = ft_printf("%d\n", n);
    //printf("(Printf)%d\n", n);
    
    //Print an integer (base 10) number (Wraps around and will print 2147483647)
    //int n = -2147483649;
    //printf_count = ft_printf("%i\n", n);
    //printf("(Printf)%i\n", n);

    //Print an unsigned decimal (base 10 number) (-2147483647 returns 2^31+1=2147483648+1)
    //int n = -2147483647;
    //printf_count = ft_printf("%u\n", n);
    //printf("(Printf)%u\n", n);

    //Print a number in hexadecimal (base 16) lowercase format (7fffffff) is 2147483647)
    //int n = 2147483649;
    //printf_count = ft_printf("%x\n", n);
    //printf("(Printf)%x\n", n);

    //Prints a number in hexadecimal (base 16) uppercase format.
    //int n = -1;
    //printf_count = ft_printf("%X\n", n);
    //printf("(Printf)%X\n", n);

    //Prints a percent sign
    //printf_count = ft_printf("%%\n");
    //printf("(Printf)%%\n");
    
    //How many characters had been printed?
    printf("Result of ft_printf is %d\n", printf_count);
    
    return (0);
}*/