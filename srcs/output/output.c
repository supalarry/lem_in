/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 09:20:49 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/14 09:20:50 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Create two dimensional array where each index will store
** @desc a linked list. nth linked list contains nth move of all paths.
** @param int steps - size of the array aka # of steps to get all ants accross
** @return t_steps ** as address of two dimensional array with all
** @return addresses initialised to NULL
*/

t_steps			**create_steps_array(int steps)
{
	int		i;
	t_steps	**steps_array;

	i = 0;
	steps_array = (t_steps **)malloc(sizeof(t_steps *) * steps);
	while (i < steps)
	{
		steps_array[i] = NULL;
		i++;
	}
	return (steps_array);
}

/*
** @desc Originate linked list of nth move by creating a link storing
** @desc nth move from some path.
** @param char *steps_line - nth steps taken within some path
** @return t_steps * as link containing nth steps take within some path
*/

t_steps			*originate_steps(char *steps_line)
{
	t_steps *new_steps;

	new_steps = (t_steps *)malloc(sizeof(t_steps));
	new_steps->steps_line = steps_line;
	new_steps->next = NULL;
	return (new_steps);
}

/*
** @desc Append nth steps taken from some path to nth steps within steps array
** @param t_steps *level - start of nth linked list
** @param char *steps_line - nth steps taken within some path
** @return void
*/

void			append_steps(t_steps *level, char *steps_line)
{
	while (level->next)
		level = level->next;
	level->next = originate_steps(steps_line);
}

/*
** @desc is() aka insert_steps()
** @desc Insert nth step from some path into nth position of steps array.
** @desc Thus very first steps from all paths taken will form a linked list
** @desc at the very first index of the steps array.
** @param t_steps **level - address of nth linked list
** @param char *steps_line - nth steps taken within some path
** @return void
*/

void			is(t_steps **level, char *steps_line)
{
	if (*level == NULL)
		*level = originate_steps(steps_line);
	else
		append_steps(*level, steps_line);
}

/*
** @desc Initialise steps_array where nth position stores nth steps
** @desc of all paths
** @param t_room **pa - paths array storing all paths
** @param t_combo *comb - combination structure storing combination indexes
** @param int steps - number of steps aka size of steps array
*/

void			print_hub(t_room **pa, t_combo *comb, int steps)
{
	int		a;
	int		b;
	int		i;
	int		j;
	t_steps	**steps_array;

	print_hub_initialize(&i, &steps_array, steps, &a);
	b = pa[comb->paths[i]]->ants;
	while (i < comb->combo_size)
	{
		j = 0;
		while (j < steps)
		{
			save_pathlen(pa[comb->paths[i]]->len);
			if (j == 0)
				is(&steps_array[j], output_line(pa[comb->paths[i]], a, b, 1));
			else
				is(&steps_array[j], output_line(pa[comb->paths[i]], a, b, 0));
			j++;
		}
		a = b + 1;
		i++;
		b = (i < comb->combo_size ? pa[comb->paths[i]]->ants + a - 1 : b);
	}
	finally_print(steps_array, steps);
}
