//Given an array having N integers, find the contiguous subarray having sum 
//as great as possible, but not greater than M

//solving using Binary Search

#include <stdio.h>

void fillaux(int* a, int* aux, int n);

void main()
{
	int i,j,n;
	int a[]={2,3,1,4,5,2,6,1,7};
	n=9;
	int aux[n];
	fillaux(a,aux,n); //aux[] contains cumulative sums
	//NOTE: aux[] will be in sorted order, because cumulative sums increase
	find_subarray(a,aux,n);
}

void fillaux(int* a, int* aux, int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		aux[i]=0;
	}

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			aux[j]+=a[i];
		}
	}
}

void find_subarray(int* a, int* aux, int n)
{
	
}