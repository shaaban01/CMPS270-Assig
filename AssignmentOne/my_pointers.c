#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** merge(char** arrayOne, int sizeOne, char** arrayTwo, int sizeTwo)
{
    int i=0, j=0, k=0;
    //creating the returned array 
    char **ans = malloc(100 * sizeof(char*));
    
    for (int i =0 ; i < 10; ++i)
        ans[i] = malloc(20 * sizeof(char));
        
    //compare and add to the answer array(similar to mergeSort)
    while(i<sizeOne && j<sizeTwo)
    {
        if(strcmp(arrayOne[i], arrayTwo[j]) <= 0) strcpy(ans[k++], arrayOne[i++]);
        else strcpy(ans[k++], arrayTwo[j++]);
    }
    
    //appending the rest of both arrays
    while(i<sizeOne) strcpy(ans[k++], arrayOne[i++]);
    while(j<sizeTwo) strcpy(ans[k++], arrayTwo[j++]);
    
    return ans;
}

int main()
{
    char *a[3] = {"ab", "ac"}, *b[4] = {"za", "zb", "zzzzc"};
    char **ans = merge(a,2, b,3);
    for(int i=0; i<5; i++) printf("%s \n", ans[i]);
    return 0;
}