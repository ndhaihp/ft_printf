/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c	       	 					 	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	size_t	i;

	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	i = 0;
	while (n != 0)
	{
		if (n < 0)
			str[i] = -(n % 10) + '0';
		else
			str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		write(fd, &str[i - 1], 1);
		i--;
	}
}
// int	main(void)
// {	
// 	ft_putnbr_fd(-11520, 1);
// 	return (0);
// }
