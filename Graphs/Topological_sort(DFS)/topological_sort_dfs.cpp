/*
    Topological sort is a an arrangement of nodes of a graph in linear fashion as
    if  u->v then in the list u must come first then v will come.
    eg. u v 

    * keypoints - 1. The graph must be directed for topological sort
    2. Graph must be Acyclic or non-cyclic (not having cycle in graph).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int v, int e){
    vector<int> * adjlist = new vector<int>[v];
    for(int i = 0; i < e; i++){
        int x, y;
        cin>>x>>y;
        adjlist[x].push_back(y);
    }
    return adjlist;
}

void topologicalSortDfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st){
    visited[node] = true;
    for(auto k : adj[node]){
        if(!visited[k]){
            topologicalSortDfs(k, adj, visited, st);
        }
    }
    st.push(node);
}


int main(){
    int v, e;
    cin>>v>>e;
    vector<int> * adj = createGraph(v, e);
    vector<bool> visited(v, false);
    stack<int> st;
    for(int j = 0; j < v; j++){
        if(!visited[j]){
            topologicalSortDfs(j, adj, visited, st);
        }
    }
    vector<int> result;
    while(!st.empty()){
        result.emplace_back(st.top());  
        st.pop();
    }

    // printing result
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
}