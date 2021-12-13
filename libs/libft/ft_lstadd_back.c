/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:41:36 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:41:37 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last;

	if (lst)
	{
		if (*lst)
		{
			lst_last = ft_lstlast(*lst);
			lst_last->next = new;
		}
		else
			*lst = new;
	}
}
