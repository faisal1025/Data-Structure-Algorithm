/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
#include<bits/stdc++.h>
using namespace std;

void Dfs(int node, vector<int> adj[], vector<int> & visited, int &cnt) {
    visited[node] = 1;
    cnt++;
    for(auto adjNode : adj[node]){
        if(visited[adjNode] == 0){
            Dfs(adjNode, adj, visited, cnt);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> visited(n, 0);
    vector<int> adj[n];
    for(int i = 0; i < astronaut.size(); i++){
        int a = astronaut[i][0];
        int b = astronaut[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> setno;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int cnt = 0;
            Dfs(i, adj, visited, cnt);
            setno.push_back(cnt);
        }
    }
    
    
    int ans = (n*(n-1))/2;
    for(int i = 0; i < setno.size(); i++){
        int x = (setno[i]*(setno[i]-1))/2;
        ans = ans - x;
    }
    
    return ans;   
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int> > astronaut;
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        astronaut.push_back({a, b});
    }
    cout<<journeyToMoon(n, astronaut);
}