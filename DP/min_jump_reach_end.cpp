/*
minimum steps required to go from start of array to end of array
if the value at any index of array is the maximum range of jump
allowed from the index

We apply DP approach
Time Complexity : O(n^2)
*/

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

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,max=1e5;
	ll n=10;
	ll a[]={2,3,1,1,2,4,2,0,1,1};
	ll jump[n];
	ll from[n];
	for(i=1;i<n;i++)
		jump[i]=max;
	jump[0]=0;
	from[0]=-1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]+j<i)
				continue;
			if(jump[j]+1<jump[i])
			{
				jump[i]=jump[j]+1;
				from[i]=j;
			}
		}
	}

	for(i=0;i<n;i++)
		cout<<jump[i]<<" ";
	cout<<endl;

	for(i=0;i<n;i++)
		cout<<from[i]<<" ";
	cout<<endl;
}