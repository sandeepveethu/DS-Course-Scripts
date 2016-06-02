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
typedef vector<ll,ll> vll;
ll maxx = 10000;
int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,n,l;
	string a = "ababbbabbababa";
	n = a.size();
	ll c[n][n];
	bool p[n][n];
	for(i=0;i<n;i++)
	{
		p[i][i]=1;
		c[i][i]=0;
	}

	for(l=1;l<n;l++)
	{
		for(i=0;i<n;i++)
		{
			j=i+l;
			if(l==1)
				p[i][j]=(a[i]==a[j]);
			else
				p[i][j]=(a[i]==a[j])&&(p[i+1][j-1]);

			if(p[i][j])
				c[i][j]=0;
			else
			{
				c[i][j]=maxx;
				for(k=i;k<j;k++)
				{
					c[i][j]=MIN(c[i][j],c[i][k]+c[k+1][j]+1);
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}

	cout<<"minimum partition required for "<<a<<" are "<<c[0][n-1]<<endl;
}