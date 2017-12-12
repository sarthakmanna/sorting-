#include <stdio.h>

void radixSort(int[],int,int);
void printAr(int[],int);

int main()
{
	int ar[]={554,363,326,673,123,843,78,656,763,182,400};
	printf("Unsorted: ");
	printAr(ar,11);
	radixSort(ar,0,10);
	printf("Sorted: ");
	printAr(ar,11);
  return 0;
}

int mat[100][10],endInd[10];
void radixSort(int ar[],int s,int e)
{
	int i,j,d,modV=10,divVal=1;
	for(i=0;i<10;i++)endInd[i]=0;
	for(i=0;i<19;i++)
	{
		for(j=s;j<=e;j++)
		{
			d=(ar[j]%modV)/divVal;
			mat[endInd[d]++][d]=ar[j];
		}
		modV*=10;divVal*=10;
		d=0;
		for(j=0;j<10;j++)
		{
			for(int k=0;k<endInd[j];k++)
				ar[d++]=mat[k][j];
			endInd[j]=0;
		}
			
	}
}
void printAr(int ar[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",ar[i]);
	printf("\n");
}
