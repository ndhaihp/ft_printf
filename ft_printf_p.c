/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c         	 				 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_hex(unsigned long p_address)
{
	size_t	i;

	i = 0;
	if (p_address == 0)
		i = 1;
	while (p_address != 0)
	{
		p_address = p_address / 16;
		i++;
	}
	return (i);
}


static char	*convert_hex(unsigned long p_address)
{
	char 			*p_address_hex;
	unsigned long	hex_value;
	size_t			len_hex;

	len_hex = length_hex(p_address) + 2;
	p_address_hex = malloc(len_hex + 1);
	if (!p_address_hex)
		return (NULL);
	if (p_address == 0)
		p_address_hex[len_hex - 1] = '0';
	p_address_hex[0] = '0';
	p_address_hex[1] = 'x';
	p_address_hex[len_hex] = '\0';
	while (p_address != 0)
	{
		hex_value = p_address % 16;
		if (hex_value >= 10)
			p_address_hex[len_hex - 1] = 'a' + hex_value - 10;
		else
			p_address_hex[len_hex - 1] = hex_value + '0';
		len_hex--;
		p_address = p_address / 16;
	}
	return (p_address_hex);	
}

int	ft_printf_p(va_list *args, int *len_str)
{
	void			*p;
	unsigned long	p_address;
	char			*p_address_hex;

	p = va_arg(*args, void *);
	if (!p)
	{
		*len_str += write(1, "(nil)", 5);
		return (*len_str);
	}
	p_address = (unsigned long)p;
	p_address_hex = convert_hex(p_address);
	if (!p_address_hex)
		return (-1);
	ft_putstr_fd(p_address_hex, 1);
	*len_str += ft_strlen(p_address_hex);
	free(p_address_hex);
	return (*len_str);	
}
