#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int V, int e){

    vector<int> *adjlist = new vector<int>[V];

    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
    }
    return adjlist;
}

bool isCycleDfs(int node, vector<int> adj[], vector<int> &visited, vector<int> loc_vis){
    visited[node] = 1;
    loc_vis[node] = 1;

    for(auto k : adj[node]){
        if(!visited[k]){
            if(isCycleDfs(k, adj, visited, loc_vis)) return true;
        }else if(loc_vis[k]){
            return true;
        }
    }

    return false;
}

int main(){
    int V, e;
    cin>>V>>e;
    vector<int> * adj = createGraph(V, e);

    vector<int> visited(V, 0);
    vector<int> loc_vis(V, 0);
    for(int j = 0; j < V; j++){
        if(!visited[j])
        if(isCycleDfs(j, adj, visited, loc_vis)){
            cout<<"1";
            return 0; 
        }
    }
    cout<<"0";
    return 0;
}