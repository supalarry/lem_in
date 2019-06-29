/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 10:03:13 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/03 10:03:15 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc In the first node on path's linked list, store linked list
** @desc with path's crossover nodes and allocate integer array to
** @desc store later other paths' indexes with which this one crosses
** @param t_room *head - address of first node of path's linked list
** @param t_cross_node *nodehead - address of crossover nodes linked list
** @param int len - length of the path
** @return void
*/

static void		path_metadata(t_room *head, t_cross_node *nodehead, int len)
{
	int	i;
	int	count;

	i = 0;
	count = count_crossovers(nodehead) * 100 + 1;
	head->cross_nodes = nodehead;
	head->cross_paths = (int *)malloc(sizeof(int) * count);
	while (i < count)
	{
		head->cross_paths[i] = -1;
		i++;
	}
	head->len = len - 1;
}

/*
** @desc Initialise variables for create_path() and allocate array for paths
** @param t_room ***paths_array - address of array storing all paths
** @param t_room **head - address of first node in the linked list
** @param t_cross_node **nodehead - address of crossover nodes linked list
** @param int *len - address of integer storing length of the path
** @return void
*/

static void		initialise_vars(t_room ***paths_array, t_room **head,\
								t_cross_node **nodehead, int *len)
{
	if (!(*paths_array))
		*paths_array = (t_room **)malloc(sizeof(t_room *) * 1000000);
	*head = NULL;
	*nodehead = NULL;
	*len = 0;
}

/*
** @desc Either originate list for rooms of a path or append a new room
** @param t_room **head - address of pointer point to first room in the path
** @return void
*/

static void		room_list(t_room **head, t_pathfinder *item)
{
	if (*head == NULL)
		*head = room_origin(item->room_name);
	else
		room_insert(head, item->room_name);
}

/*
** @desc Save array storing all paths as linked lists
** @param t_room **paths_array - address of the array to be stored
** @return NULL if address is stored
** @return address of previously saved array otherwise
*/

t_room			**save_paths_array(t_room **paths_array)
{
	static t_room	**saved_paths_array;

	if (paths_array)
	{
		saved_paths_array = paths_array;
		return (NULL);
	}
	return (saved_paths_array);
}

/*
** @desc Once end path is found in the linked list, create a new linked list
** @desc storing full path to the end. Each path's first node also holds
** @desc a linked list of nodes within the path with more than 2 neighbors.
** @desc More than 2 neigbhors imply it is a crossover node. First node also
** @desc holds 2d int array to later hold with which paths does it cross.
** @param t_pathfinder **item - current node in the linked list indicating
** @param that ending node has been found
** @param t_hash **hashtable - 2d array storing access to neighbors for rooms
** @param t_link **links - 2d array storing list of neighbors for each room
** @return void
*/

int				create_path(t_pathfinder *item, t_hash **hashtable,
											t_link **links)
{
	static int		i;
	static t_room	**paths_array;
	int				len;
	t_room			*head;
	t_cross_node	*nodehead;

	initialise_vars(&paths_array, &head, &nodehead, &len);
	while (item != NULL)
	{
		room_list(&head, item);
		if (crossover_node(item->room_name, hashtable, links))
			add_crossover(item->room_name, &nodehead);
		item = item->previous_ptr;
		len++;
	}
	path_metadata(head, nodehead, len);
	paths_array[i] = head;
	path_crossovers(paths_array, i);
	save_paths_array(paths_array);
	if (i != 0 && (unsigned int)len > save_steps(-1))
		return (0);
	i++;
	if (!get_combinations(paths_array, i))
		return (0);
	return (1);
}
