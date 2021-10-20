#include<bits/stdc++.h>
using namespace std;

int ways = 0;

void display(vector<vector<int> > arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool is_it_safe(int r, int c, vector<vector<int> > arr, int n){
    if(r >= 0 && r < n && c >= 0 && c < n){
        for(int i = r-1, j = c; i >= 0; i--){ // UP
            if(arr[i][j] == 1)
                return false;
        }
        
        for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++){  // DIAGONAL RIGHT
            if(arr[i][j] == 1)
                return false;
        }

        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){  // DIAGONAL LEFT
            if(arr[i][j] == 1)
                return false;
        }
        return true;
    }
    else
        return false;
}

void n_queen(vector<vector<int> > arr, int r, int n){
    if(r == n){
        display(arr, n);
        ways++;
        return;
    }

    for(int c = 0; c < n; c++){
        if(is_it_safe(r, c, arr, n)){
            arr[r][c] = 1;
            n_queen(arr, r+1, n);
            arr[r][c] = 0;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > board(n, vector<int>(n, 0));
    n_queen(board, 0, n);
    cout<<ways;
    return 0;
}