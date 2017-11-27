/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapSort.c
 * Author: sarthakmanna
 *
 * Created on 28 November, 2017, 1:04 AM
 */

#include <stdio.h>
#include <stdlib.h>

int ar[]={8,1,3,7,9,2,4,0},len=8;
int heap[100],top=0;

void addVal(int);
void removeVal(int);
void swap(int,int);

void printAr()
{
    int i;
    for(i=0;i<len;i++)
        printf("%d ",ar[i]);
    printf("\n");
}

int main(int argc, char** argv)
{
    int i;
    printf("Before Sorting: ");
    printAr();
    for(i=0;i<len;i++)
        addVal(ar[i]);
    printf("After Sorting: ");
    for(i=0;i<len;i++)
    {
        printf("%d ",heap[0]);
        removeVal(0);
    }
    return (EXIT_SUCCESS);
}
void swap(int a,int b)      // Time Complexity: O(1)
{
    int temp=heap[a];heap[a]=heap[b];heap[b]=temp;
}
void addVal(int val)        // Time Complexity: O(log N)
{
    int pos=top;
    heap[top++]=val;
    while((pos-1)/2>=0)
    {
        if(heap[(pos-1)/2]>heap[pos])
            swap(pos,(pos-1)/2);
        else break;
        pos=(pos-1)/2;
    }
}
void removeVal(int pos)     //Time Complexity: O(log N)
{
    swap(--top,pos);
    while(pos*2+2<top)
    {
        if(heap[pos]<=heap[pos*2+1] && heap[pos]<=heap[pos*2+2])
            return;
        if(heap[pos*2+1]<heap[pos*2+2])
        {
            swap(pos,pos*2+1);
            pos=pos*2+1;
        }
        else
        {
            swap(pos,pos*2+2);
            pos=pos*2+2;
        }
    }
    if(pos*2+1<top && heap[pos*2+1]<heap[pos])
        swap(pos,pos*2+1);
}