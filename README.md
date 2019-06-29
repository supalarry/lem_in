# Lem_in
Lem_in is a project involving shortest path problem. It is about moving N amount of ants from a specific start room to a specific end room. Antfarm consists of many rooms and each room can be connected to unlimited amount of other rooms. Notably, while ants are being moved only one ant at a time can be within a room.

## Getting Started
To create a executable that finds smallest amount of steps to get N ants from A to B, run **make** in root folder to get executable called **lem_in**. The executable receives input file to start solving it.

```
lem_in < map
```

### Prerequisites
The **map** file's structure is as follows
```
number of ants
rooms room_coordinate_x room_coordinate_y
connections
```
```
10
A 10 20
B 30 40
C 50 60
A-B
B-C
```
