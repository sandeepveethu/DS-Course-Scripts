//finding ceiling of a key in a sorted array
#include <stdio.h>

int findceil(int a[], int low, int high, int key);
void main()
{
	int i,n;
	int a[]={1,3,5,8,10};
	n=5;
	printf("%d\n",findceil(a,0,n-1,2));
	printf("%d\n",findceil(a,0,n-1,7));
	printf("%d\n",findceil(a,0,n-1,5));
	printf("%d\n",findceil(a,0,n-1,9));
	printf("%d\n",findceil(a,0,n-1,11));

}

int findceil(int a[], int low, int high, int key)
{
	int mid,current_ceil,temp;
	if(low==high)
	{
		if(a[low]>=key)
		{
			return a[low];
		}
		else
		{
			printf("not found\n");
			return -1;
		}
	}
	else
	{
		mid = (low+high)/2;
		if(a[mid]>key)
		{
			return findceil(a,0,mid,key);
		}
		if(a[mid]<key)
		{
			return findceil(a,mid+1,high,key);
		}
		if(a[mid]==key)
		{
			return a[mid];
		}
	}
}