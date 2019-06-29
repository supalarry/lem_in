/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 10:06:49 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/03 10:06:51 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

void				print_path_old(t_room *head)
{
	static int no = 0;

	ft_printf("---PATH-%i---\n", no);
	no++;
	while (head != NULL)
	{
		ft_printf("%s\n", head->room_name);
		head = head->next;
	}
	ft_printf("\n");
}

void				print_crossover(t_cross_node *head)
{
	static int no = 0;

	ft_printf("Path %i has crossover nodes ", no);
	no++;
	while (head != NULL)
	{
		ft_printf("%s ", head->cross_node);
		head = head->next;
	}
	ft_printf("\n");
}

void				print_path_crossover(int *cross_paths)
{
	int i;

	i = 0;
	ft_printf("that cross with paths ");
	while (cross_paths[i] != -1)
	{
		ft_printf("%d ", cross_paths[i]);
		i++;
	}
	ft_printf("\n");
}

void				print_combinations(t_combo *combination,\

							t_room **paths_array)
{
	t_room				*path;
	int					u;

	u = 0;
	while (u < combination->combo_size)
	{
		ft_printf("PATH: %i\n", combination->paths[u]);
		path = paths_array[combination->paths[u]];
		while (path)
		{
			ft_printf("%s -> ", path->room_name);
			path = path->next;
		}
		ft_printf("\n");
		u++;
	}
	ft_printf("STEPS: %i\n", combination->steps);
	ft_printf("\n\n");
}

void				print_path_lengths(t_room **paths_array,\
							t_combo *combination, int r)
{
	int i;

	i = 0;
	while (i < r)
	{
		ft_printf("%i ", paths_array[combination->paths[i]]->len);
		i++;
	}
	ft_printf("\n");
}
