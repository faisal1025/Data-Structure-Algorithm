#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int pathcnt;

bool is_safe(int i, int j, int n, vector<vector<char> > grid){
    return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == '.');
}

void validPath(vector<vector<char>> grid, int n, int i, int j, vector<vector<int>> visited){
    visited[i][j] = 1;
    if(grid[n-1][n-1] == '*') {
        pathcnt = 0;
        return;
    }
    if(i == n-1 and j == n-1) {
        pathcnt = (pathcnt%mod + 1%mod)%mod;
        return;
    }

    // Right
    if(is_safe(i, j+1, n, grid)){
        validPath(grid, n, i, j+1, visited);
    }
    // Down
    if(is_safe(i+1, j, n, grid)){
        validPath(grid, n, i+1, j, visited);
    }
    visited[i][j] = 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char> > grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }
    pathcnt = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    validPath(grid, n, 0, 0, visited);
    cout<<pathcnt;
    return 0;
}