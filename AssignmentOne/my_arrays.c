#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10


int findMax(int array[], int size);


//printing an array
void printArray(int array[],int size)
{
    printf("Index Value\n");
    for(int i=0; i < size;i++) printf("%5d %5d \n",i,array[i]);
}


//helper function
//uniqNum is the number of uniqe numbers in the array
int* fillFreq(int array[],int size, int uniqNum)
{   
    int *freq = malloc(100*sizeof(int));
    
    //fill the array with zeros
    for(int i = 0;i<uniqNum+1;i++) freq[i]=0;
    
    for(int i = 0;i<size;i++) freq[(array[i])]++;
    
    return freq;
}


void arrayHistogram(int array[],int size,int uniqNum)
{
    int *freq = fillFreq(array,size,uniqNum);
    
    printf("value Frequence Histogram\n");
    for(int i=0; i < uniqNum;i++)
    {
        printf("%5d %9d",i+1,freq[i+1]);
        for(int j=0; j < 10 - freq[i+1];j++) printf(" ");
        for(int j=0; j < freq[i+1];j++)printf("*");
        printf("\n");
    }
}

void swapValues(int array[],int index1, int index2)
{
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

void bubbleSort(int array[],int size)
{
    for(int i = 1; i < size;i++)
    {
        for(int j = 1; j < size;j++)
        {
            if( array[j-1] > array[j]){swapValues(array,j-1,j);}
        }
        
    }
    
}

int median(int array[],int size)
{
    //copying the array so that we don't sort the actual array
    int arrayCopy[size];
    
    for(int i=0;i < size;i++) arrayCopy[i]=array[i];
    
    bubbleSort(arrayCopy, size);
    
    if(size%2 == 0){return arrayCopy[(size/2)-1];}
    else{return arrayCopy[((size+1)/2)-1];}
}



int mode(int array[],int size,int uniqNum)
{
    int *freq = fillFreq(array,size,uniqNum);
    
    return findMax(freq,size);
}

int findMax(int array[], int size)
{
    int max = array[0];
    for(int i = 1;i<size;i++)
    {
        if(array[i]>max){max = array[i];}
    }
    return max;
    
}

int isSorted(int array[],int size){
    for(int i=1;i < size;i++){
        if(array[i-1] > array[i]){return 0;}
    }
    return 1;
}

int main(){
    
    int myArray[] = {1,2,2,3,3,3,1,1,1,1};
    printArray(myArray,SIZE);
    arrayHistogram(myArray,SIZE,3);
    int testArray[] = {9,8,5,6,10};
    printArray(testArray,5);
    bubbleSort(testArray,5);
    printArray(testArray,5);
    printf("The median of testArray is: %d \n",median(testArray,5));
    printf("The median myArray is: %d \n",median(myArray,10));
    printf("The mode is: %d \n",mode(myArray,SIZE,3));
    if(isSorted(myArray,SIZE)) printf("myArray is sorted \n");
    else printf("myArray is not sorted \n");
    if(isSorted(testArray,5))printf("testArray is sorted \n");
    else printf("testArray is not sorted \n");
    return 0;
}