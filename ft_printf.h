/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:36 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/27 15:53:26 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putaddress(unsigned long long int n);
int ft_putnbr(int n);
unsigned int ft_putunbr(unsigned int n, unsigned int base);
unsigned int ft_putxnbr_uppercase(unsigned int n, unsigned int base);
int ft_printf(const char *format, ...);

#endif