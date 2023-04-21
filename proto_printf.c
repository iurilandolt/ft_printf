/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:35 by rlandolt          #+#    #+#             */
/*   Updated: 2023/04/21 23:51:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	proto_printf(char	*format, ...)
{
	char *char_value;
	int int_value;
	va_list	args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				int_value = va_arg(args, int);
				ft_putnbr_fd(int_value, 1);
			}
			else if (*format == 's')
			{
				char_value = va_arg(args, char *);
				ft_putstr_fd(*format, 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
}

