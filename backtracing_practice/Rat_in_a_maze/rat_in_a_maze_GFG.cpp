#include<bits/stdc++.h>
#define  vv  vector<vector<int> >
using namespace std;

bool isSafe(int i, int j, int n){
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void printPath(int n, vv m, vector<vector<bool> > visited, int i, int j, string str){
    if(i == n-1 and j == n-1){
        cout<<str<<" ";
        return;
    }
    visited[i][j] = false;

    // Write path as Down, Left, Right, and Up in sorted order
    
    if(isSafe(i+1, j, n) and m[i+1][j] == 1 and visited[i+1][j]){ //Down
        printPath(n, m, visited, i+1 , j, str+'D');    
    }
    if(isSafe(i, j-1, n) and m[i][j-1] == 1 and visited[i][j-1]){ // Left
        printPath(n, m, visited, i , j-1, str+'L');    
    }
    if(isSafe(i, j+1, n) and m[i][j+1] == 1 and visited[i][j+1]){ // Right
        printPath(n, m, visited, i , j+1, str+'R');    
    }
    if(isSafe(i-1, j, n) and m[i-1][j] == 1 and visited[i-1][j]){ // Up
        printPath(n, m, visited, i-1 , j, str+'U');    
    }

    visited[i][j] = true;

}

int main(){
    int n;
    cin>>n;
    vv m(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>m[i][j];
        }
    }
    if(m[0][0] == 0 or m[n-1][n-1] == 0)
        cout<<-1;
    else{
        vector<vector<bool> >  visited(n, vector<bool>(n, true));
        printPath(n, m, visited, 0 , 0, "");
    }    
}