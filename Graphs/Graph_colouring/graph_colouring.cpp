#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin>>n>>e;
    int cn = 0;
    vector<int> adj[n];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int color[n] = {-1};
    bool available[n];
    for(int j = 0; j < n; j++) available[j] = true;
    color[0] = 0;
    for(int i = 1; i < n; i++){
        for(auto adjNode:adj[i]){
            if(color[adjNode] != -1){
                available[color[adjNode]] = false;
            }
        }
        int c;
        for(c = 0; c < n; c++){
            if(available[c])
            break;
        }
        color[i] = c; 
        if(cn < c)
            cn = c;
        for(auto adjNode: adj[i]){
            if(color[adjNode] != -1)
                available[color[adjNode]] = true; 
        }
    }
    cout<<cn+1<<"\n";
    for(int j = 0; j < n; j++) cout<<color[j]<<" ";
    return 0;
}