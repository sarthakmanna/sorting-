
/* 
 * File:   BubbleSort.c
 * Author: sarthakmanna
 *
 * Created on 13 November, 2017, 11:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Bubble Sort
 */

int ar[MAX],n;

void printAr();
void sort();

int main(int argc, char** argv)
{
    int i;
    printf("Input length of the Input Array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Input Element %d: ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nThe Array before Sorting: ");
    printAr();
    sort();
    printf("The Array after Sorting: ");
    printAr();
    return EXIT_SUCCESS;
}
void sort()         // Bubble Sort
                    // Best Case Complexity: O(N)
                    // Worst Case Complexity: O(N^2)
{
    int needSorting=1,i,temp;
    while(needSorting)
        for(i=0,needSorting=0;i<n-1;i++)
            if(ar[i]>ar[i+1])
            {
                needSorting=1;
                temp=ar[i];ar[i]=ar[i+1];ar[i+1]=temp;
            }
}
void printAr()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d%s",ar[i],i==n-1?"\n":", ");
}