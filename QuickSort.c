
/* 
 * File:   QuickSort.c
 * Author: sarthakmanna
 *
 * Created on 13 November, 2017, 11:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Quick Sort
 */

int ar[MAX],n;

void printAr();
void sort(int,int);
void swap(int,int);

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
    sort(0,n-1);
    printf("The Array after Sorting: ");
    printAr();
    return EXIT_SUCCESS;
}
void sort(int lb,int ub)    // Quick Sort
                            // Average Case Complexity: O(N*log N)
                            // Worst Case Complexity: O(N^2)
{
    int pivot=ar[lb],up=ub,down=lb;
    if(ub<=lb)return;
    while(down<up)
    {
        while(pivot>=ar[down] && down<up)down++;
        while(pivot<ar[up])up--;
        if(down<up)
            swap(down,up);
    }
    swap(lb,up);
    sort(lb,up-1);sort(up+1,ub);
}
void swap(int a,int b)
{
    int t=ar[a];ar[a]=ar[b];ar[b]=t;
}
void printAr()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d%s",ar[i],i==n-1?"\n":", ");
}