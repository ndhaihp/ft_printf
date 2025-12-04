/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c       	 				 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_hex(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}


static char	*convert_hex(unsigned int n, char *str)
{
	char 			*n_hex;
	size_t			len_hex;

	len_hex = length_hex(n);
	n_hex = malloc(len_hex + 1);
	if (!n_hex)
		return (NULL);
	if (n == 0)
		n_hex[len_hex - 1] = '0';
	n_hex[len_hex] = '\0';
	while (n != 0)
	{
		if ((n % 16 >= 10) && *str == 'x')
			n_hex[len_hex - 1] = 'a' + n % 16 - 10;
		else if ((n % 16 >= 10) && *str == 'X')
			n_hex[len_hex - 1] = 'A' + n % 16 - 10;
		else
			n_hex[len_hex - 1] = n % 16 + '0';
		len_hex--;
		n = n / 16;
	}
	return (n_hex);	
}

int	ft_printf_x_X(va_list *args, int *len_str, char *str)
{
	unsigned int		n;
	char	*n_hex;

	n = va_arg(*args, unsigned int);
	n_hex = convert_hex(n, str);
	if (!n_hex)
		return (-1);
	ft_putstr_fd(n_hex, 1);
	*len_str += ft_strlen(n_hex);
	free(n_hex);
	return (*len_str);
}
