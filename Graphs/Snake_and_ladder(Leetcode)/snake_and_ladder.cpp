#include<bits/stdc++.h>
using namespace std;

int* findCor(int, int);

int snakesAndLadders(vector<vector<int> > &board){
    int n = board.size();
    int val = n*n;
    
    vector<vector<int> > visited(n, vector<int>(n, 0));
    queue<int> q;
    int steps = 0;
    int r = n-1, c = 0;
    q.push(1);
    visited[r][c] = 1;
    while(!q.empty()){
        int size = q.size();
        steps++;

        for(int i = 0; i < size; i++){
            int cur = q.front();
            if(cur == n*n) return steps-1;
            q.pop();

            for(int i = 1; i <= 6; i++){
                if(cur+i > n*n) break;
                int *pos = findCor(cur+i, n);
                r = pos[0];
                c = pos[1];
                if(visited[r][c]) continue;
                visited[r][c] = 1;
                if(board[r][c] == -1){
                    q.push(cur+i);
                }else{
                    q.push(board[r][c]);
                }
            }

        }
    }

    return -1;
}

int* findCor(int num, int n){
    // These formula to get r and c are derived by observing
    int r = n-((num-1)/n)-1;
    int c = (num-1)%n;
    if(r%2 == n%2)
        c = n-1-c;
    int *ans = new int[2];
    ans[0] = r;
    ans[1] = c;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > board(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            cin>>board[i][j];
        }
    }
    /*
        6
        -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1
        -1 35 -1 -1 13 -1
        -1 -1 -1 -1 -1 -1
        -1 15 -1 -1 -1 -1
    */

    cout<<snakesAndLadders(board);
    return 0;
}