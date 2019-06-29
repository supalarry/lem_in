/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   technique.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 11:35:54 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/15 11:35:56 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Find start and end rooms' indexes in links array to skip them
** @desc when deciding which technique to use.
** @param int *start - address of int storing starting room's link index
** @param int *end - address of int storing ending room's link index
** @param int rooms_count - number of rooms within the antfarm
** @param t_hash **htable - array holding all rooms' t_link array's index
** @return void
*/

static void	init_var(int *start, int *end, int rooms_count, t_hash **htable)
{
	*start = hash_link(generate_hash_value(save_start(NULL),
rooms_count), save_start(NULL), htable);
	*end = hash_link(generate_hash_value(save_end(NULL),
rooms_count), save_end(NULL), htable);
}

/*
** @desc Based on the amount of room connections decide which technique to use
** @param t_link **head - array holding a linked list for each rooms neighbors
** @param int rooms_count - number of rooms within the antfarm
** @param t_hash **hashtable - array holding all rooms' t_link array's index
** @return 1 to use breadth_first_search() function for finding paths
** @return 0 to use breadth_first_search_big() function for finding paths
*/

int			technique(t_link **head, int rooms_count, t_hash **htable)
{
	int		i;
	int		start;
	int		end;
	int		solo;
	t_link	*neighbors;

	i = 0;
	init_var(&start, &end, rooms_count, htable);
	while (i < rooms_count)
	{
		if (i != start && i != end)
		{
			solo = 0;
			neighbors = head[i];
			while (neighbors)
			{
				solo++;
				neighbors = neighbors->next;
			}
			if (solo > 6)
				return (0);
		}
		i++;
	}
	return (1);
}
