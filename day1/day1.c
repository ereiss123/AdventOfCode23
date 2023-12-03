/*
* I decided to use C for the first day.
* I'm not sure if I'll use it for the rest of the days.
*/
#define BUFFER_SIZE 2048
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int part1(void){
    FILE *infile;
    infile = fopen("input.txt", "r");
    int num1 = -1, num2 = -1, total = 0, index = 0;
    char buffer[BUFFER_SIZE];
    int nums[BUFFER_SIZE];
    memset(nums, -1, BUFFER_SIZE*sizeof(int));
    memset(buffer, '\0', BUFFER_SIZE*sizeof(char));

    while(!feof(infile))
    {
        fgets(buffer, BUFFER_SIZE, infile);
        for(int i = 0; i < BUFFER_SIZE; i++) 
        {
            if(buffer[i] == '\0')
            {
                break; 
            }
            else if(buffer[i] >= '0' && buffer[i] <='9' )
            {
                nums[index++] = (buffer[i]-'0');
            }    
        }
        if (nums[index-1] == -1)
        {
            int num = nums[0] + (10*nums[0]);
            total += num;
        }
        else if (nums[0] > -1)
        {
            int num = nums[index-1] + (10*nums[0]);
            total += num;
        }
        index = 0;
        memset(nums, -1, BUFFER_SIZE*sizeof(int));
        memset(buffer, '\0', BUFFER_SIZE*sizeof(char));
    }
    fclose(infile);
    return total;
}

int part2(void){
    FILE *infile;
    infile = fopen("input.txt", "r");
    int num1 = -1, num2 = -1, total = 0, index = 0;
    char buffer[BUFFER_SIZE];
    int nums[BUFFER_SIZE];
    memset(nums, -1, BUFFER_SIZE*sizeof(int));
    memset(buffer, '\0', BUFFER_SIZE*sizeof(char));

    while(!feof(infile))
    {
        fgets(buffer, BUFFER_SIZE, infile);
        for(int i = 0; i < BUFFER_SIZE; i++) 
        {
            if(buffer[i] == '\0')
            {
                break; 
            }
            else if(buffer[i] >= '0' && buffer[i] <='9' )
            {
                nums[index++] = (buffer[i]-'0');
            }
            else if (buffer[i] == 'o' || buffer[i] == 't' || buffer[i] == 'f' || buffer[i] == 's' || buffer[i] == 'e' || buffer[i] == 'n')
            {
               switch(buffer[i])
               {
                case 'o': // One
                    if (buffer[i+1] == 'n' && buffer[i+2] == 'e')
                    {
                        nums[index++] = 1;
                        i += 2;
                    }
                    break;
                case 't': // Two, Three
                    if (buffer[i+1] == 'w' && buffer[i+2] == 'o')
                    {
                        nums[index++] = 2;
                        i += 2;
                    }
                    else if (buffer[i+1] == 'h' && buffer[i+2] == 'r' && buffer[i+3] == 'e' && buffer[i+4] == 'e')
                    {
                        nums[index++] = 3;
                        i += 4;
                    }
                    break;
                case 'f': // Four, Five
                    if (buffer[i+1] == 'o' && buffer[i+2] == 'u' && buffer[i+3] == 'r')
                    {
                        nums[index++] = 4;
                        i += 3;
                    }
                    else if (buffer[i+1] == 'i' && buffer[i+2] == 'v' && buffer[i+3] == 'e')
                    {
                        nums[index++] = 5;
                        i += 3;
                    }
                    break;
                case 's': // Six, Seven
                    if (buffer[i+1] == 'i' && buffer[i+2] == 'x')
                    {
                        nums[index++] = 6;
                        i += 2;
                    }
                    else if (buffer[i+1] == 'e' && buffer[i+2] == 'v' && buffer[i+3] == 'e' && buffer[i+4] == 'n')
                    {
                        nums[index++] = 7;
                        i += 4;
                    }
                    break;
                case 'e': // Eight
                    if (buffer[i+1] == 'i' && buffer[i+2] == 'g' && buffer[i+3] == 'h' && buffer[i+4] == 't')
                    {
                        nums[index++] = 8;
                        i += 4;
                    }
                    break;
                case 'n': // Nine
                    if (buffer[i+1] == 'i' && buffer[i+2] == 'n' && buffer[i+3] == 'e')
                    {
                        nums[index++] = 9;
                        i += 3;
                    }
                    break;
               }
            }
                
        }
        if (nums[index-1] == -1)
        {
            int num = nums[0] + (10*nums[0]);
            printf("%d\n", num);
            total += num;
        }
        else if (nums[0] > -1)
        {
            int num = nums[index-1] + (10*nums[0]);
            printf("%d\n", num);
            total += num;
        }
        index = 0;
        memset(nums, -1, BUFFER_SIZE*sizeof(int));
        memset(buffer, '\0', BUFFER_SIZE*sizeof(char));
    }
    fclose(infile);
    return total;
}

int main(void) {
    printf("Part 1 Total: %d\n", part1());
    printf("Part 2 Total: %d\n", part2());

    return 0;
}