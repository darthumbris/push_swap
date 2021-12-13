/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:41:07 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:41:08 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*s_temp;
	unsigned char	c_temp;

	s_temp = s;
	c_temp = c;
	while (n)
	{
		n--;
		if (*s_temp == c_temp)
			return ((void *)s_temp);
		s_temp++;
	}
	return (NULL);
}
