#ifndef DAY5_H
#define DAY5_H

typedef struct Map_node Map_node;
typedef struct Map Map; 

typedef struct Map_node{
    int src;
    int dest; 
    int range;
    Map_node *next;
}Map_node;

typedef struct Map{
    Map_node *head;
    Map_node *tail;
    int size;
    char* name;
}Map;



Map* create_map();
void add_node(Map *map, int start, int end, int range);
Map_node* get_node(Map *map, int seed);
void print_map(Map *map);
void free_map(Map *map);


#endif