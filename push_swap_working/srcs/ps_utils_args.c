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

/*	*** table_free (table free) ***
 *
 *	Frees a char ** table created by ft_split.
 *	Takes a table to free 'table'.
 *	Returns nothing.
 */

void	table_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	return ;
}

/*	*** table_err_check (table error check) ***
 *
 *	Checks table for correct strings for push_swap program
 *	Takes a table of strings.
 *	Returns 0 on success or -1 on ERROR.
 */

int	table_err_check(char **table)
{
	int	i;
	int	j;

	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			if (!ft_strchr("0123456789-+", table[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/*	*** table_dup (table duplicate) ***
 *
 *	Makes a copy of a table and all of it's contents.
 *	Takes a char table (char **).
 *	Returns a copy of the table.
 */

char	**table_dup(char **table)
{
	int		i;
	int 	size;
	char	**new_table;

	i = 0;
	size = 0;
	while (table[size])
		size++;
	new_table = (char **)ft_calloc((size + 1), sizeof(char *));
	if (!new_table)
		return (0);
	while (table[i])
	{
		new_table[i] = ft_strdup(table[i]);
		if (!new_table[i])
		{
			table_free(new_table);
			return (0);
		}
		i++;
	}
	return (new_table);
}

/*	*** m_arg_parse (multi argument parse) ***
 *
 *	Parses a multiple string arguments for integers.
 *	Takes a table of strings 's_table'.
 *	Returns address to t_list 'a' on success or 0 on ERROR.
 */

t_list	*m_arg_parse(char **s_table)
{
	char	**new_table;
	t_list	*a;

	new_table = table_dup(&s_table[1]);
	if (!new_table)
		return (0);
	if (table_err_check(new_table))
	{
		table_free(new_table);
		return (0);
	}
	a = t_list_construct(new_table);
	table_free(new_table);
	if (!a)
		return (0);
	return (a);
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
	t_list	*a;

	i = 0;
	table = 0;
	while (s[i])
	{
		if (!ft_strchr("0123456789-+ ", s[i]))
			return (0);
		i++;
	}
	table = ft_split(s, ' ');
	if (!table)
		return (0);
	a = t_list_construct(table);
	table_free(table);
	if (!a)
		return (0);
	return (a);
}
