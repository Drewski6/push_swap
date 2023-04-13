/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_t_list_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:40:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/15 12:40:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** t_list_free_content (list free content) ***
 *
 *	Frees the content of a list.
 *	Passed as function pointer to ft_lstclear.
 *	Takes address of content to free 'content'.
 *	Returns nothing.
 */

void	t_list_free_content(void *content)
{
	free(content);
	return ;
}

/*
 *
 *
 */

int	int_max_check(char *str_num, int *number)
{
	char	*itoa_ret;

	itoa_ret = ft_itoa(*number);
	if (!itoa_ret)
		return (-1);
	if (str_num[0] == '+')
	{
		if (ft_strncmp((str_num + 1), itoa_ret, ft_strlen(str_num)))
			return (free(itoa_ret), -1);
	}
	else if (!ft_strncmp(str_num, "-0", 2))
		return (free(itoa_ret), 0);
	else if (ft_strncmp(str_num, itoa_ret, ft_strlen(str_num)))
		return (free(itoa_ret), -1);
	free(itoa_ret);
	return (0);
}
