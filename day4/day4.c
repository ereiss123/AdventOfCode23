/**
 * I decided that I will be brave and try to solve this problem in C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day4.h"

#define DEBUG

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
        printf("No colon found\n");
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
        printf("No bar found\n");
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
        printf("No newline found\n");
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
    char* iter = output;
    while((*iter) != '\0'){
        char* winning_start = find_colon(iter)+2;
        char* winning_end = find_line(winning_start);
        int winning_length = winning_end - winning_start;

        char* winning = malloc(winning_length + 1);
        strncpy(winning, winning_start, winning_length);
        winning[winning_length] = '\0';

        printf("%s\n", winning);

        char* losing_start = winning_end + 2;
        char* losing_end = find_newline(losing_start);
        if (losing_end == NULL) {
            // We are at the end of the file
            losing_end = iter + strlen(iter);
        }
        int losing_length = losing_end - losing_start;
        char* losing = malloc(losing_length + 1);
        strncpy(losing, losing_start, losing_length);
        losing[losing_length] = '\0';
    

        printf("%s\n", losing);
        iter = losing_end;

        free(winning);
        free(losing);

    }

    printf("\n");
    free(output);
}