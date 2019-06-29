/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_crossovers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/01 14:04:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/01 14:04:35 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Count crossover nodes in crossover nodes linked list to allocate
** @desc space to later hold indexes of paths that the path cross.
** @param t_cross_node *head - address of head of linked list
** @return int as number of crossover nodes
*/

int						count_crossovers(t_cross_node *head)
{
	int count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

/*
** @desc Creates link for linked list storing crossover nodes
** @param char *room - name of the room which has more than 2 neighbors
** @return void
*/

static t_cross_node		*cross_node_origin(char *room)
{
	t_cross_node	*node;

	node = (t_cross_node *)malloc(sizeof(t_cross_node));
	node->cross_node = ft_strdup(room);
	node->next = NULL;
	return (node);
}

/*
** @desc Appends link to linked list storing crossover nodes
** @param t_cross_node **head - address of address of head of linked list
** @param char *room - name of the room which has more than 2 neighbors
** @return void
*/

static void				cross_node_insert(t_cross_node **head, char *room)
{
	t_cross_node	*node;

	node = cross_node_origin(room);
	node->next = *head;
	*head = node;
}

/*
** @desc If room in path has more than 2 neighbors, add new link with it's name
** @desc in linked list storing path's crossover nodes
** @param char *room - name of the room which has more than 2 neighbors
** @param t_cross_node **head - address of address of head of linked list
** @return void
*/

void					add_crossover(char *room, t_cross_node **head)
{
	if (*head == NULL)
		*head = cross_node_origin(room);
	else
		cross_node_insert(head, room);
}

/*
** @desc Based on the count of neighbors tell if room in a path is crossover
** @param char *room - name of the room which neighbors are counted
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **links - 2d array storing list of neighbors for each room
** @return void
*/

int						crossover_node(char *room, t_hash **hashtable,\
													t_link **links)
{
	int				count;
	int				index;
	t_link			*neighbors;

	count = 0;
	index = hash_link(generate_hash_value(room, count_rooms(NULL)),\
													room, hashtable);
	neighbors = links[index];
	while (neighbors != NULL)
	{
		count++;
		neighbors = neighbors->next;
	}
	if (count > 2)
		return (1);
	return (0);
}
