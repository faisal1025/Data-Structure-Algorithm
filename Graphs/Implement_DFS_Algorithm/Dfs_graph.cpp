#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int V, int edges){
    vector<int> *adjlist = new vector<int>[V];
    for(int i = 0; i < edges; i++){
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        // adjlist[v].push_back(u);
    }
    return adjlist;
}

vector<int> dfs(int node, vector<int> adj[], vector<bool> &visited){
    visited[node] = true;
    static vector<int> ans;
    ans.push_back(node);
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<bool> visited(n, false);
    vector<int> *adj = createGraph(n, m);

    vector<int> result;
    for(int i = 2; i < n; i++){
        if(!visited[i]){
            vector<int> temp = dfs(i, adj, visited);
            result.insert(result.end(), temp.begin(), temp.end());
        }
    }
    for(auto i : result){
        cout<<i<<" ";
    }
}