#include<bits/stdc++.h>
using namespace std;

void complementOfGraph(int adjM[101][101], int V){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i != j){
                if(adjM[i][j] == 1) adjM[i][j] = 0;
                else adjM[i][j] = 1;
            }
        }
    }
}

bool isTwoClique(int adjM[101][101], int V){
    complementOfGraph(adjM, V);
    queue<int> q;
    vector<int> color(V, 0);
    color[0] = 1;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < V; i++){
            if(adjM[cur][i] == 1){
                if(color[i] == 0){
                    if(color[cur] == 1) color[i] = 2;
                    else if(color[cur] == 2) color[i] = 1;
                    q.push(i);
                }else if(color[cur] == color[i]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n, e;
    cin>>n>>e;
    int adjM[101][101] = {0};
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjM[a][b] = 1;
        adjM[b][a] = 1;
    }

    if(isTwoClique(adjM, n)) cout<<"Yes";
    else cout<<"No";
    return 0;
}