#include<bits/stdc++.h>
using namespace std;

// Total time Complexity : O(E logV)
int primsAlgo(vector<pair<int, int> > *adj, vector<int> &parent, vector<int> &addMST, vector<int> &minWt){
    minWt[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, 0});
    int cost = 0;
    // TC : O(E logV)
    while(!pq.empty()){
        
        int curr = pq.top().second;
        if(addMST[curr]){
            pq.pop();
            continue;
        }
        cost += pq.top().first;
        addMST[curr] = 1;
        pq.pop();
        for(auto adjNode : adj[curr]){
            if(!addMST[adjNode.first] and adjNode.second < minWt[adjNode.first]){
                minWt[adjNode.first] = adjNode.second;
                parent[adjNode.first] = curr;
                pq.push({adjNode.second, adjNode.first});
            }
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