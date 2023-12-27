#include "day5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG

Map* create_map(){
    Map *map = (Map*)malloc(sizeof(Map));
    map->head = (Map_node*)malloc(sizeof(Map_node));
    map->head->next = NULL;
    map->head->src = -1;
    map->head->dest = -1;
    map->head->range = -1;
    map->size = 0;
    map->tail = map->head;
    return map;
}
void add_node(Map *map, int src, int dest, int range){
    // printf("In add_node with map: %s with size %d\n", map->name, map->size);
    if (map->size == 0){
        // printf("Adding first node\n");
        map->head->src = src;
        map->head->dest = dest;
        map->head->range = range;
        map->size++;
    }else{
        // printf("Adding node\n");
        map->tail->next = (Map_node*)malloc(sizeof(Map_node));
        Map_node *node = map->tail->next;
        node->src = src;
        node->dest = dest;
        node->range = range;
        node->next = NULL;
        map->tail = node;
        map->size++;
    }
}

void print_map(Map *map){
    if(map == NULL){
        printf("Map is NULL\n");
        return;
    }
    printf("%s\n", map->name);
    printf("size: %d\n", map->size);
    Map_node *node = map->head;
    while (node != NULL){
        printf("%d %d %d\n", node->src, node->dest, node->range);
        node = node->next;
    }
}

Map_node* get_node(Map *map, int seed){
    Map_node *iter = map->head;
    while(iter != NULL){
        if (seed >= iter->src && seed <= iter->src + iter->range){
            break;
        }
        iter = iter->next;
    }
    if(iter == NULL){
        iter = (Map_node*)malloc(sizeof(Map_node));
        iter->src = seed;
        iter->dest = seed;
        iter->range = 0;
        iter->next = NULL;
    }
    return iter;
}

void free_map(Map *map){
    if(map == NULL){
        return;
    }
    Map_node *iter = map->head;
    while(iter != NULL){
        Map_node *temp = iter;
        iter = iter->next;
        free(temp);
    }
    free(map);
}

const char* read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END); // Go to the end of the file
    long length = ftell(file);  // Get the length of the file
    fseek(file, 0, SEEK_SET); // Go to the start of the file
    char* buffer = malloc(length + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    fread(buffer, 1, length, file); // Read the file into the buffer
    fclose(file);
    buffer[length] = '\0'; // Null terminate the string
    return buffer;
}

bool is_number(char c){
    return c >= '0' && c <= '9';
}

