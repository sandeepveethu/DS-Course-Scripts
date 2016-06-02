#include <iostream>

#define MAX(i,j) i>j?i:j

using namespace std;

int main()
{
	int i,j,n=4;
	int v[]={0,10,40,30,50};
	int w[]={0,5,4,6,3};
	int wt=10; //weight limit of knapsack

	int a[n+1][wt+1];
	for(i=0;i<=wt;i++)
	{
		a[0][i]=0; //first row is zero
	}

	for(i=1;i<=n;i++)
	{
		for(j=0;j<=wt;j++)
		{
			if(w[i]<=j)
				a[i][j]=MAX(a[i-1][j],v[i]+a[i-1][j-w[i]]);
			else
				a[i][j]=a[i-1][j];
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=wt;j++)
		{
			cout<<a[i][j];
			if(a[i][j]<10)
				cout<<"   ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
}