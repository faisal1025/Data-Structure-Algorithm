#include<bits/stdc++.h>
using namespace std;

// Total time Complexity : O(N^(N+e)) ~= O(N^2)
int primsAlgo(vector<pair<int, int> > *adj, vector<int> &parent, vector<int> &addMST, vector<int> &minWt){
    minWt[0] = 0;
    queue<int> q;
    q.push(0);
    int cost = 0;
    // TC : O(N)
    while(!q.empty()){
        
        pair<int, int> min = {0, INT_MAX};
        int curr = q.front();
        addMST[curr] = 1;
        q.pop();
        for(auto adjNode : adj[curr]){
            if(!addMST[adjNode.first] and adjNode.second < minWt[adjNode.first]){
                minWt[adjNode.first] = adjNode.second;
                parent[adjNode.first] = curr;
            }
        }
        // TC : O(N)
        for(int i = 0; i < minWt.size(); i++){
            if(!addMST[i] and minWt[i] < min.second){
                min = {i, minWt[i]};
            }
        }
        if(min.first != 0 && min.second != INT_MAX){
            cost += min.second;
            q.push(min.first);
        }
    }
    return cost;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int> > adj[n];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    /*
        9 14
        7 6 1
        8 2 2
        6 5 2
        0 1 4
        2 5 4
        8 6 6
        2 3 7
        7 8 7
        0 7 8
        1 2 8
        3 4 9
        5 4 10
        1 7 11
        3 5 14
    */

    vector<int> parent(n, -1);
    vector<int> addMST(n, 0);
    vector<int> minWt(n, INT_MAX);

    cout<<"Minimum Cost of spanning tree is "<<primsAlgo(adj, parent, addMST, minWt);
    cout<<"\nedges of spanning tree\n";
    cout<<"source |"<<" Destin |"<<" weight"<<"\n";
    for(int i = 1; i < n; i++){
        cout<<parent[i]<<" | "<<i<<" | "<<minWt[i]<<endl;
    }
    return 0;
}