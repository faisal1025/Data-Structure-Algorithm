/*
    Topological sort is a an arrangement of nodes of a graph in linear fashion as
    if  u->v then in the list u must come first then v will come.
    eg. u v 

    * keypoints - 1. The graph must be directed for topological sort
    2. Graph must be Acyclic or non-cyclic (not having cycle in graph).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int v, int e, int indegree[]){
    vector<int> *adjlist = new vector<int>[v];

    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        indegree[b]++;
    }
    return adjlist;
}

vector<int> topologicalSortBfs(int v, vector<int> adj[], int indegree[], queue<int> &q){
    vector<int> ans;
    while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        ans.push_back(curr_node);
        for(auto node : adj[curr_node]){
            indegree[node]--;
            if(indegree[node] == 0){
                q.push(node);
            }
        }
    }
    return ans;
}

int main(){
    int v, e;
    cin>>v>>e;
    int indegree[v] = {0};
    vector<int> *adj = createGraph(v, e, indegree);
    cout<<"indegree - ";
    for(int i = 0; i < v; i++){
        cout<<indegree[i]<<" ";
    }
    cout<<"\n";
    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> result = topologicalSortBfs(v, adj, indegree, q);
    for(auto k : result){
        cout<<k<<" ";
    }

    return 0;
}