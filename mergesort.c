#include <stdio.h>

#define MIN -100000
#define MAX 100000

void mergesort(int*a,int low,int high);
void merge(int*a,int low,int mid,int high);
int main()
{
	int i,j,n=6;
	int a[]={6,5,4,3,2,1};
	mergesort(a,0,5);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);


}

void mergesort(int*a,int low,int high)
{
	int i,mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void merge(int*a,int low,int mid,int high)
{
	int i;
	int j;
	int k;
	int l_len=mid-low+1,r_len=high-mid;
	int l[l_len];
	int r[r_len];
	i=0;
	for(k=low;k<=mid;k++)
	{
		l[i]=a[k];
		i++;
	}
	j=0;
	for(k=mid+1;k<=high;k++)
	{
		r[j]=a[k];
		j++;
	}
	i=0;j=0;
	for(k=low;k<=high;k++)
	{
		if(i<l_len && j<r_len)
		{
			if(l[i]<=r[j])
			{
				a[k]=l[i];
				i++;
			}
			else
			{
				a[k]=r[j];
				j++;
			}
		}
		else if(i>=(l_len))
		{
			a[k]=r[j];
			j++;
		}
		else if(j>=(r_len))
		{
			a[k]=l[i];
			i++;
		}
	}

}