/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c           	 			 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned(unsigned int n, size_t *len)
{
	char c;
	
	if (n / 10 != 0)
		ft_put_unsigned(n / 10, len);
	(*len)++;
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_printf_u(va_list *args, int *len_str)
{
	unsigned int	nbr;
	size_t			len_nbr;

	nbr = va_arg(*args, unsigned int);
	len_nbr = 0;
	ft_put_unsigned(nbr, &len_nbr);
	*len_str += len_nbr;
	return (*len_str);
}
