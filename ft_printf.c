/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:35 by rlandolt          #+#    #+#             */
/*   Updated: 2023/04/27 16:19:59 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg(va_list args, const char c)
{
	int	fsize;

	fsize = 0;
	if (c == '%')
	{
		if (c == 'd' || c == 'i')
			fsize += ft_printnbr(va_arg(args, int));
		else if (c == 'c')
			fsize += ft_printchar(va_arg(args, int));
		else if (c == 's')
			fsize += ft_printstr(va_arg(args, char *));
		else if (c == 'u')
			fsize += ft_print_u_nbr(va_arg(args, unsigned int));
		else if (c == 'x' || c == 'X')
			fsize += ft_printhex(va_arg(args, unsigned int), c);
		else if (c == 'p')
			fsize += ft_printptr(va_arg(args, unsigned long));
		else if (c == '%')
			fsize += ft_printchar('%');
	}
	return (fsize);
}

int	ft_printf(const char *format, ...)
{
	int		fsize;
	va_list	args;

	fsize = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fsize += check_arg(args, *format);
		}
		else
			fsize += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (fsize);
}
/*
	https://github.com/Surfi89/ft_printf
	https://github.com/Anasjaidi/ft_printf
	https://github.com/42Starfleet/ft_printf
*/
