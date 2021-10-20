// DAG : Directed Acyclic Graph
// In a DAG we have to find the longest path from the source node to all its connected node.
// The source node and the graph is given

#include<bits/stdc++.h>
using namespace std;

void topoDfs(int node, vector<pair<int, int>> adj[], vector<int> & visited, stack<int> &st){
    visited[node] = 1;

    for(auto adjNode : adj[node]){
        int data = adjNode.first;
        int wt = adjNode.second;
        if(!visited[data]){
            topoDfs(data, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> longestPath(int S, int V, vector<pair<int, int>> adj[]){
    vector<int> visited(V, 0);
    stack<int> st;
    
    for(int i = 0; i < V; i++){
        if(!visited[i])
            topoDfs(i, adj, visited, st);
    }

    vector<int> dist(V, INT_MIN);

    dist[S] = 0;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        if(dist[cur] != INT_MIN){
            for(auto adjNode: adj[cur]){
                int data = adjNode.first;
                int wt = adjNode.second;
                if(dist[data] < dist[cur]+wt){ // Relaxation for longest path
                    dist[data] = dist[cur]+wt;
                }
            }
        }
    }
    return dist;

}

int main(){
    int n, e;
    cin>>n>>e;

    // Formation of DAG
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
    }

    /*
            6 10
            0 1 5
            0 2 3
            1 3 6
            1 2 2
            2 4 4
            2 5 2
            2 3 7
            3 5 1
            3 4 -1
            4 5 -2
            1

            ans: INT 0 2 9 8 10

    */

    int s;
    cin>>s;
    vector<int> longPath = longestPath(s, n, adj);
    for(int i = 0; i < longPath.size(); i++){
        if(longPath[i] == INT_MIN){
            cout<<"INT ";
        }else{
            cout<<longPath[i]<<" ";
        } 
    }

    return 0;
}