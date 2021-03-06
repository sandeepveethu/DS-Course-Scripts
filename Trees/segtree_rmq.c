//C code for Range Minimum Query(RMQ) using Segment Tree

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX INT_MAX
#define MIN(i,j) i<j?i:j

void initialisetree(int*,int);
void createtree(int*,int*,int,int,int,int);
int rmq(int*,int,int,int,int,int,int);


void main()
{
	int i,n = 6;
	int a[] = {-1,3,4,0,2,1};

	//if n is a power of 2 then t is 2n-1
	//otherwise, say if n is 5, then it is 2(2^3)-1 = 15
	//meaning take the next power of 2 which is greater than n 
	//i.e. here 8>5 and then apply 2n-1 on that
	int t = (int)((2*pow(2,(int)ceil(log2(n))))-1) ;

	//another way of determining tree size
	//i=1;
	//while((1<<i++)<n);
	//t=(1<<(i+1))-1;

	//leaf nodes start from t/2
	int tree[t]; // t is no of elements in segment tree

	//set each value in array to MAX
	initialisetree(tree,t);

	createtree(a,tree,t,0,0,n-1);

	for(i=0;i<t;i++)
	{
		if(tree[i]==MAX)
		{
			printf("MAX ");
			continue;
		}
		printf("%d ",tree[i]);
	}
	printf("\n%d\n",rmq(tree,t,0,n-1,0,4,0));
}

void initialisetree(int* tree, int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		tree[i] = MAX ;
	}
}

//tree is constructed in bottom up fashion
void createtree(int* a, int* tree, int t, int pos, int low, int high)
{
	int mid;

	if(low==high)
	{
		//printf("tree position is %d and low is %d and value is %d\n",pos,low,a[low]);
		tree[pos] = a[low];
		return;
	}
	else
	{
		mid = (high+low)/2;
		createtree(a,tree,t,2*pos+1,low,mid);
		createtree(a,tree,t,2*pos+2,mid+1,high);
		tree[pos] = MIN(tree[2*pos+1],tree[2*pos+2]);
	}

}

int rmq(int tree[], int t, int low, int high, int l, int r,int pos)
{
	int a,b,mid;

	if(high<l || low>r)
	{
		return MAX ;
	}
	else if(low>=l && high<=r)
	{
		return tree[pos];
	}
	else
	{
		mid = (low+high)/2;
		a = rmq(tree,t,low,mid,l,r,2*pos+1);
		b = rmq(tree,t,mid+1,high,l,r,2*pos+2);
		return MIN(a,b);
	}
}