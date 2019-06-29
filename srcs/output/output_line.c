/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_line.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 09:17:58 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/14 09:18:00 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc First, save address of very first room. Then it is used as a starting
** @desc point to iterate to specific room.
** @param t_room *path - path containing link of rooms of a path
** @param int room_copy - indicates which room's name we need to extract later
** @return NULL if we just save the address of first room, otherwise
** @return address of a room within path
*/

static t_room	*target_room(t_room *path, int room_copy)
{
	int				iterate;
	static t_room	*path_copy;

	iterate = 0;
	if (room_copy == -1)
	{
		path_copy = path;
		return (NULL);
	}
	path = path_copy;
	while (iterate < room_copy)
	{
		path = path->next;
		iterate++;
	}
	return (path);
}

/*
** @desc Concatenate another move to steps_line
** @desc Each move consists of "L" ant number "-" room name where ant goes
** @param char *steps_line - line to which concatenate contents. This line
** @param is later inserted into linked list array nth steps linked list.
** @param int ant_copy - number of the ant to be moved
** @param char *room_name - name of the room where the ant travels to
** @return void
*/

static void		create_line(char *steps_line, int ant_copy, char *room_name)
{
	char	*itoa;

	itoa = ft_itoa(ant_copy);
	ft_strcat(steps_line, "L");
	ft_strcat(steps_line, itoa);
	ft_strcat(steps_line, "-");
	ft_strcat(steps_line, room_name);
	ft_strcat(steps_line, " ");
	free(itoa);
}

/*
** @desc If set is 1, then we are starting to work with a new path
** @desc and static variables need to be reset
** @param int set - indicates if local variables of output_line must be reset
** @param int *room - address of integer storing starting room
** @param int *ant - address of integer storing starting ant
** @param int start_ant - integer indicating starting ant
** @return void
*/

static void		reset(int set, int *room, int *ant, int start_ant)
{
	if (set)
	{
		*room = 1;
		*ant = start_ant;
	}
}

/*
** @desc Creates a line consisting of one or more moves. Each path's
** @desc nth steps line is inserted at nth place in array of linked lists,
** @desc where each linked list stores nth step lines from various paths.
** @param t_room *path - path which ants have to traverse
** @param int start_ant - number of starting ant for the path
** @param int end_ant - number of ending ant for the path
** @param int set - 1 to reset static values. 0 to keep current values
** @return char * as line consisting of one or multiple moves,
** @return eg 'L1-3' or 'L1-4 L2-3'
*/

char			*output_line(t_room *path, int start_ant, int end_ant, int set)
{
	static int	ant;
	int			ant_copy;
	static int	room;
	int			room_copy;
	char		*steps_line;

	steps_line = steps_line_create();
	reset(set, &room, &ant, start_ant);
	room_copy = room;
	ant_copy = ant;
	target_room(path, -1);
	while (room_copy >= 1)
	{
		if (ant_copy <= end_ant)
		{
			path = target_room(path, room_copy);
			create_line(steps_line, ant_copy, path->room_name);
			if (ft_strequ(save_end(NULL), path->room_name))
				ant++;
			ant_copy++;
		}
		room_copy--;
	}
	room_increment(&room, save_pathlen(-1));
	return (steps_line);
}
