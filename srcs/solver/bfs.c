/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:07:12 by fblom         #+#    #+#                 */
/*   Updated: 2019/05/28 14z:07:13 by fblom         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Sets current link in the linked list as visited, so that it's children
** @desc don't visit it again causing an infinite loop.
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param char *room_name - name of the room of the current link
** @return void
*/

void				set_visited(t_hash **hashtable, char *room_name)
{
	int				hash;
	t_hash			*node;

	hash = generate_hash_value(room_name, count_rooms(NULL));
	node = hashtable[hash];
	while (node)
	{
		if (ft_strequ(room_name, node->hash_name))
		{
			node->visited = 1;
			break ;
		}
		node = node->next;
	}
}

/*
** @desc Initialise start of linked list of currently searched rooms for path
** @param char *room_name - name of the starting room from which search starts
** @return t_pathfinder * as address of a first node in the linked list
*/

t_pathfinder		*add_first_item(char *room_name)
{
	t_pathfinder	*first;

	first = (t_pathfinder *)malloc(sizeof(t_pathfinder));
	first->room_name = room_name;
	first->previous = NULL;
	first->previous_ptr = NULL;
	first->next = NULL;
	return (first);
}

/*
** @desc Free linked list
** @param t_pathfinder *head - head of linked list
** @return void
*/

void				free_pathfinder(t_pathfinder *head)
{
	t_pathfinder	*head_copy;

	while (head)
	{
		head_copy = head;
		head_copy = head->next;
		free(head);
		head = head_copy;
	}
}

/*
** @desc Using breadth first search finds shortest paths.
** @desc Furthermore, a linked list of rooms of and their neighbors is created
** @desc to later save path once it is found.
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **link - 2d array storing list of neighbors for each room
** @return void
*/

void				breadth_first_search(t_hash **hashtable, t_link **link)
{
	char			*start_room;
	char			*end_room;
	t_pathfinder	*head;
	t_pathfinder	*item;

	start_room = save_start(NULL);
	end_room = save_end(NULL);
	item = add_first_item(start_room);
	head = item;
	while (item)
	{
		if (ft_strequ(end_room, item->room_name) != 1
		&& ft_strequ(end_room, item->previous) != 1)
		{
			if (!append_children(item, item->room_name, hashtable, link))
				break ;
		}
		item = item->next;
	}
	free_pathfinder(head);
	if (save_paths_array(NULL) == NULL)
		path_error();
}

/*
** @desc Using breadth first search finds shortest paths.
** @desc Furthermore, a linked list of rooms of and their neighbors is created
** @desc to later save path once it is found.
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **link - 2d array storing list of neighbors for each room
** @return void
*/

void				breadth_first_search_big(t_hash **hashtable, t_link **link)
{
	char			*start_room;
	char			*end_room;
	t_pathfinder	*head;
	t_pathfinder	*item;

	start_room = save_start(NULL);
	end_room = save_end(NULL);
	item = add_first_item(start_room);
	head = item;
	while (item)
	{
		if (ft_strequ(end_room, item->room_name) != 1
		&& ft_strequ(end_room, item->previous) != 1)
		{
			set_visited(hashtable, item->room_name);
			if (!append_children_big(item, item->room_name, hashtable, link))
				break ;
		}
		item = item->next;
	}
	free_pathfinder(head);
	if (save_paths_array(NULL) == NULL)
		path_error();
}
