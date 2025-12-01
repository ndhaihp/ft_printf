/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c           	 			 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_nbr(int nbr)
{
	size_t	len;
	
	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_printf_d_i(va_list *args, int *len_str)
{
	int		nbr;

	nbr = va_arg(*args, int);
	ft_putnbr_fd(nbr, 1);
	*len_str += length_nbr(nbr);
	return (*len_str);
}