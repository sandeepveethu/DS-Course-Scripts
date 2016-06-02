//longest palindromic sequence

#include <stdio.h>

int main()
{
	int i,j,l,n=9,k=0,len,max=0,max_len=0;
	char c[]="character";
	//char c[]="aaacaaa";
	//char c[]="agbdba";
	int a[n];
	for(i=0;i<n;i++)
		a[i]=0;

	for(l=n-1;l>=0;l--)
	{
		max=0;
		k=0;
		len=0;
		for(i=l;i>=0;i--)
		{
			for(j=k;j<=i;j++)
			{
				if(c[i]==c[j])
				{
					k=j+1;
					if(i==j)	
						len++;
					else
						len+=2;
				if(len>max)
					max=len;
				break;
				}
			}
			if(k>i)
				break;
		}
		a[l]=max;
		if(a[l]>max_len)
			max_len=a[l];
		
		//if c[]="character" then this outermost loop will break at c[l]='c'
		//since a[l]=5 and in subarray "chara" even if the whole subarray is palindromic
		//its length will be 5 which is less than or equal to a[l] so no need to check further
		//use this only if you have to find only the length of lps for whole string
		//and not the length of lps at each index
		if(a[l]>l-2)
			break;
	}
	//a[i] now contains length of lps which ends at c[i]
	//so lps of the sequence is the max in a[]
	
	//for(i=0;i<n;i++)
	//	printf("%d ",a[i]);
	
	printf("%d\n",max_len);
}