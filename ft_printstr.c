/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:54:37 by rlandolt          #+#    #+#             */
/*   Updated: 2023/04/27 15:02:54 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str = NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while(*str)
	{
		ft_printchar(*(str + i));
		i++;
	}
	return (i);
}
