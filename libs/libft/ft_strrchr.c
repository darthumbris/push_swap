/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:40:04 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:40:05 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*rev;

	rev = (char *)s;
	while (*rev)
		rev++;
	while (c > 256)
		c -= 256;
	while (rev >= s)
	{
		if (*rev == c)
			return (rev);
		rev--;
	}
	if (c == '\0')
		return (rev);
	return (0);
}
