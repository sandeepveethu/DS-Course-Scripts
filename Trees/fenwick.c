#include <stdio.h>

void init_tree(int*,int);
void createtree(int*,int*,int);
void updatetree(int*,int*,int,int,int);
int rsq(int*,int,int,int);
void main()
{
	int i,n=7;
	int a[] = {2,5,3,-1,6,4,2};
	int m=n+1;
	int tree[m];
	init_tree(tree,m); //set every node to 0

	createtree(a,tree,n);

	printf("Fenwick Tree is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",tree[i]);
	}
	
	//updatetree(a,tree,n,2,5); //index is 2 of a[] and new value is 5
	printf("\n%d\n",rsq(tree,m,2,5));
}

void init_tree(int* tree, int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		tree[i]=0;
	}
}

void createtree(int *a, int *tree, int n)
{
	int m=n+1,i,k,j=0; //j is the current index of a[]

	for(i=1;i<m;i++)
	{
		k = i;
		while(k<m)
		{
			tree[k] += a[j];

			//formula for finding next index of tree[] which needs to be updated
			//Steps: 1.Take 2's complement 2.AND it with original number i.e. k 3. ADD it with k
			k = k + (k & -k);
		}
		j++;
	}
}

void updatetree(int *a, int* tree,int n, int index, int value)
{
	int m=n+1; //length of tree array

	a[index] = value; //updating array a[] takes O(1) time

	//code for updating tree takes O() time
	index++;
	int increment = value-tree[index]; //increment can be negative
	while(index<m)
	{
		tree[index] += increment;
		index = index + (index & -index); //same as the formula used in createtree()
	}
}

/*int rsq(int* tree, int m, int high) //prefix_sum from index 0 of array a to high
{
	int i,prefix_sum=0;
	high++;
	while(high>0)
	{
		prefix_sum += tree[high];
		high = high & (high-1) ;//flipping the right most bit
	}
	return prefix_sum;
}*/

int rsq(int* tree, int m, int low, int high)
{
	int low_sum=0,high_sum=0;
	high++;
	while(high>0)
	{
		high_sum += tree[high];
		high = high & (high-1) ;
	}

	while(low>0)
	{
		low_sum += tree[low];
		low = low & (low-1) ;
	}

	return high_sum-low_sum;
}



//we can tune fenwick tree to increment or decrement values in a range by same value within array
//Time complexity of this operation is O(lg n)
//Courtesy:
//http://petr-mitrichev.blogspot.com/2013/05/fenwick-tree-range-updates.html

//Range update query code

void range_update(int * tree, int m, int low, int high)
{

}