/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   links_support2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/16 17:39:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/16 17:39:14 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc When extracting data from connections, each room
** @desc is checked if it exists in the hashtable. If not,
** @desc non existing connection has been provided.
** @param char *room - room to search from connection
** @param t_hash **htable - hashtable consisting of all rooms
** @param int rooms_count - count of all rooms
** @return void
*/

void	find_room(char *room, t_hash **htable, int rooms_count)
{
	int		i;
	t_hash	*current;

	i = 0;
	current = NULL;
	while (i < rooms_count)
	{
		current = htable[i];
		while (current)
		{
			if (ft_strequ(current->hash_name, room))
				return ;
			current = current->next;
		}
		i++;
	}
	ft_printf("CONNECTION TO NON EXISTING ROOM\n");
	exit(1);
}
