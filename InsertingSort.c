
/* 
 * File:   InsertingSort.c
 * Author: sarthakmanna
 *
 * Created on 13 November, 2017, 11:30 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Insertion Sort
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
void sort()         // Insertion Sort
                    // Best Case Complexity: O(N)
                    // Worst Case Complexity: O(N^2)
{
    int i,j,val;
    for(i=0;i<n;i++)
    {
        val=ar[i];
        for(j=i-1;j>=0;j--)
            if(ar[j]>val)
                ar[j+1]=ar[j];
            else
                break;
        ar[j+1]=val;
    }
}
void printAr()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d%s",ar[i],i==n-1?"\n":", ");
}