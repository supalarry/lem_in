# Lem_in
Lem_in is a project involving shortest path problem. It is about moving N amount of ants from a specific start room to a specific end room. Antfarm consists of many rooms and each room can be connected to unlimited amount of other rooms. Notably, while ants are being moved only one ant at a time can be within a room. The solution consists of finding paths that result in least amount of steps required to move all ants from start to end. Step is defined as moving all ants that have free next room in their path at the same time. 

## Project folder structure
```
lem_in
├── includes [header file for project]
├── libft [my library with various functions]
└── srcs [sources of the project]
    ├── input [sources for creating hashtable from input]
    ├── output [sources for printing steps that ants take]
    ├── solver [sources for path finding and saving combination of paths]
Makefile [compiles the project]
author [my username]
```

## Getting Started
To create a executable that finds smallest amount of steps to get N ants from A to B, run **make** in root folder to get executable called **lem_in**. The executable receives input file to start solving it.

```
./lem_in < map
```

## Prerequisites
The **map's** file's structure is as follows
```
number of ants
room_1 room_coordinate_x room_coordinate_y
room_N room_coordinate_x room_coordinate_y
connections
```
Notably, there needs to be a starting room indicated by ##start and ending room indicated by ##end.
```
4
3 2 2
##start
start 4 0
##end
end 4 6
4 0 4
1 4 2
2 4 4
5 8 2
6 8 4
start-1
3-4
2-4
1-5
6-5
end-6
1-2
2-end
3-start
```
This results in the following map
```
  [start]
   /  |
 [3] [1]--[5]
 /    |    |
[4]--[2]  [6]
      |   /
     [end]
```
## Finding the solution
After running
```
./lem-in < map
```
the solution is found to be a combination of path start-3-4-2-end and start-1-5-6-end
```
L1-3 L3-1
L1-4 L2-3 L3-5 L4-1
L1-2 L2-4 L3-6 L4-5
L1-end L2-2 L3-end L4-6
L2-end L4-end
```
The answer follows structure Lx-y where x is number of ant and y is name of room ant is heading to.
