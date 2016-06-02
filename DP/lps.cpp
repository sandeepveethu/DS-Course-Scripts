#include <iostream>
#include <vector>
#include <string>

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
	ll i,j,k,n;
	n = 6;
	string a = "agbdba";
	ll dp[n][n];
	for(i=0;i<n;i++)
		dp[i][i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			k=i+j;
			if(a[j]==a[k])
				dp[j][k]=dp[j+1][k-1]+2;
			else
				dp[j][k]=MAX(dp[j][k-1],dp[j+1][k]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Length of LPS in "<<a<<" is "<<dp[0][n-1]<<endl;
}