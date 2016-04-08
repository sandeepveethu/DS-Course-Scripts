//longest increasing subsequence algorithm by dynamic programming
//O(n^2) time complexity

#include <stdio.h>

void printlis(int*,int);
void main()
{
	int a[] = {3,4,-1,0,6,2,3};

	//this array stores the longest subsequence length at each index of a[]
	//initially each element is a LIS on its own, so length is 1 at each index
	int lis[] = {1,1,1,1,1,1,1};
	
	int i,j,n=7;
	
	//start updating length of LIS at each index
	for(i=0;i<n;i++)
	{
		//move j from 0 to i-1 checking if a[j]<a[i]
		//if yes, then the LIS at a[j] can be extended by a[i]
		//thus making length of LIS at a[i] equal lis[j]+1
		//but, if lis[i] is already greater than lis[j]+1
		//then no need of extending because we keep track
		//of LONGEST increasing subsequence, so just ignore this j and move to j+1 
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i] && lis[j]+1>lis[i])
			{
				lis[i] = lis[j]+1;
			}
		}

		printf("for i=%d LIS status is ",i);
		printlis(lis,n);
	}


}

void printlis(int lis[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",lis[i]);
	}
	printf("\n");
}