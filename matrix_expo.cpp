#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long li;

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,n,p;
	n=3;
	//ll a[n][n]={{2,3,1},{4,3,1},{1,1,1,}};
	//ll out[n][n]={{2,3,1},{4,3,1},{1,1,1,}};
	//ll temp[n][n];
	ll a=7;
	ll out=1;
	p=4;
	while(p>0)
	{
		if(p&1)
		{
			out=out*a;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					temp[i][j]=0;
					for(k=0;k<n;k++)
					{
						temp[i][j]+=out[j][k]*a[k][j];
					}
				}
			}
		}
		a*=a;
		p=p>>1;
	}
	cout<<out<<endl;

}