#include<bits/stdc++.h>
using namespace std;
// Overall Time Complexity : O(N^3)

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int> > graph(n, vector<int>(n, -1));
    for(int i = 0; i < e; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        graph[u][v] = wt;
    }

    // Time complexity : O(N^3)
    vector<vector<int> > dist = graph;
    for(int k = 0; k < n; k++){
        for(int i = 0; i <  n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }


}