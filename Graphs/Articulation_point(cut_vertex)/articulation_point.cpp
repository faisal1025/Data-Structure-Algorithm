// articulation point is vertex in a graph which is when removed the graph gets disconnected
// in two or more components. 

#include<bits/stdc++.h>
using namespace std;

int timer;

void articulationPointDfs(vector<int> adj[], int node, int parent, vector<bool> &visited, set<int> &s, int in[], int low[]){
    visited[node] = true;
    in[node] = low[node] = timer++;
    int children = 0;
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        
        else if(visited[adjNode]){
            // back edge case
            low[node] = min(in[adjNode], low[node]);
        }
        else{
            // forward edge case
            articulationPointDfs(adj, adjNode, node, visited, s, in, low);
            low[node] = min(low[node], low[adjNode]);
            if(in[node] <= low[adjNode] and parent != -1){
                s.insert(node);
            }
            
            children++;
        }
    }
    if(parent == -1 and children > 1){
        s.insert(node);
    }
}


set<int> findArticulationPoint(int V, vector<int> adj[]){
    vector<bool> visited(V+1, false);
    int in[V+1];
    int low[V+1];
    set<int> s;
    for(int i = 1; i < V; i++){
        if(!visited[i]){
            articulationPointDfs(adj, i, -1, visited, s, in, low);
        }
    }
    return s;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adj[n+1];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find Articulation points
    set<int> ans = findArticulationPoint(n, adj);
    
    for (auto itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr<<" ";
    }
    
    return 0;
}