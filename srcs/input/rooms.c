/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 13:18:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 13:18:12 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc If "##start" or "##end" is encountered in the input,
** @desc free current line and save starting room with save_start()
** @desc and save end room with save_end()
** @param char **line - address of variable storing line read from file
** @param char ***items - address of variable storing line as 2d array
** @return void
*/

static int		save_special(char **line, char ***items)
{
	if (ft_strstr(*line, "##start")
	&& ft_strlen(*line) == 7)
	{
		free_two_d(*items);
		free(*line);
		get_next_line(0, line);
		*items = ft_strsplit(*line, ' ');
		if (!ft_strlen((*items)[0]) || (*items)[0][0] == '#')
			quit();
		copy_input(*line);
		save_start(*items[0]);
	}
	else if (ft_strstr(*line, "##end")
	&& ft_strlen(*line) == 5)
	{
		free_two_d(*items);
		free(*line);
		get_next_line(0, line);
		*items = ft_strsplit(*line, ' ');
		if (!ft_strlen((*items)[0]) || (*items)[0][0] == '#')
			quit();
		copy_input(*line);
		save_end(*items[0]);
	}
	return (1);
}

/*
** @desc Create a new structure for a room
** @param char *name - name of the room
** @return t_room * as the address of the new node
*/

t_room			*room_origin(char *name)
{
	t_room	*new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->room_name = ft_strdup(name);
	new_room->cross_nodes = NULL;
	new_room->cross_paths = NULL;
	new_room->next = NULL;
	return (new_room);
}

/*
** @desc Insert a new room to the start of rooms linked list
** @param t_room **head - address of head of linked list
** @param char *name - name of the room
** @return void
*/

void			room_insert(t_room **head, char *name)
{
	t_room	*new_room;

	new_room = room_origin(name);
	new_room->next = *head;
	*head = new_room;
}

/*
** @desc Free read line and array containing it's items
** @param char *line - address of read line
** @param char **items - array holding line's items
** @return void
*/

static void		free_both(char *line, char **items)
{
	free(line);
	free_two_d(items);
}

/*
** @desc Create a linked list where each link holds information
** @desc about a room. This data is read from the input file
** @desc until information about a pipe is encountered. Then
** @desc that line is saved and can later be retrieved. If
** @desc ##start or ##end is encountered, save_special function
** @desc stores next line's rooms either in save_start or save_end
** @desc that can be retrieved by passing NULL to thouse functions.
** @param void
** @return t_room * as head of linked list containing
** @return rooms from the input file
*/

t_room			*rooms_list(void)
{
	char			*line;
	char			**items;
	static t_room	*head;

	while (1)
	{
		if (!get_next_line(0, &line) || ft_strlen(line) == 0)
			return (NULL);
		copy_input(line);
		items = ft_strsplit(line, ' ');
		if (items[1] == NULL && items[0][0] != '#' && items[0][1] != '#')
		{
			if (head == NULL)
				return (NULL);
			break ;
		}
		save_special(&line, &items);
		if (head == NULL && items[0][0] != '#')
			head = room_origin(items[0]);
		else if (items[0][0] != '#')
			room_insert(&head, items[0]);
		free_both(line, items);
	}
	save_link(line, items);
	return (head);
}
