/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edges.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 19:33:47 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 19:33:48 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Originate room's neighbor's node
** @param char *neighbor - neighbor to add
** @return t_link * as link storing node's neighbor
*/

static t_link	*neighbor_origin(char *neighbor)
{
	t_link	*new_link;

	new_link = (t_link*)malloc(sizeof(t_link));
	new_link->neighbor = ft_strdup(neighbor);
	new_link->next = NULL;
	return (new_link);
}

/*
** @desc Insert a new neighbor to room's neighbor linked list
** @param t_room **head - address of head of linked list storing
** @param room's neigbhors
** @param char *neighbor - neighbor to add
** @return void
*/

static void		neighbor_insert(t_link **head, char *neighbor)
{
	t_link	*new_link;

	new_link = neighbor_origin(neighbor);
	new_link->next = *head;
	*head = new_link;
}

/*
** @desc Given specific link_index at links array of linked lists,
** @desc originate neighbor linked list or insert a neighbor link
** @param int link_index - linked list of neighbors of specific room
** @param char *neighbor - neighbor of a room
** @param t_link **links - array storing linked lists of rooms' neighbors
** @return void
*/

static void		room_neighbors(int link_index, char *neighbor, t_link **links)
{
	if (links[link_index] == NULL)
		links[link_index] = neighbor_origin(neighbor);
	else
		neighbor_insert(&links[link_index], neighbor);
}

/*
** @desc Given a line storing link between two rooms in the form X-Y,
** @desc extract both rooms using extract_room_1 and extract_room_2 functions.
** @desc Then, generate hash value for reach room to know where in hashtable
** @desc the room can be found to later find link_index. Then, find link_indexes
** @desc of both rooms in hashtable based on their hashes and names.
** @desc Finally, call room_neighbors add neighbor at the specific link_index.
** @param t_link **links - array storing linked lists of neigbors
** @param char *line - line storing the link X-Y
** @param int n - count of rooms
** @param t_hash **htable - array of linked lists to find link_index
** @param of a specific room to know where to insert a specific neighbor.
** @return void
*/

static void		link_split(t_link **links, char *line, int n, t_hash **htable)
{
	int		room_hashes[2];
	int		link_index_1;
	int		link_index_2;
	char	*room_1;
	char	*room_2;

	room_1 = extract_room_1(line);
	room_2 = extract_room_2(line);
	find_room(room_1, htable, count_rooms(NULL));
	find_room(room_2, htable, count_rooms(NULL));
	room_hashes[0] = generate_hash_value(room_1, n);
	room_hashes[1] = generate_hash_value(room_2, n);
	link_index_1 = hash_link(room_hashes[0], room_1, htable);
	link_index_2 = hash_link(room_hashes[1], room_2, htable);
	room_neighbors(link_index_1, room_2, links);
	room_neighbors(link_index_2, room_1, links);
	free(room_1);
	free(room_2);
}

/*
** @desc Create an array of linked lists where each linked list
** @desc stores information about neighbors of a room. In the hashtable
** @desc in a link of a specific linked list resides link_index which
** @desc tells within which linked list reside neighbors of a room. So first
** @desc room's name is hashed to get index of linked list in hashtable, then
** @desc room is found within that linked list and there is found link_index
** @desc to further find room's neighbors stored in a linked list at link_index
** @desc of links array.
** @param int rooms_count - count of the rooms.
** @param t_hash **hashtable - array of linked lists used to find link_index
** @param previously assigned and at that linked list store room's neighbors. So
** @param link_index was assigned while creating hashtable,
** @param but only now the linked list containing neighbors is being created.
** @return t_link ** as an array of linked lists where each linked list contains
** @return neighbors of a specific room
*/

t_link			**create_links(int rooms_count, t_hash **hashtable)
{
	int		ret;
	char	*line;
	t_link	**links;

	ret = 1;
	line = save_link(NULL, NULL);
	links = (t_link**)malloc(sizeof(t_link) * rooms_count);
	links_null(links, rooms_count);
	while (ret > 0)
	{
		if (ft_strlen(line) > 0 && line[0] != '#')
			link_split(links, line, rooms_count, hashtable);
		else if (ft_strlen(line) == 0)
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		free(line);
		ret = get_next_line(0, &line);
		if (ret > 0 && ft_strlen(line))
			copy_input(line);
	}
	return (links);
}
