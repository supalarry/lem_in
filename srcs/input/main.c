/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:16:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 16:16:08 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

int				main(void)
{
	int			ants_count;
	int			rooms_count;
	t_room		*rooms;
	t_hash		**hashtable;
	t_link		**links;

	ants_count = count_ants();
	rooms = rooms_list();
	if (ants_count == -1 || rooms == NULL
	|| save_start(NULL) == NULL || save_end(NULL) == NULL)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	rooms_count = count_rooms(rooms);
	hashtable = create_hashtable(rooms, rooms_count);
	links = create_links(rooms_count, hashtable);
	max_paths(rooms_count, hashtable, links);
	if (technique(links, rooms_count, hashtable) == 1)
		breadth_first_search(hashtable, links);
	else
		breadth_first_search_big(hashtable, links);
	divide_ants(save_paths_array(NULL));
	print_hub(save_paths_array(NULL), save_combo(NULL), save_steps(-1));
	return (0);
}
