/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 19:02:01 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 19:02:02 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Display names of each room in rooms linked list
** @param t_room *head - start of linked list storing rooms
** @return void
*/

void	print_rooms(t_room *head)
{
	while (head != NULL)
	{
		ft_printf("%s ", head->room_name);
		head = head->next;
	}
	ft_printf("\n");
}

void	print_hashrow(t_hash *hashrow, int hash_value)
{
	while (hashrow != NULL)
	{
		ft_printf("HASH %d ROOM %-10s LINK_INDEX %d\n",
		hash_value, hashrow->hash_name, hashrow->link_index);
		hashrow = hashrow->next;
	}
}

void	print_hashtable(t_room *vertices,
t_hash **hashtable, int vertices_amount)
{
	int	hash_value;

	while (vertices != NULL)
	{
		hash_value = generate_hash_value(vertices->room_name, vertices_amount);
		print_hashrow(hashtable[hash_value], hash_value);
		vertices = vertices->next;
	}
}

void	link_print(t_link *head)
{
	while (head != NULL)
	{
		ft_printf("neighbor %s\n", head->neighbor);
		head = head->next;
	}
}
