/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c           	 				 		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainguye <dainguye@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:58 by dainguye          #+#    #+#             */
/*   Updated: 2025/11/11 10:57:58 by dainguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arg_handling(va_list *args, int *len_str, const char *str)
{
	if (*str == 'c')
		ft_printf_c(args, len_str);
	else if (*str == 's')
		ft_printf_s(args, len_str);
	else if (*str == 'p')
	{
		if (ft_printf_p(args, len_str) == -1)
			return (-1);
	}
	else if (*str == 'd' || *str == 'i')
		ft_printf_d_i(args, len_str);	
	else if (*str == 'u')
		ft_printf_u(args, len_str);
	else if (*str == 'x' || *str == 'X')
	{
		if (ft_printf_x_X(args, len_str, (char *)str) == -1)
			return (-1);
	}
	else if (*str == '%')
		ft_printf_pct(len_str);
	return (0);
}

int	ft_printf(const char *str, ...)
{	
	int		len_str;
	va_list	args;

	va_start(args, str);
	len_str = 0;	
	while (*str)
	{
		if(*str == '%')
		{
			str++;
			if (arg_handling(&args, &len_str, str) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			len_str += write(1, str, 1);
		str++;		
	}
	va_end(args);
	return (len_str);	
}
int	main(void)
{
	char	c;
	char	*s;
	int		len_str;
	void	*p;
	int		nbr;
	unsigned int	u;
	int 	x;

	c = 'B';
	s = "42 school";
	p = &s;
	nbr = -32;
	u = -1;
	x = 42;
	len_str = ft_printf("Hello %c", c);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("Hello %s", s);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("Address of s = %p", p);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format d = %d", nbr);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format i = %i", nbr);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format u = %u", u);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format x = %x", x);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format -x = %x", -x);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format X = %X", x);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("nbr format -X = %X", -x);
	printf("\nLength of string = %d\n\n", len_str);
	len_str = ft_printf("%% %d", 42);
	printf("\nLength of string = %d\n\n", len_str);
	printf("\nprintf unsigned decimal %u", u);
	printf("\nx format: %x", x);
	printf("\n-x format: %x", -x);
	printf("\nX format: %X", x);
	printf("\n-X format: %X", -x);
	printf("\n%% %d", 42);
}