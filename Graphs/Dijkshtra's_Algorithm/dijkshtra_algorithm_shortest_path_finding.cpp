#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<pair<int, int> > adj[], int s){
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int>> > pq;
    pq.push(make_pair(s, 0));
    // Time Complexity : O(N + E log N) ~= O(N log N)
    while(!pq.empty()){
        auto p = pq.top();
        int curr = p.first;
        int currWt = p.second;
        if(visited[curr]){
            pq.pop();
            continue;
        }
        visited[curr] = true;
        pq.pop();
        for(auto adjNodePair : adj[curr]){
            int adjNode = adjNodePair.first;
            int adjWt = adjNodePair.second;
            if(visited[adjNode] == false and dist[adjNode] > currWt+adjWt){
                dist[adjNode] = currWt+adjWt;
                pq.push(make_pair(adjNode, currWt+adjWt));
            }
        }
    }
    return dist;
}

int main(){
    int V, e;
    cin>>V>>e;
    vector<pair<int, int> > adjList[V];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adjList[a].push_back({b, wt});
        adjList[b].push_back({a, wt});
    }
    int S;
    cin>>S;
    /*
            5 6
            0 1 2
            0 3 1
            1 4 5
            1 2 4
            3 2 3
            2 4 1
            0

            ans : 0 2 6 1 7 
    */
    vector<int> ans = dijkstra(V, adjList, S);
    cout<<"Shortest distance to each node from node "<<S<<":\n";
    for(int i = 0; i < V; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}