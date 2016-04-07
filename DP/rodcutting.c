//determine the maximum obtainable revenue by cutting rod of length n in optimum pieces

#include <stdio.h>
#include <stdlib.h>

int slowrodcut(int*, int);
int bottomup_rodcut(int*, int);
int main()
{
	//array of price for a particular length
	int p[]={0,1,5,8,9,10,17,17,20,24,30}; //for length 0 to 10


	int i,j,l=11;

	printf("By top down recursive approach\n");
	for(i=0;i<l;i++)
	{
		printf("%d ",slowrodcut(p,i));
	}

	printf("\nBy bottomup dp approach\n");
	for(i=0;i<l;i++)
	{
		printf("%d ",bottomup_rodcut(p,i));
	}

}


//this is straightforward, top-down, recursive solution
//this algorithm is too slow
//for finding optimal revenue for length n rod, it takes O(2^n) time

int slowrodcut(int p[], int l)
{
	int i,r_max=-1,j;

	if(l==0)
		return 0;
	
	for(i=1;i<=l;i++)
	{
		j = p[i]+slowrodcut(p,l-i);
		
		if(j>r_max)
			r_max = j;
	}
	return r_max;
}


//using DP to optimize the time consumption
//first approach is "top down with memoization"
//in this, we write the procedure recursively but 
//it is modified to save the solution for each subproblem


//second approach is "bottom-up method" 
int bottomup_rodcut(int p[], int l)
{
	int i,j,r_max;

	int r[11]; //r[0] for rod of length 0

	r[0] = 0;

	for(i=1;i<=l;i++)
	{
		r_max=-1;
		for(j=i;j>0;j--)
		{
			if(p[j]+r[i-j]>r_max)
				r_max = p[j]+r[i-j];
		}
		r[i] = r_max;
	}

	return r[l];

}
