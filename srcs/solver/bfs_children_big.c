/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_children_big.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 11:49:25 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/15 11:49:27 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Check if current child has been visited, if so, continue to next link
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param char *room_name - current node's room name
** @return int 1 if the room has been visited already
** @return int 0 if the room has been visited already
*/

int					check_for_visited_big(t_hash **hashtable, char *room_name)
{
	int				hash;
	t_hash			*node;

	hash = generate_hash_value(room_name, count_rooms(NULL));
	node = hashtable[hash];
	while (node)
	{
		if (ft_strequ(room_name, node->hash_name))
		{
			if (node->visited == 1)
				return (1);
		}
		node = node->next;
	}
	return (0);
}

/*
** @desc Find current node's children and append them to linked list
** @param t_pathfinder **item - current node in the linked list
** @param char *room_name - current node's room name
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **links - 2d array storing list of neighbors for each room
** @return void
*/

int					append_children_big(t_pathfinder *item, char *room_name,\
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
		if (check_for_visited_big(hashtable, neighbors->neighbor))
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
