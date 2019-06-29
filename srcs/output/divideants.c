/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divideants.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 11:08:29 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/15 11:08:32 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

void		divide_ants(t_room **paths_array)
{
	t_combo	*combination;
	int		antstotal;
	int		steps;
	int		i;
	int		*paths;

	combination = save_combo(NULL);
	antstotal = count_ants();
	i = combination->combo_size - 1;
	steps = save_steps(-1);
	paths = combination->paths;
	while (i >= 0)
	{
		if (i == 0)
			paths_array[paths[i]]->ants = antstotal;
		else
		{
			paths_array[paths[i]]->ants = steps -
			paths_array[paths[i]]->len + 1;
			antstotal -= paths_array[paths[i]]->ants;
		}
		i--;
	}
}
