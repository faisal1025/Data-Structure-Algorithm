#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int> > arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool is_it_safe(int i, int j, vector<vector<int> > &arr, int n){
    return i >= 0 && i < n && j >= 0 && j < n;
}

void knight_tour(vector<vector<int> > &arr, int i, int j, int n, int path){
    if(path == n*n-1){
        arr[i][j] = path;
        display(arr, n);
        arr[i][j] = -1;
        return;
    }
    arr[i][j] = path;

    int arr_i[10] = {i-2, i-2, i-1, i-1, i+2, i+2, i+1, i+1};
    int arr_j[10] = {j-1, j+1, j-2, j+2, j+1, j-1, j+2, j-2};

    for(int k = 0; k < 8; k++){
        if(is_it_safe(arr_i[k], arr_j[k], arr, n) && arr[arr_i[k]][arr_j[k]] == -1){
            knight_tour(arr, arr_i[k], arr_j[k], n, path+1);
        }
    }

    arr[i][j] = -1;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > board(n, vector<int>(n, -1));
    knight_tour(board, 0, 0, n, 0);
}