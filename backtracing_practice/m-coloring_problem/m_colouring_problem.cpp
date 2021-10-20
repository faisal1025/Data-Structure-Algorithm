#include<bits/stdc++.h>
using namespace std;

bool isSafe(int grid[101][101], int col, int n, int node, int vertices[]){
    for(int i = 0; i < n; i++){
        if(i != node && grid[i][node] == true && vertices[i] == col){
            return false;
        }
    }
    return true;
}

bool isPossible(int grid[101][101], int n, int m, int vertices[], int node){
    if(node == n) {
        return true;
    }
    for(int color = 1; color <= m; color++){
        if(isSafe(grid, color, n, node, vertices)){
            vertices[node] = color;
            if(isPossible(grid, n, m, vertices, node+1)) return true;
            vertices[node] = 0;
        }
    }
    return false;
}

bool graphColoring(int grid[101][101], int m, int n){
    int vertices[n] = {0};
    if(isPossible(grid, n, m, vertices, 0)) return true;
    return false;    
}


int main(){
    int n, m;
    cin>>n>>m;
    int grid[101][101] ;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            grid[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        grid[u][v] = 1;
        grid[v][u] = 1;
    }
    cout<<graphColoring(grid, m, n);
}