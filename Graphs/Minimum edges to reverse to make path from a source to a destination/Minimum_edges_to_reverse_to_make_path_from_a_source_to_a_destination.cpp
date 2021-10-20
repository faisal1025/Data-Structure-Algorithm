#include<bits/stdc++.h>
using namespace std;

int minimumReverse(int s, int d, vector<pair<int, int>> adjList[], int V, vector<bool> &visited){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int cnt = cur.first;
        int node = cur.second;
        if(visited[node]) continue;
        visited[node] = true;
        if(node == d) return cnt;
        for(auto it : adjList[node]){
            int adjNode = it.first;
            int cost = it.second;
            pq.push(make_pair(cost+cnt, adjNode));
        }
    }
    return -1;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adjList[n];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }

    int s, d;
    cin>>s>>d;
    vector<pair<int, int>> adj[n];
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        for(auto a : adjList[i]){
            adj[i].push_back(make_pair(a, 0));
            adj[a].push_back(make_pair(i, 1));
        }
    }
    cout<<minimumReverse(s, d, adj, n, visited);
    
    return 0;
}