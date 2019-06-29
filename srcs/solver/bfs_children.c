/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_children.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 10:03:04 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/03 10:03:07 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Append children of current node at the end of linked list
** @param t_pathfinder **item - current node in the linked list
** @param t_link *link - node storing current node's room's neighbor
** @return t_pathfinder * as address of current node's neighbor node
*/

t_pathfinder		*append_item(t_pathfinder *item, t_link *link)
{
	t_pathfinder	*new;

	new = (t_pathfinder*)malloc(sizeof(t_pathfinder));
	new->room_name = link->neighbor;
	new->previous = item->room_name;
	new->previous_ptr = item;
	new->next = NULL;
	return (new);
}

/*
** @desc Count neighbors within neighbors list
** @param t_link *link - node storing current room's neighbors
** @return int as count of neighbors
*/

int					count_neighbors(t_link *neighbors)
{
	int	count;

	count = 0;
	while (neighbors)
	{
		count++;
		neighbors = neighbors->next;
	}
	return (count);
}

/*
** @desc Check if current child has been visited, if so, continue to next link
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param char *room_name - current node's room name
** @return int 1 if the room has been visited already
** @return int 0 if the room has been visited already
*/

int					check_for_visited(t_pathfinder *item, char *neighbor)
{
	while (item)
	{
		if (ft_strequ(item->room_name, neighbor))
			return (1);
		item = item->previous_ptr;
	}
	return (0);
}

/*
** @desc Calculate index of links array for room and return neighbors list
** @param char *room_name - current node's room name
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **links - 2d array storing list of neighbors for each room
** @return t_link * as list containing room's neighbors
*/

t_link				*n_list(char *room_name, t_hash **hashtable, t_link **links)
{
	int				index;

	index = hash_link(generate_hash_value(room_name, count_rooms(NULL)),\
	room_name, hashtable);
	return (links[index]);
}

/*
** @desc Find current node's children and append them to linked list
** @param t_pathfinder **item - current node in the linked list
** @param char *room_name - current node's room name
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **links - 2d array storing list of neighbors for each room
** @return void
*/

int					append_children(t_pathfinder *item, char *room_name,\
t_hash **hashtable, t_link **links)
{
	t_link			*neighbors;
	t_pathfinder	*path;

	path = item;
	neighbors = n_list(room_name, hashtable, links);
	while (path->next)
		path = path->next;
	while (neighbors)
	{
		if (check_for_visited(item, neighbors->neighbor))
		{
			neighbors = neighbors->next;
			continue ;
		}
		path->next = append_item(item, neighbors);
		path = path->next;
		if (ft_strequ(save_end(NULL), neighbors->neighbor) == 1)
		{
			if (!create_path(path, hashtable, links))
				return (0);
		}
		neighbors = neighbors->next;
	}
	return (1);
}
