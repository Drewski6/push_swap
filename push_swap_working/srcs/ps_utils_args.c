/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/14 10:18:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** free_table (free table) ***
 *
 *	Frees a char ** table created by ft_split.
 *	Takes a table to free 'table'.
 *	Returns nothing.
 */

void	free_table(char **table)
{
	int	i;

	while(table[i])
		free(table[i]);
	free(table);
	return ;
}

/*	*** s_arg_parse (single argument parse) ***
 *
 *	Parses a single string argument for integers.
 *	Takes a single string 's'.
 *	Returns address to t_list 'a' on success or 0 on ERROR.
 */

t_list	*s_arg_parse(char *s)
{
	size_t	i;
	char	**table;

	i = 0;
	table = 0;
	while (s[i])
	{
		if (!ft_strchr("0123456789 ", s[i]))
			return (-1);
		i++;
	}
	table = ft_split(s, ' ');
	if (!table)
		return (0);
	a = t_list_construct(table);
	if (!a)
	{
		free_table(table);
		return (0);
	}
	free_table(table);
	return (a);
}
