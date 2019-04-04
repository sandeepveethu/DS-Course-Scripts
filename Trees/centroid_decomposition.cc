#include <iostream>
#include <vector>

using namespace std;

void find_weights(int node, vector<int>& wt, vector<bool>& vis, vector<vector<int> >& adjlist, vector<bool> & in_centroid_tree) {
        vis[node]=true;
        for(int i=0;i<adjlist[node].size();i++) {
                int j = adjlist[node][i];
                if(!vis[j] && !in_centroid_tree[j]) {
                        find_weights(j, wt, vis, adjlist, in_centroid_tree);
                        wt[node] += wt[j] + 1;
                }
        }
}

int find_centroid(int node, vector<int>& wt, vector<bool>& vis, vector<vector<int> >& adjlist, vector<bool> & in_centroid_tree) {
        for(int i=1;i<=vis.size();i++){wt[i]=0;vis[i]=false;}
        find_weights(node,wt,vis,adjlist,in_centroid_tree);
        for(int i=1;i<=vis.size();i++)vis[i]=false;
        int n = wt[node]+1;
        for(;;) {
                vis[node]=true;
                int node_copy=node;
                for(int j=0;j<adjlist[node].size();j++) {
                        int k=adjlist[node][j];
                        if(!vis[k] && !in_centroid_tree[k]) {
                                if(wt[k]+1 > n/2){node=k;break;}
                        }
                }
                if(node==node_copy)break;
        }
        return node;
}

void construct_centroid_tree(int centroid, vector<int>& wt, vector<bool>& vis, vector<vector<int> >& adjlist, vector<vector<int> >& centroid_tree, vector<bool>& in_cent
roid_tree) {
        in_centroid_tree[centroid]=true;
        for(int i=0;i<adjlist[centroid].size();i++) {
                int j = adjlist[centroid][i];
                if(!in_centroid_tree[j]) {
                        int child_centroid = find_centroid(j, wt, vis, adjlist, in_centroid_tree);
                        centroid_tree[centroid].push_back(child_centroid);
                        construct_centroid_tree(child_centroid, wt, vis, adjlist, centroid_tree, in_centroid_tree);
                }
        }
}


int main() {
        int n; cin>>n;
        vector<vector<int> > adjlist(n+1);
        for(int i=1;i<n;i++) {
                int j,k; cin>>j>>k;
                adjlist[j].push_back(k);
                adjlist[k].push_back(j);
        }
        vector<vector<int> > centroid_tree(n+1);
        vector<int> wt(n+1, 0);
        vector<bool> vis(n+1, 0);

        vector<bool> in_centroid_tree(n+1,0);

        int centroid=find_centroid(1,wt,vis,adjlist,in_centroid_tree);

        construct_centroid_tree(centroid, wt, vis, adjlist, centroid_tree, in_centroid_tree);

        cout<<"adjacency list for centroid tree is:"<<endl;
        for(int i=1;i<=n;i++) {
                cout<<i;
                for(int j=0;j<centroid_tree[i].size();j++)cout<<" "<<centroid_tree[i][j];
                cout<<endl;
        }
}
