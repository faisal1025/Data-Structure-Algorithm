// Shortest path in a DAG from a source node

#include<bits/stdc++.h>
using namespace std;

void topoDfs(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st){
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

vector<int> sortestPath(int S, vector<pair<int, int>> adj[], int V){
    vector<int> visited(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!visited[i])
            topoDfs(i, adj, visited, st);
    }

    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        if(dist[cur] != INT_MAX){
            for(auto adjNode : adj[cur]){
                int data = adjNode.first;
                int wt = adjNode.second;
                if(dist[data] > dist[cur]+wt){ // Relaxation for sortest path
                    dist[data] = dist[cur] + wt;
                }
            }
        }
    }
    return dist;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int> >adj[n];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
    }
    /*
            6 7
            0 1 2
            2 3 6
            0 4 1
            4 2 2
            4 5 4
            5 3 1
            1 2 3
            0

            ans : 0 2 3 6 1 5 
    */

    int s;
    cin>>s;
    vector<int> ans = sortestPath(s, adj, n);
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == INT_MAX){
            cout<<"INF ";
            continue;
        }
        cout<<ans[i]<<" ";
    }

    return 0;
}