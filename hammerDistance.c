#include<stdio.h>


int hammingDistance(int n1,int n2);

int n1 = 0;
int n2 = 0;
int output =0;


int main()
{
    
    
    while(1)
    {
        scanf("%d", &n1);
        if (n1 < 0) return(0);
        scanf("%d", &n2);
        output= hammingDistance(n1, n2);
        printf("%d \n",output);
    }
}
int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int rslt = 0;
 
    while (x > 0) 
    {
        rslt += x & 1;
        x >>= 1;
    }
 
    return rslt;
}