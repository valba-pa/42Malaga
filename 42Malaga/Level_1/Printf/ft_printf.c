/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valba-pa <valba-pa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:10 by valba-pa          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:40 by valba-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converformat(va_list arg, const char *s, int *i)
{
	void	*ptr;

	if (s[0] == 'c')
		ft_putchar_fd(va_arg(arg, int), i);
	else if (s[0] == 's')
		ft_putstr_fd(va_arg(arg, char *), i);
	else if (s[0] == 'p')
	{
		ptr = va_arg(arg, void *);
		if (ptr)
			ft_ptr(ptr, i);
		else
			ft_putstr_fd("0x0", i);
	}
	else if (s[0] == 'd' || s[0] == 'i')
		ft_putnbr_fd(va_arg(arg, unsigned int), i);
	else if (s[0] == 'u')
		ft_uputnbr(va_arg(arg, unsigned int), i);
	else if (s[0] == 'x')
		ft_hexa_low(va_arg(arg, unsigned long), i);
	else if (s[0] == 'X')
		ft_hexa_upper(va_arg(arg, unsigned long), i);
	else if (s[0] == '%')
		ft_putchar_fd('%', i);
}

int	ft_printf(const char *str, ...)
{
	va_list	variadic;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(variadic, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_converformat(variadic, str + i, &len);
		}
		else
			ft_putchar_fd(str[i], &len);
		i++;
	}
	va_end(variadic);
	return (len);
}