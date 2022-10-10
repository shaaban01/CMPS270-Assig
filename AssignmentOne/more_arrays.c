#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **concat (char *array [][3], int size) 
{
    char **answer = malloc (size * sizeof (char *));   
    for (int i = 0; i < size; ++i) 
    {
        answer [i] = malloc (100 * sizeof (char)); 
        int pos = 0;
        for (int j = 0; j < 3; ++j) 
        {
            strcpy (answer [i] + pos, array [i][j]);      
            pos = strlen (answer [i]);
            strcpy (answer [i] + pos, " ");               
            pos++;
        }
        answer [i][pos - 1] = '\0'; 
    }
    return answer;
}

int main()
{
    char *arr [][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    char **ans = concat (arr, 2);
    printf ("{%s},{%s}", ans [0], ans [1]);

    return 0;
}
