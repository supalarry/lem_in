/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combinations_support.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 13:13:27 by fblom         #+#    #+#                 */
/*   Updated: 2019/06/03 13:13:28 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc
** @param
** @return
*/

void			loop_through_ints(int *i, int r, int *ints, t_combo *combo)
{
	while (*i < r - 2)
	{
		ints[*i + 1] = combo->paths[*i + 1];
		(*i)++;
	}
}

/*
** @desc puts ints into an array
** @param all the ints
** @return void
*/

int				*make_vars(int r, int found_paths)
{
	int			*variables;

	variables = malloc(sizeof(int) * 2);
	variables[0] = r;
	variables[1] = found_paths;
	return (variables);
}

/*
** @desc updates the int array in the combination struct
** @param the combination struct, the int array, the size of the combination
** @return void
*/

void			edit_combo_array(t_combo *combination, int *int_array, int r)
{
	int x;

	x = 0;
	while (x < r)
	{
		combination->paths[x] = int_array[x];
		x++;
	}
}

/*
** @desc initialises the int array that holds possible combinations of paths
** @param the int array, the size of the int array
** @return void
*/

void			set_int_array(int *int_array, int r)
{
	int			i;
	t_combo		*combo;

	combo = save_combo(NULL);
	i = 0;
	while (i < r - 1)
	{
		int_array[i] = combo->paths[i];
		i++;
	}
}

/*
** @desc check a new item in the combination array for crossing paths
** @param the index of the item, the array of combinations, the crossing paths
** @return (1) for crossing paths, (0) for no crossing paths
*/

int				check_cross_paths(int i, int *int_array, int *cross_paths)
{
	int x;

	x = 0;
	while (cross_paths[x] != -1)
	{
		if (int_array[i] == cross_paths[x])
			return (1);
		x++;
	}
	return (0);
}
