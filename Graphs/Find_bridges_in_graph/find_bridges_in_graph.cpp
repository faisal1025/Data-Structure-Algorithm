#include<bits/stdc++.h>
using namespace std;

int times;

void findBridgesDfs(int node, int parent, vector<int> adj[], vector<int> &visited, int in[], int low[]){
    visited[node] = 1;
    in[node] = low[node] = times;
    times++;

    for(auto adjNode : adj[node]){
        if(!visited[adjNode]){
            // Case of front edge
            findBridgesDfs(adjNode, node, adj, visited, in, low);
            if(low[node] < low[adjNode]){
                cout<<node<<" - "<<adjNode<<" is a bridge\n";
            }else{
                low[node] = min(low[node], low[adjNode]);
            }
        }

        else if(visited[adjNode] and adjNode != parent){
            // Case of Back edge
            low[node] = min(low[node], in[adjNode]);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int in[n] = {0};
    int low[n] = {0};
    vector<int> visited(n, 0);
    findBridgesDfs(0, -1, adj, visited, in, low);
}