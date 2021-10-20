#include<bits/stdc++.h>
using namespace std;

bool detectNegCycle(int V, vector<pair<int, int>> adj[]){
    vector<int> weight(V, INT_MAX);
    weight[0] = 0;
    for(int i = 0; i < V; i++){
        int change = 0;
        for(int j = 0; j < V; j++){
            for(auto p : adj[j]){
                int s = j;
                int d = p.first;
                int wt = p.second;
                // Relaxation
                if(weight[s] != INT_MAX and weight[d] > weight[s]+wt){
                    change++;
                    weight[d] = weight[s]+wt;
                }
            }
        }
        if(change == 0)
            return false;
    }
    return true;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b, wt));
    }

    if(detectNegCycle(n, adj))
        cout<<"Yes, there is a negative cycle.\n";
    else
        cout<<"No negative cycle found.\n";
    return 0;
}