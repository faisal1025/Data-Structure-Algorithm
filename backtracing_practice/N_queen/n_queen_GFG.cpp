#include<bits/stdc++.h>
using namespace std;

void display (vector<vector<char> > &board, int n){
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cout<<board[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isItSafe(int col, int row, int n, vector<vector<char> > &board){
    for(int i = row; i >= 0; i--){
        if(board[i][col] == 'Q')
        return false;
    }
    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--){
        if(board[i][j] == 'Q')
        return false;
    }
    for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++){
        if(board[i][j] == 'Q')
        return false;
    }
    return true;
}


void printN_Queen(vector<vector<char> > &board, int n, int row){
    if(row == n){
        display(board, n);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isItSafe(col, row, n, board)){
            board[row][col] = 'Q';
            printN_Queen(board, n, row+1);
            board[row][col] = 'O';
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char> > board(n, vector<char>(n, 'O'));
    printN_Queen(board, n, 0); 
}