int part1(char* filename){
    const char *input = read_file(filename);
    char *iter = (char*)input;
    int *seeds = (int*)malloc(sizeof(int)*100);
    for (int i = 0; i < 100; i++){
        seeds[i] = -1;
    }
    int lowest_location = __INT32_MAX__;
    Map* seed_to_soil = create_map();
    Map* soil_to_fert = create_map();
    Map* fert_to_water = create_map();
    Map* water_to_light = create_map();
    Map* light_to_temp = create_map();
    Map* temp_to_hum = create_map();
    Map* hum_to_location = create_map();
    char* file_end = strchr(iter, '\0');
    const char* str0 = "seeds:\0";
    const char *str1 = "seed-to-soil map:\0";
    const char *str2 = "soil-to-fertilizer map:\0";
    const char *str3 = "fertilizer-to-water map:\0";
    const char *str4 = "water-to-light map:\0";
    const char *str5 = "light-to-temperature map:\0";
    const char *str6 = "temperature-to-humidity map:\0";
    const char *str7 = "humidity-to-location map:\0";
    Map *cur_map = NULL;
    int loop = 0;
    // Parse input
    while(iter != NULL){

        if(loop > 0){
            iter++;
        }
        loop++;
        // get line
        char *line = (char*)malloc(1024);
        // printf("file_end: %p\titer: %p\n", file_end,iter);
        char *line_end = strchr(iter, '\n');
        int line_len = 0;
        if(line_end == NULL){
            // EOF
            line_len = strlen(iter);
        }else{
            line_len = line_end - iter;
        }
        strncpy(line, iter, line_len);
        line[line_len] = '\0';

        // printf("Working with line\n%s\n", line);

        // Check if char or num
        if(!is_number(line[0]) && line[0] != '\0'){
            // printf("len line: %ld\t%s\n", strlen(line),line);
            // Parse line
            if( memcmp(line,str0,strlen(str0)) == 0){
                cur_map = NULL;
                // Parse seeds
                // char *seed = strchr(line, ' ');
                char* seed = strtok(line, " ");
                int i = 0;
                while(seed != NULL){
                    if(atoi(seed) != 0){
                        seeds[i] = atoi(seed);
                        // printf("%d ", seeds[i]);
                        i++;
                    }
                    seed = strtok(NULL, " ");
                    // printf("seed: %s\n", seed);
                }
                // printf("\n");
                seeds = realloc(seeds, sizeof(int)*i);

            }else if(memcmp(line,str1,strlen(str1)) == 0){
                // free(cur_map);
                cur_map = seed_to_soil;
                cur_map->name = (char*) str1;
                // print_map(cur_map);
                // printf("cur_map: %s\n", cur_map->name);

            }else if(memcmp(line,str2,strlen(str2)) == 0){
                // free(cur_map);
                cur_map = soil_to_fert;
                cur_map->name = (char*) str2;

            }else if(memcmp(line,str3,strlen(str3)) == 0){
                // free(cur_map);
                cur_map = fert_to_water;
                cur_map->name = (char*) str3;

            }else if(memcmp(line,str4,strlen(str4)) == 0){
                // free(cur_map);
                cur_map = water_to_light;
                cur_map->name = (char*) str4;  

            }else if(memcmp(line,str5,strlen(str5)) == 0){
                // free(cur_map);
                cur_map = light_to_temp;
                cur_map->name = (char*) str5;

            }else if(memcmp(line,str6,strlen(str6)) == 0){
                // free(cur_map);
                cur_map = temp_to_hum;
                cur_map->name = (char*) str6;

            }else if(memcmp(line,str7,strlen(str7)) == 0){
                // free(cur_map);
                cur_map = hum_to_location;
                cur_map->name = (char*) str7;

            }else{
                printf("Error parsing input\n");
                exit(EXIT_FAILURE);
            }
        }else if(line[0] != '\0'){
            // printf("Cur map == NULL: %d\n", cur_map == NULL);
            if(cur_map->name != NULL){
                int src = -1;
                int dest = -1;
                int range = -1;
                sscanf(line, "%d %d %d", &src, &dest, &range);
                // printf("src: %d\tdest: %d\trange: %d\n", src, dest, range);
                // print_map(cur_map);
                add_node(cur_map, src, dest, range);
             }
        }
        iter = line_end;
        free(line);
    }

    // Find lowest location
    int i = 0;
    while(seeds[i] != -1){
        int seed = seeds[i];
        // printf("seed: %d\n", seed);
        Map_node *soil_node = get_node(seed_to_soil, seed);
        Map_node *fert_node = get_node(soil_to_fert, soil_node->dest);
        Map_node *water_node = get_node(fert_to_water, fert_node->dest);
        Map_node *light_node = get_node(water_to_light, water_node->dest);
        Map_node *temp_node = get_node(light_to_temp, light_node->dest);
        Map_node *hum_node = get_node(temp_to_hum, temp_node->dest);
        Map_node *location_node = get_node(hum_to_location, hum_node->dest);
        if(location_node->dest < lowest_location){
            lowest_location = location_node->dest;
        }
        i++;
        free(soil_node);
        free(fert_node);
        free(water_node);
        free(light_node);
        free(temp_node);
        free(hum_node);
        free(location_node);
    }



    free_map(seed_to_soil);
    free_map(soil_to_fert);
    free_map(fert_to_water);
    free_map(water_to_light);
    free_map(light_to_temp);
    free_map(temp_to_hum);
    free_map(hum_to_location);
    free(seeds);
    free((void*)input);
    return lowest_location;
}

int part2(char* filename){
    return -1;
}

int main(void){
#ifdef DEBUG
    char* filename = "test.txt";
#else
    char* filename = "input.txt";
#endif
    printf("Part 1: %d\n",part1(filename));
    printf("Part 2: %d\n",part2(filename));
    return 0;
}