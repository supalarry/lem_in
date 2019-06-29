/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   best_combination.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 12:08:26 by fblom         #+#    #+#                 */
/*   Updated: 2019/06/04 12:08:26 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc saves the best combination soo far
** @param the new combination
** @return the best combination
*/

t_combo			*save_combo(t_combo *combo)
{
	static t_combo *best_combo;

	if (combo == NULL)
		return (best_combo);
	best_combo = combo;
	return (best_combo);
}

/*
** @desc saves the lowest number of steps found so far
** @param combo is sent as a paramater so we can later save combo
** @return returns -1 so it's the largest int possible (unsigned)
** @return and skips it the first time of the loop in create_path
*/

unsigned int	save_steps(unsigned int new_steps)
{
	static int	lowest_steps;

	if (new_steps == (unsigned int)-1 && !lowest_steps)
		return (-1);
	if (!lowest_steps || new_steps <= (unsigned int)lowest_steps)
		lowest_steps = new_steps;
	return (lowest_steps);
}

/*
** @desc calculates the number of steps needed to get the ants through the farm
** @param the array of paths, the int array of combinations
** @param the size of the combination
** @return the number of steps it takes to get the ants through
*/

int				get_steps(t_room **paths_array, int *combo_array, int r)
{
	int			steps;
	int			i;
	int			add;
	int			ants;

	steps = 0;
	i = 0;
	add = count_ants() % r;
	ants = count_ants();
	while (i < r)
	{
		if (i == 0)
			steps += paths_array[combo_array[i]]->len + (ants / r + add) - 1;
		else
			steps += paths_array[combo_array[i]]->len + (ants / r) - 1;
		i++;
	}
	add = steps % r;
	steps = steps / r;
	if (add != 0)
		steps += 1;
	return (steps);
}

/*
** @desc check a new combination for crossing paths
** @param the new combination int array, the array of all paths
** @param the size of the combination
** @return (1) if paths cross
** @return (0) if paths don't cross
*/

static int		paths_cross(int *paths, t_room **paths_array, int combo_size)
{
	int			i;
	int			j;
	int			k;
	t_combo		*combo;

	combo = save_combo(NULL);
	i = combo_size - 1;
	while (i >= 0)
	{
		k = i - 1;
		while (k >= 0)
		{
			j = 0;
			while (paths_array[paths[k]]->cross_paths[j] != -1)
			{
				if (paths[i] == paths_array[paths[k]]->cross_paths[j])
					return (1);
				j++;
			}
			k--;
		}
		i--;
	}
	return (0);
}

/*
** @desc check a new combination for crossing paths, and checks if
** @desc steps is lower than previous found lowest steps
** @desc if steps is lower, saves it via save_lowest() function
** @param the new comboination array (i), the array of paths, size of combo
** @param number of found paths so far, the combination struct
** @return (1) if it's the best combination
** @return (2) if the combination has more steps than previous
** @return (0) if paths cross so the next combination can be tried
*/

int				best_combination(int *int_array, t_room **paths_array, \
				int *variables, t_combo *combination)
{
	unsigned int		steps;
	unsigned int		old_steps;
	int					cross;
	int					r;
	int					found_paths;

	r = variables[0];
	found_paths = variables[1];
	free(variables);
	cross = paths_cross(int_array, paths_array, r);
	if (!cross)
	{
		steps = get_steps(paths_array, int_array, r);
		old_steps = save_steps(-1);
		if (steps < old_steps || found_paths == 1)
		{
			save_steps(steps);
			combination->steps = steps;
			return (1);
		}
		return (2);
	}
	return (0);
}
