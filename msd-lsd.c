#include <stdio.h>


int theIndex;
int position;

int msd(int n)
{
    int x = n;
    theIndex = 0;
    position = 0;
    while (x > 0) {
        if(x & 1) position = theIndex;
        x >>= 1;
        theIndex++;
    }
 
    return position;
}
 
int lsd(int n)
{
    int x = n;
    theIndex = 0;
    while (x > 0) {
        if(x & 1)return theIndex;
        x >>= 1;
        theIndex++;
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    printf("%d\n", (msd(n)-lsd(n)));
 
    return 0;
}