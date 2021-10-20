#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool isItSafe(int row, int col, int n, int m){
            return (row >= 0 and row < n and col >= 0 and col < m);
        }

        void isIslandBfs(vector<vector<char> > &grid, int n, int m, int row, int col, vector<vector<int> > &visited){
            queue<pair<int, int> > q;
            q.push(make_pair(row, col));
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if(isItSafe(r+1, c, n, m) and grid[r+1][c] == '1' and visited[r+1][c] == 0){
                    q.push(make_pair(r+1, c));
                    visited[r+1][c] = 1;
                }
                if(isItSafe(r+1, c+1, n, m) and grid[r+1][c+1] == '1' and visited[r+1][c+1] == 0){
                    q.push(make_pair(r+1, c+1));
                    visited[r+1][c+1] = 1;
                }
                if(isItSafe(r+1, c-1, n, m) and grid[r+1][c-1] == '1' and visited[r+1][c-1] == 0){
                    q.push(make_pair(r+1, c-1));
                    visited[r+1][c-1] = 1;
                }
                if(isItSafe(r, c+1, n, m) and grid[r][c+1] == '1' and visited[r][c+1] == 0){
                    q.push(make_pair(r, c+1));
                    visited[r][c+1] = 1;
                }
                if(isItSafe(r, c-1, n, m) and grid[r][c-1] == '1' and visited[r][c-1] == 0){
                    q.push(make_pair(r, c-1));
                    visited[r][c-1] = 1;
                }
                if(isItSafe(r-1, c, n, m) and grid[r-1][c] == '1' and visited[r-1][c] == 0){
                    q.push(make_pair(r-1, c));
                    visited[r-1][c] = 1;
                }
                if(isItSafe(r-1, c+1, n, m) and grid[r-1][c+1] == '1' and visited[r-1][c+1] == 0){
                    q.push(make_pair(r-1, c+1));
                    visited[r-1][c+1] = 1;
                }
                if(isItSafe(r-1, c-1, n, m) and grid[r-1][c-1] == '1' and visited[r-1][c-1] == 0){
                    q.push(make_pair(r-1, c-1));
                    visited[r-1][c-1] = 1;
                }
            }
        }
    public:
        int numIslands(vector<vector<char> > &grid){
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int> > visited(n, vector<int>(m, 0));
            int cnt = 0;
            for(int row = 0; row < n; row++){
                for(int col = 0; col < m; col++){
                    if(!visited[row][col] and grid[row][col] == '1'){
                        cnt++; 
                        visited[row][col] = 1;
                        isIslandBfs(grid, n, m, row, col, visited);
                    }
                }
            }
            return cnt;
        }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char> > grid(n, vector<char> (m, '0'));
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin>>grid[row][col];
        }
    }
    Solution obj;
    cout<<obj.numIslands(grid);
}