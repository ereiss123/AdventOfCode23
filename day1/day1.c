/*
* I decided to use C for the first day.
* I'm not sure if I'll use it for the rest of the days.
*/
#define BUFFER_SIZE 2048
#include <stdio.h>

int main(void) {
    FILE *infile;
    infile = fopen("input.txt", "r");
    char buffer[BUFFER_SIZE];

    while(!feof(infile)) {
        fgets(buffer, BUFFER_SIZE, infile);
        printf("%s", buffer);
        
    }
    return 0;
}