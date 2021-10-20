#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int V, int e){
    vector<int> *adjlist = new vector<int> [V];

    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    return adjlist;
}

bool isCycleDfs(int node, int parent_node, vector<int> adj[], vector<bool> &visited){
    visited[node] = true;

    for(auto k : adj[node]){
        if(k != parent_node){
            if(!visited[k]){
                if(isCycleDfs(k, node, adj, visited)) return true;
            }else{
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V, e;
    cin>>V>>e;
    vector<int> *adj = createGraph(V, e);

    vector<bool> visited(V, false);
    for(int j = 0; j < V; j++){
        if(!visited[j]){
            if(isCycleDfs(j, -1, adj, visited)){
                cout<<"1";
                return 0;
            } 
        }
    }
    cout<<"0";
    return 0;
}