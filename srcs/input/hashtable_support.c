/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_support.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 09:18:59 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/24 09:19:00 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Initialise each pointer in hashtable array to NULL
** @param t_hash **hashtable - array of linked lists where
** @param each linked list stores room's links with the same hash value
** @param int rooms_count - number of rooms in rooms linked list
** @return void
*/

void	hashtable_null(t_hash **hashtable, int rooms_count)
{
	int	i;

	i = 0;
	while (i < rooms_count)
	{
		hashtable[i] = NULL;
		i++;
	}
}

/*
** @desc Count room's name's ascii value
** @param char *room_name - name of the room used to find it in hashtable
** @return int as sum of name's characters' ascii values
*/

int		ascii_sum(char *room)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (room[i] != '\0')
	{
		sum = room[i];
		i++;
	}
	return (sum);
}

/*
** @desc This is the hashing function. Calculate index
** @desc of a linked list in hashtable where
** @desc a link of a specific room resides. It is done
** @desc based on name of the room thus providing quick search.
** @param char *room_name - name of the room used to find it in hashtable
** @param int rooms_count - number of rooms in rooms linked list
** @return int as index of a linked list in the hashtable
** @return where room's node storing integer for accessing
** @return neighbors resides.
*/

int		generate_hash_value(char *room, int rooms_count)
{
	int	sum;

	sum = ascii_sum(room);
	return (sum % rooms_count);
}
