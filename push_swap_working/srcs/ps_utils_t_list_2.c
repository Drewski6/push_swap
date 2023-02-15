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
