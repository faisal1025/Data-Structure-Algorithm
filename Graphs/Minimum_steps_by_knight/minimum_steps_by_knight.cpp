#include<bits/stdc++.h>
using namespace std;

int minKnightStep(vector<int> &knightPos, vector<int> targetPos, int N){
    int k1 = knightPos[0];
    int k2 = knightPos[1];
    int t1 = targetPos[0];
    int t2 = targetPos[1];

    vector<vector<int> > grid(N+1, vector<int> (N+1, 0));
    grid[k1][k2] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(k1, k2));
    while(!q.empty()){
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        if(y+2 > 0 and y+2 <= N and x-1 > 0 and x-1 <= N and grid[x-1][y+2] == 0){
            grid[x-1][y+2] = grid[x][y] + 1;
            q.push(make_pair(x-1, y+2));
        }
        if(y+2 > 0 and y+2 <= N and x+1 > 0 and x+1 <= N and grid[x+1][y+2] == 0){
            grid[x+1][y+2] = grid[x][y] + 1;
            q.push(make_pair(x+1, y+2));
        }

        if(y+1 > 0 and y+1 <= N and x-2 > 0 and x-2 <= N and grid[x-2][y+1] == 0){
            grid[x-2][y+1] = grid[x][y] + 1;
            q.push(make_pair(x-2, y+1));
        }
        if(y-1 > 0 and y-1 <= N and x-2 > 0 and x-2 <= N and grid[x-2][y-1] == 0){
            grid[x-2][y-1] = grid[x][y] + 1;
            q.push(make_pair(x-2, y-1));
        }

        if(y+1 > 0 and y+1 <= N and x+2 > 0 and x+2 <= N and grid[x+2][y+1] == 0){
            grid[x+2][y+1] = grid[x][y] + 1;
            q.push(make_pair(x+2, y+1));
        }
        if(y-1 > 0 and y-1 <= N and x+2 > 0 and x+2 <= N and grid[x+2][y-1] == 0){
            grid[x+2][y-1] = grid[x][y] + 1;
            q.push(make_pair(x+2, y-1));
        }

        if(y-2 > 0 and y-2 <= N and x-1 > 0 and x-1 <= N and grid[x-1][y-2] == 0){
            grid[x-1][y-2] = grid[x][y] + 1;
            q.push(make_pair(x-1, y-2));
        }
        if(y-2 > 0 and y-2 <= N and x+1 > 0 and x+1 <= N and grid[x+1][y-2] == 0){
            grid[x+1][y-2] = grid[x][y] + 1;
            q.push(make_pair(x+1, y-2));
        }
    }
    return (grid[t1][t2]-1);
}

int main(){
    vector<int> knightPos;
    vector<int> targetPos;
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    knightPos.emplace_back(x1);
    knightPos.emplace_back(y1);
    targetPos.emplace_back(x2);
    targetPos.emplace_back(y2);
    int N;
    cin>>N;
    cout<<minKnightStep(knightPos, targetPos, N);
    return 0;
}