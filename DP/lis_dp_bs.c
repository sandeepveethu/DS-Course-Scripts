//longest increasing subsequence algorithm by dynamic programming using binary search
//O(n*lgn) time complexity

#include <stdio.h>
void print_t(int* t, int n);

void main()
{
	int a[] = {3,4,-1,5,8,2,3,12,7,8,9};

	int i,j,temp,n=11,len=0;

	int t[n],r[n];
	t[0]=0;
	for(i=0;i<n;i++)
	{
		r[i]=-1;
	}
	for(i=1;i<n;i++)
	{
		if(a[i]<a[t[0]])
		{
			t[0]=i;
			printf("\nfor i=%d\n",i);
			print_t(r,n);
		}
		else if(a[i]>a[t[0]] && a[i]<a[t[len]])
		{
			temp = findceil(a,t,0,len,a[i]);
			r[i] = t[temp-1];
			t[temp] = i;
			printf("\nfor i=%d\n",i);
			print_t(r,n);
		}
		else if(a[i]>a[t[len]])
		{
			r[i]=t[len];
			len++;
			t[len]=i;
			printf("\nfor i=%d\n",i);
			print_t(r,n);
		}
	}
printf("\n");
	print_t(t,len+1);
	printf("\n");
	print_t(r,n);
	printf("\n");
	printf("%d\n",len+1);

}

int findceil(int a[],int t[], int low, int high, int key)
{
	int mid,current_ceil,temp;
	if(low==high)
	{
		if(a[t[low]]>=key)
		{
			return low; //returns the index
		}
	}
	else
	{
		mid = (low+high)/2;
		if(a[t[mid]]>key)
		{
			return findceil(a,t,0,mid,key);
		}
		if(a[t[mid]]<key)
		{
			return findceil(a,t,mid+1,high,key);
		}
		if(a[t[mid]]==key)
		{
			return mid; //returns the index
		}
	}
}

void print_t(int* t, int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",t[i]);
	}
}

