
/* 
 * File:   SelectionSort.c
 * Author: sarthakmanna
 *
 * Created on 13 November, 2017, 11:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Selection Sort
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
void sort()         // Selection Sort
                    // Best Case Complexity: O(N^2)
                    // Worst Case Complexity: O(N^2)
{
    int i,j,pos,temp;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
            if(ar[j]<ar[pos])
                pos=j;
        temp=ar[i];ar[i]=ar[pos];ar[pos]=temp;
    }
}
void printAr()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d%s",ar[i],i==n-1?"\n":", ");
}