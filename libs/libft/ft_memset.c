/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:40:56 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:40:57 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	int				i;

	temp = b;
	i = 0;
	while (len > 0)
	{
		temp[i] = c;
		len--;
		i++;
	}
	return (b);
}
