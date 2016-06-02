#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
	ll i,j,n;
	string a=")))";
	n=a.size();
	ll op=0,cl=0,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]=='(')
			op++;
		else
		{
			if(op<=cl)
				count++;
			else
				op--;
		}
	}
	count+=op;
	/*
	ll op=0,cnt=0;
	for(i=0;i<m;i++)
	{
		if(a[i]=='(')
			op++;
		else
		{
			if(op)
				op--;
			else
				cnt++;
		}
	}
	cnt+=op;
	*/
	cout<<count<<endl; //total count of unmatched brackets
}