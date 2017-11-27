
/* 
 * File:   MergeSort.c
 * Author: sarthakmanna
 *
 * Created on 14 November, 2017, 1:06 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Merge Sort
 */

int ar[MAX],n;

void sort(int,int);
void mergeSegments(int,int,int);
void printAr();

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
void sort(int lb,int ub)    // Merge Sort
                            // Average Case Complexity: O(N*log N)
                            // Worst Case Complexity: O(N*log N)
{
    int mid=lb+(ub-lb)/2;
    if(lb<ub)
    {
        sort(lb,mid);sort(mid+1,ub);
        mergeSegments(lb,ub,mid);
    }
}
void mergeSegments(int l,int r,int mid)
{
    int temp[MAX],pt1=l,pt2=mid+1,k=0;
    if(r<=l)return;
    while(1)
    {
    	if(pt1>mid && pt2>r)break;
    	if(pt1>mid)temp[k++]=ar[pt2++];
    	else if(pt2>r)temp[k++]=ar[pt1++];
    	else if(ar[pt1]<ar[pt2])temp[k++]=ar[pt1++];
    	else temp[k++]=ar[pt2++];
    }
    for(k=0;l<=r;l++,k++)
        ar[l]=temp[k];
}

void printAr()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d%s",ar[i],i==n-1?"\n":", ");
}