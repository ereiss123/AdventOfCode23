/**
 * I decided that I will be brave and try to solve this problem in C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day4.h"

#define PART2
// #define DEBUG

char* read_file(char* filename) {
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

char* find_colon(char* start) {
    char* iter = start;
    while((*iter) != ':' && (*iter) != '\0') {
        iter++;
    }
    if ((*iter) == '\0') {
        // printf("No colon found\n");
        iter = NULL;
    }
    return iter;
}

char* find_line(char* start) {
    char* iter = start;
    while(*iter != '|' && *iter != '\0') {
        iter++;
    }
    if (*iter == '\0') {
        iter = NULL;
    }
    return iter;
}

char* find_newline(char* start) {
    char* iter = start;
    while(*iter != '\n' && *iter != '\0') {
        iter++;
    }
    if (*iter == '\0') {
        // printf("No newline found\n");
        iter = NULL;
    }
    return iter;
}

int main(char** args, int argc) {
#ifdef DEBUG
    char* output = read_file("test.txt");
#else
    char* output = read_file("input.txt");
#endif
#ifdef PART1
    char* iter = output;
    int total = 0;
    while((*iter) != '\0'){
        char* winning_start = find_colon(iter)+2;
        char* winning_end = find_line(winning_start);
        int winning_length = winning_end - winning_start;

        char* winning = malloc(winning_length + 1);
        strncpy(winning, winning_start, winning_length);
        winning[winning_length] = '\0';

        // printf("%s\n", winning);

        char* mynums_start = winning_end + 2;
        char* mynums_end = find_newline(mynums_start);
        if (mynums_end == NULL) {
            // We are at the end of the file
            mynums_end = iter + strlen(iter);
        }
        int mynums_length = mynums_end - mynums_start;
        char* mynums = malloc(mynums_length + 1);
        strncpy(mynums, mynums_start, mynums_length);
        mynums[mynums_length] = '\0';

        // Convert to int array
        int* mynums_int = malloc(mynums_length * sizeof(int));
        int idx = 0;
        for(int i = 0; i < mynums_length; i++) {
            if (mynums[i] >= '0' && mynums[i] <= '9') {
               int num = atoi(&mynums[i]);
               if(num/10 > 0 ){
                    i++;
               }
                mynums_int[idx++] = num;
                
            } 
        }
        // realloc to remove unused space
        int mynums_length_int = idx;
        mynums_int = realloc(mynums_int, mynums_length_int * sizeof(int));

        idx = 0;
        int* winning_int = malloc(winning_length * sizeof(int));
        for(int i = 0; i < winning_length; i++) {
            if (winning[i] >= '0' && winning[i] <= '9') {
               int num = atoi(&winning[i]);
               if(num/10 > 0 ){
                    i++;
               }
                winning_int[idx++] = num;
            } 
        }
        // realloc to remove unused space
        int winning_length_int = idx;
        winning_int = realloc(winning_int, winning_length_int * sizeof(int));

        int round_total = 0;
        for(int i = 0; i < mynums_length_int; i++) {
            for(int j = 0; j < winning_length_int; j++) {
                if (mynums_int[i] == winning_int[j]) {
                    // printf("%c == %c\n", mynums[i], winning[j]);
                    round_total = round_total==0?1:round_total*2;
                }
            }
        }
        total += round_total;

        // printf("%s\n", mynums);
        iter = mynums_end;
        free(mynums_int);
        free(winning_int);
        free(winning);
        free(mynums);

    }
    printf("\n%d\n", total);
    free(output);
#endif
#ifdef PART2
    char* iter = output;
    int total = 0;
    int card = 0;
    int* copies = malloc(sizeof(int) * 1000);
    int* scores = malloc(sizeof(int) * 1000);
    int round = 0;
    for(int i = 0; i < 1000; i++) {
        copies[i] = 1;
        scores[i] = 0;
    }
    while((*iter) != '\0'){
        round++;
        char* winning_start = find_colon(iter)+2;
        char* winning_end = find_line(winning_start);
        int winning_length = winning_end - winning_start;

        char* winning = malloc(winning_length + 1);
        strncpy(winning, winning_start, winning_length);
        winning[winning_length] = '\0';

        // printf("%s\n", winning);

        char* mynums_start = winning_end + 2;
        char* mynums_end = find_newline(mynums_start);
        if (mynums_end == NULL) {
            // We are at the end of the file
            mynums_end = iter + strlen(iter);
        }
        int mynums_length = mynums_end - mynums_start;
        char* mynums = malloc(mynums_length + 1);
        strncpy(mynums, mynums_start, mynums_length);
        mynums[mynums_length] = '\0';

        // Convert to int array
        int* mynums_int = malloc(mynums_length * sizeof(int));
        int idx = 0;
        for(int i = 0; i < mynums_length; i++) {
            if (mynums[i] >= '0' && mynums[i] <= '9') {
               int num = atoi(&mynums[i]);
               if(num/10 > 0 ){
                    i++;
               }
                mynums_int[idx++] = num;
                
            } 
        }
        // realloc to remove unused space
        int mynums_length_int = idx;
        mynums_int = realloc(mynums_int, mynums_length_int * sizeof(int));

        idx = 0;
        int* winning_int = malloc(winning_length * sizeof(int));
        for(int i = 0; i < winning_length; i++) {
            if (winning[i] >= '0' && winning[i] <= '9') {
               int num = atoi(&winning[i]);
               if(num/10 > 0 ){
                    i++;
               }
                winning_int[idx++] = num;
            } 
        }
        // realloc to remove unused space
        int winning_length_int = idx;
        winning_int = realloc(winning_int, winning_length_int * sizeof(int));

        int matches = 0;
        for(int i = 0; i < mynums_length_int; i++) {
            for(int j = 0; j < winning_length_int; j++) {
                if (mynums_int[i] == winning_int[j]) {
                    // printf("%c == %c\n", mynums[i], winning[j]);
                    matches++;
                }
            }
        }

        for(int i = 0; i<copies[card]; i++){
            for(int j = 1; j < (matches)+1; j++){
                copies[card+j]++;
            }
        }

        card++;
        iter = mynums_end;
        free(mynums_int);
        free(winning_int);
        free(winning);
        free(mynums);
    }

    for(int i = 0; i < card; i++) {
        // printf("scores[%d] %d \n",i+1, scores[i]);
        // printf("copies[%d] %d\n",i+1, copies[i]);
        total += copies[i];
    }

    printf("\n%d\n", total);
    free(output);
    free(copies);
    free(scores);
#endif
    return 0;
}