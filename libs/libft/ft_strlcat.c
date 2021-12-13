/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:40:27 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:40:28 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		dst_len;
	const char	*src_temp;
	size_t		ret;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	src_temp = src;
	dst_len = ft_strlen(dst);
	if (dstsize > dst_len)
		ret = ft_strlen(src) + dst_len;
	else
		return (ft_strlen(src) + dstsize);
	while (src_temp[i] && dst_len < (dstsize - 1))
		dst[dst_len++] = src_temp[i++];
	dst[dst_len] = '\0';
	return (ret);
}
