#include <stdio.h>
#include <string.h>

#define MAX(i,j) i>j?i:j

int main()
{
	int i,j,k,n,max_len=0;
	char a[] = "aibohphobia";
	n = strlen(a);
	int b[n][n];

	for(i=0;i<n;i++)
	{
		b[i][i]=1;
	}

	for(j=1;j<n;j++)
	{
		for(i=0;i+j<n;i++)
		{
			if(a[i]==a[i+j])
			{
				b[i][i+j]=b[i+1][i+j-1]+2;
			}
			else
			{
				b[i][i+j]=MAX(b[i+1][i+j],b[i][i+j-1]);
			}
			if(b[i][i+j]>max_len)
			max_len=b[i][i+j];
		}
	}
	printf("%d\n  ",max_len);
	for(i=0;i<n;i++)
		printf("%c ",a[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%c ",a[i]);
		for(k=0;k<i;k++)
			printf("  ");
		for(j=i;j<n;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
}