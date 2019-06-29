/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin_header.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 13:17:55 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 13:18:04 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_HEADER_H
# define LEMIN_HEADER_H
# include "../libft/includes/libft.h"

typedef struct				s_pathfinder
{

	char					*room_name;
	char					*previous;
	struct s_pathfinder		*previous_ptr;
	struct s_pathfinder		*next;
}							t_pathfinder;

typedef struct				s_cross_node
{
	char					*cross_node;
	struct s_cross_node		*next;
}							t_cross_node;

typedef struct				s_room
{
	char					*room_name;
	int						len;
	t_cross_node			*cross_nodes;
	int						*cross_paths;
	struct s_room			*next;
	int						ants;
}							t_room;

typedef struct				s_hash
{
	char					*hash_name;
	int						link_index;
	struct s_hash			*next;
	int						visited;
	char					*previous;
}							t_hash;

typedef struct				s_link
{
	char					*neighbor;
	struct s_link			*next;
}							t_link;

typedef struct				s_combo
{
	int						combo_size;
	int						*paths;
	int						steps;
}							t_combo;

typedef struct				s_steps
{
	char					*steps_line;
	struct s_steps			*next;
}							t_steps;

int							count_ants(void);
void						free_two_d(char **two_d);
t_hash						**create_hashtable(t_room *vertices,
							int vertices_count);
char						*save_link(char *line, char **items);
t_room						*rooms_list(void);
void						print_rooms(t_room *head);
int							count_rooms(t_room *head);
char						*extract_room_1(char *line);
char						*extract_room_2(char *line);
void						print_hashtable(t_room *vertices,
							t_hash **hashtable, int va);
void						print_hashrow(t_hash *hashrow, int hash_value);
int							generate_hash_value(char *name, int items);
void						link_print(t_link *head);
t_link						**create_links(int rooms_count,
							t_hash **hashtable);
int							hash_link(int room_hash, char *room_name,
							t_hash **hashtable);
char						*save_start(char *room);
char						*save_end(char *room);
void						hashtable_null(t_hash **hashtable,
							int rooms_count);
void						links_null(t_link **links, int rooms_count);
int							save_max(int check);
void						breadth_first_search(t_hash **hashtable,
							t_link **link);
int							max_paths(int rooms_count, t_hash **hashtable,
							t_link **links);
t_room						*room_origin(char *name);
void						room_insert(t_room **head, char *name);
int							append_children(t_pathfinder *i, char *r,
							t_hash **h, t_link **l);
int							create_path(t_pathfinder *item, t_hash **hashtable,
							t_link **links);
int							crossover_node(char *room, t_hash **hashtable,
							t_link **links);
void						add_crossover(char *room, t_cross_node **head);
int							count_crossovers(t_cross_node *head);
void						insert_crossover_path(t_room *one, t_room *two,
							int o, int t);
int							shared_crossover(t_cross_node *one,
							t_cross_node *two);
void						path_crossovers(t_room	**paths_array, int last_i);
int							get_combinations(t_room **paths_array, int i);
int							best_combination(int *i, t_room **p, int *vars,
							t_combo *c);
unsigned int				save_steps(unsigned int new_steps);
int							get_steps(t_room **paths_array, int *combo_array,
							int r);
void						set_int_array(int *int_array, int r);
int							check_cross_paths(int i, int *int_array,
							int *cross_paths);
void						edit_combo_array(t_combo *combinations, int *i,
							int r);
t_combo						*save_combo(t_combo *combo);
void						print_path_lengths(t_room **paths_array,
							t_combo *combination, int r);
void						print_path_old(t_room *head);
void						print_crossover(t_cross_node *head);
void						print_path_crossover(int *cross_paths);
void						print_combinations(t_combo *combination,
							t_room **paths_array);
void						print_crossover(t_cross_node *head);
t_link						*n_list(char *room_name, t_hash **hashtable,
							t_link **links);
int							technique(t_link **head, int rooms_count,
							t_hash **htable);
void						breadth_first_search_big(t_hash **hashtable,
							t_link **link);
int							append_children_big(t_pathfinder *item,
							char *room_name, t_hash **hashtable,
							t_link **links);
void						quit(void);
int							*make_vars(int r, int found_paths);
t_room						**save_paths_array(t_room **paths_array);
void						print_hub(t_room **paths_array,
							t_combo *combination, int steps);
char						*output_line(t_room *path, int lower_bound,
							int upper_bound, int set);
void						finally_print(t_steps **steps_array, int steps);
void						divide_ants(t_room **paths_array);
t_pathfinder				*append_item(t_pathfinder *item, t_link *link);
void						room_increment(int *room, int len);
char						*steps_line_create(void);
int							save_pathlen(int len);
t_steps						**create_steps_array(int steps);
void						print_hub_initialize(int *i,
							t_steps ***steps_array, int steps, int *a);
void						print_hub_ij(int *i, int *j);
void						find_room(char *room, t_hash **htable,
							int rooms_count);
char						*copy_input(char *line);
void						path_error(void);
void						loop_through_ints(int *i, int r, int *ints,
							t_combo *combo);
void						make_combination_paths(t_combo *combo, int r);

#endif
