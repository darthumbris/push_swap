/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:40:48 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:40:49 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		remain_nbr;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(0 - n, fd);
	}
	else if (n > 9)
	{
		remain_nbr = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putnbr_fd(remain_nbr, fd);
	}
	else
	{
		n = n + '0';
		write(fd, &n, 1);
	}
}
