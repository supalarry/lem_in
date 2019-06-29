/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_crossovers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 16:38:19 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/02 16:38:24 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc If common crossover node was found, note in path's first node's
** @desc cross_paths array the index of path with which path crosses.
** @param t_room *one - node storing path's crossover paths array
** @param t_room *two - node storing other path's crossover paths array
** @param int o - index of one's position in paths array
** @param int t - index of two's position in paths array
** @return void
*/

void			insert_crossover_path(t_room *one, t_room *two, int o, int t)
{
	long long	i;

	i = 0;
	while (one->cross_paths[i] != -1)
		i++;
	one->cross_paths[i] = t;
	i = 0;
	while (two->cross_paths[i] != -1)
		i++;
	two->cross_paths[i] = o;
}

/*
** @desc Finds if two crossover linked lists share same crossover node
** @param t_cross_node *one - linked list storing path's crossover nodes
** @param t_cross_node *two - linked list storing other path's crossover nodes
** @return int 1 if common crossover node was found
** @return int 0 if common crossover node was not found
*/

int				shared_crossover(t_cross_node *one, t_cross_node *two)
{
	t_cross_node *two_copy;

	two_copy = two;
	while (one != NULL)
	{
		while (two_copy != NULL)
		{
			if (ft_strequ(one->cross_node, two_copy->cross_node) &&\
				!ft_strequ(save_start(NULL), one->cross_node) &&\
				!ft_strequ(save_end(NULL), two_copy->cross_node))
				return (1);
			two_copy = two_copy->next;
		}
		two_copy = two;
		one = one->next;
	}
	return (0);
}

/*
** @desc Each time a new path is inserted in paths array
** @desc check if new path's crossover nodes are found in one
** @desc of previous paths. If so, each path saves with which
** @desc path it crosses by storing crossing path's index.
** @param t_room **paths_array - address of array storing paths
** @param int last_i - index of newly inserted path
** @return void
*/

void			path_crossovers(t_room **paths_array, int last_i)
{
	int i;

	i = 0;
	while (i < last_i)
	{
		if (shared_crossover(paths_array[i]->cross_nodes,\
			paths_array[last_i]->cross_nodes))
			insert_crossover_path(paths_array[i],\
				paths_array[last_i], i, last_i);
		i++;
	}
}
