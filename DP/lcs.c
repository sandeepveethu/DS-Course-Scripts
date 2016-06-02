#include <stdio.h>
#define MAX(i,j) i>j?i:j

void printlcs(int i, int j, int m, int n,int x[], int y[], int c[m+1][n+1]);

void main()
{
	int i,j,n,m;
	//int x[]={1,2,3,2,4,1,2};
	//m=7;
	//int y[]={2,4,3,1,2,1};
	//n=6;

	int x[]={1,0,0,1,0,1,0,1};
	m=8;
	int y[]={0,1,0,1,1,0,1,1,0};
	n=9;

	int c[m+1][n+1];

	for(i=0;i<n+1;i++)
	{
		c[0][i]=0;
	}
	for(i=0;i<m+1;i++)
	{
		c[i][0]=0;
	}
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			else
			{
				c[i][j]=MAX(c[i-1][j],c[i][j-1]);
			}
		}
	}
	//printing array c[][]
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printlcs(m,n,m,n,x,y,c);
}

void printlcs(int i, int j,int m, int n,int x[], int y[],int c[m+1][n+1])
{
	if(i==0 || j==0)
	{
		return;
	}
	if(x[i-1]==y[j-1])
	{
		printlcs(i-1,j-1,m,n,x,y,c);
		printf("%d ",x[i-1]);
	}
	else if(c[i][j-1]>c[i-1][j])
	{
		printlcs(i,j-1,m,n,x,y,c);
	}
	else if(c[i-1][j]>=c[i][j-1]) //only else would suffice, writing if condition to be more explanatory
	{
		printlcs(i-1,j,m,n,x,y,c);
	}

}