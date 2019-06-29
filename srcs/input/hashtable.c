/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:16:02 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 16:16:03 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Create a new structure for a room at a specific index of hashtable
** @param char *name - name of the room
** @param int link_index - integer storing corresponding entry in links array
** @param to later retrieve neighbors of this specific room.
** @return t_hash * as the address of the new node in the linked list
** @return starting at a specific index in hashtable. This index is a result
** @return of name of the room entering hashing function.
*/

static t_hash	*hashitem_origin(char *name, int link_index)
{
	t_hash	*new_hashitem;

	new_hashitem = (t_hash*)malloc(sizeof(t_hash));
	new_hashitem->hash_name = ft_strdup(name);
	new_hashitem->link_index = link_index;
	new_hashitem->visited = 0;
	new_hashitem->previous = NULL;
	new_hashitem->next = NULL;
	return (new_hashitem);
}

/*
** @desc Insert a new room to the start of specific linked list in hashtable
** @param t_room **head - address of head of linked list at hash_value index
** @param char *name - name of the room
** @param int link_index - goes from 0 to rooms_count storing unique integer
** @param for each node to access it's neighbors in another array.
** @return void
*/

static void		hashitem_insert(t_hash **head, char *name, int link_index)
{
	t_hash	*new_hashitem;

	new_hashitem = hashitem_origin(name, link_index);
	new_hashitem->next = *head;
	*head = new_hashitem;
}

/*
** @desc Based on hash value of room's name, either start a linked list at that
** @desc index or append a node to already existing linked list.
** @param t_hash **htable - array storing linked lists where each array's
** @param index corresponds to name of the room entering hashing function.
** @param char *name - name of the room
** @param int link_index - goes from 0 to rooms_count storing unique integer
** @param for each node to access it's neighbors in another array.
** @param int i - index in hashtable's list after hashing room's name
** @param So room's name is hashed and index in which hashtable's linked
** @param list a node should be inserted is returned, but each node receives
** @param unique link_index to later retrieve it's neighbors.
** @return void
*/

static void		htable_add(t_hash **htable, char *name, int link_index, int i)
{
	if (htable[i] == NULL)
		htable[i] = hashitem_origin(name, link_index);
	else
		hashitem_insert(&htable[i], name, link_index);
}

/*
** @desc Create an array of linked lists (hashtable) from rooms linked list.
** @desc Name of each room is insterted into a hashing function to
** @desc retrieve an index where in hashtable should it's
** @desc link reside. The link also saves link_index, which is used
** @desc to access another array of linked lists which lists neighbors
** @desc of each room.
** @param t_room **rooms - head of rooms linked list
** @param int rooms_count - number of rooms in rooms linked list
** @return t_room * as head of linked list containing
** @return data about each room from the input
*/

t_hash			**create_hashtable(t_room *rooms, int rooms_count)
{
	int			link_index;
	int			hash_value;
	t_hash		**hashtable;

	link_index = 0;
	hashtable = (t_hash**)malloc(sizeof(t_hash) * rooms_count);
	hashtable_null(hashtable, rooms_count);
	while (rooms != NULL)
	{
		hash_value = generate_hash_value(rooms->room_name, rooms_count);
		htable_add(hashtable, rooms->room_name, link_index, hash_value);
		rooms = rooms->next;
		link_index++;
	}
	return (hashtable);
}
