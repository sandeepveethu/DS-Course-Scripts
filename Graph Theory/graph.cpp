#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

int main()
{
	int vertices,edges,v1,v2,weight;

	cout<<"Enter the number of vertices\n";
	cin>>vertices;

	cout<<"Enter the number of edges\n";
	cin>>edges;

    // Adjacency List is a vector of list.
    // Where each element is a pair<int, int>
    // pair.first -> the edge's destination
    // pair.second -> edge's weight

    vector<list <pair<int,int> > >adj_list(vertices+1);

    cout<<"Enter the edges of v1-v2 and their weight\n";

    //1-indexing for graph
    for(int i=1;i<=edges;i++)
    {
    	cin>>v1>>v2>>weight;

    	adj_list[v1].push_back(make_pair(v2,weight));

    	//if graph is undirected
    	adj_list[v2].push_back(make_pair(v1,weight));

    	//adj_list[v1].first = v2;
    	//adj_list[v1].second = weight;

    }

    cout<<"The Adjacency list is:"<<endl;

    for(int i=1;i<adj_list.size();i++)
    {
    	list<pair<int,int> >::iterator itr = adj_list[i].begin();
    	cout<<i<<"  ";

    	while(itr!=adj_list[i].end())
    	{
    		cout<<"->"<<(*itr).first<<","<<(*itr).second<<" ";
    		itr++;
    	}
    	cout<<endl;
    }
}