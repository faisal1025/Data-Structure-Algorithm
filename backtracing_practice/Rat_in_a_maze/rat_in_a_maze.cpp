#include<bits/stdc++.h>
using namespace std;

int total_path = 0;

void Display(vector<vector<char> > &arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool is_it_safe(int r, int c, int n){
    return r >= 0 && r < n && c >= 0 && c < n;
}

void rat_maze(vector<vector<char> > &arr, int r, int c, int n, vector<vector<bool> > &visited){
    if(r == n-1 && c == n-1){
        cout<<"\n";
        Display(arr, n);
        total_path++;
        return;
    }

    visited[r][c] = false;
    
    if(is_it_safe(r-1, c, n) && arr[r-1][c] == 'O' && visited[r-1][c] == true){ //UP
        arr[r][c] = 'U';
        rat_maze(arr, r-1, c, n, visited);
        arr[r][c] = 'O';
    }

    if(is_it_safe(r, c-1, n) && arr[r][c-1] == 'O' && visited[r][c-1] == true){ //LEFT
        arr[r][c] = 'L';
        rat_maze(arr, r, c-1, n, visited);
        arr[r][c] = 'O';
    }

    if(is_it_safe(r, c+1, n) && arr[r][c+1] == 'O' && visited[r][c+1] == true){ //RIGHT
        arr[r][c] = 'R';
        rat_maze(arr, r, c+1, n, visited);
        arr[r][c] = 'O';
    }

    if(is_it_safe(r+1, c, n) && arr[r+1][c] == 'O' && visited[r+1][c] == true){ //DOWN
        arr[r][c] = 'D';
        rat_maze(arr, r+1, c, n, visited);
        arr[r][c] ='O';
    }

    visited[r][c] = true;
}


int main(){
    int n;
    cin>>n;
    vector<vector<char> > arr(n, vector<char>(n, 'O'));
    vector<vector<bool> > visited(n, vector<bool>(n, true));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    rat_maze(arr, 0, 0, n, visited);
    cout<<total_path;
    return 0;
}