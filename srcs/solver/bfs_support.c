/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   depth_search.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:04:37 by fblom         #+#    #+#                 */
/*   Updated: 2019/05/29 14:04:38 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @gets If no path was found, output error and exit
** @param void
** @return void
*/

void		path_error(void)
{
	ft_printf("NO PATH FOUND\n");
	exit(1);
}

/*
** @gets number of connections a room has
** @param room name, room count, hashtable, links
** @return number of connections (int)
*/

int			get_connections(char *room, int rooms_count, t_hash **hashtable,\
															t_link **links)
{
	int		i;
	int		index;
	t_link	*connection;

	i = 0;
	index = hash_link(generate_hash_value(room, rooms_count), room, hashtable);
	connection = links[index];
	while (connection != NULL)
	{
		connection = connection->next;
		i++;
	}
	return (i);
}

/*
** @desc saves the max defined in max_paths so it can be easily
** @desc called from anywhere
** @param the max amount of paths
** @return the max amount of paths
*/

int			save_max(int paths)
{
	static int	max;

	if (paths != 0)
		max = paths;
	return (max);
}

/*
** @desc gets maximum needed paths (that don't cross)
** @param rooms_count, hashtable, links
** @return maximum number of needed paths
*/

int			max_paths(int rooms_count, t_hash **hashtable, t_link **links)
{
	int				max_paths;
	int				ants;
	int				entries;
	int				exits;

	ants = count_ants();
	entries = get_connections(save_start(NULL), rooms_count, hashtable, links);
	exits = get_connections(save_end(NULL), rooms_count, hashtable, links);
	if (ants <= entries && ants <= exits)
		max_paths = ants;
	if (entries <= ants && entries <= exits)
		max_paths = entries;
	if (exits <= ants && exits <= entries)
		max_paths = exits;
	save_max(max_paths);
	return (max_paths);
}
