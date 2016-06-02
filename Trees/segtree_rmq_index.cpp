//Range Maximum Query to find index of maximal value in certain range
#include <iostream>
#include <stdio.h>
#include <vector>

#define MIN -1e3
using namespace std;
typedef long long int ll;

void createtree(ll a[],vector<pair<ll,ll> >&tree,ll pos,ll low,ll high);
pair<ll,ll> rmq(vector<pair<ll,ll> > tree,ll low,ll high,ll l,ll r,ll pos);



int main()
{
	ll i,j,n=6,tl;
	i=1;
	ll a[]={MIN,-1,0,6,2,3};
	while((1<<i++)<(n));
	tl=(1<<(i+1)-1);

	vector<pair<ll,ll> > tree;

	//initialise tree
	for(i=0;i<tl;i++)
	{

		tree.push_back(make_pair(0,a[0]));
	}

	//createtree
	createtree(a,tree,0,0,n-1);

	for(i=0;i<tl;i++)
	{
		cout<<"("<<tree[i].first<<","<<tree[i].second<<") ";
	}
	cout<<endl;
	cout<<rmq(tree,0,n-1,1,3,0).second<<endl;
	cout<<rmq(tree,0,n-1,4,5,0).second<<endl;
	cout<<rmq(tree,0,n-1,1,5,0).second<<endl;
	cout<<rmq(tree,0,n-1,1,2,0).second<<endl;


}

void createtree(ll a[],vector<pair<ll,ll> >&tree,ll pos,ll low,ll high)
{
	ll mid;
	if(low==high)
	{
		tree[pos].first=low;
		tree[pos].second=a[low];
	}
	else
	{
		mid=(high+low)/2;
		createtree(a,tree,2*pos+1,low,mid);
		createtree(a,tree,2*pos+2,mid+1,high);
		if(tree[2*pos+1].second>tree[2*pos+2].second)
		{
			tree[pos].first=tree[2*pos+1].first;
			tree[pos].second=tree[2*pos+1].second;
		}
		else
		{
			tree[pos].first=tree[2*pos+2].first;
			tree[pos].second=tree[2*pos+2].second;
		}
	}
}

pair<ll,ll> rmq(vector<pair<ll,ll> > tree,ll low,ll high,ll l,ll r,ll pos)
{
	ll mid;
	pair<ll,ll> a,b;
	if(low>r || high<l)
	{
		return make_pair(0,MIN);
	}
	else if(low>=l && high<=r)
	{
		return tree[pos];
	}
	else
	{
		mid=(low+high)/2;
		a = rmq(tree,low,mid,l,r,2*pos+1);
		b = rmq(tree,mid+1,high,l,r,2*pos+2);
		if(a.second>b.second)
			return a;
		else
			return b;

	}

}