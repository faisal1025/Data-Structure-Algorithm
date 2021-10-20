#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int> > & board){
    for(int x = 0; x < board.size(); x++){
        for(int y = 0; y < board.size(); y++){
            cout<<board[x][y]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool is_valid(vector<vector<int> > &board, int option, int x, int y){
    for(int row = 0; row < board.size(); row++){
        if(board[row][y] == option)
            return false;
    }

    for(int col = 0; col < board.size(); col++){
        if(board[x][col] == option)
            return false;
    }

    int xs = 3*(x/3);
    int ys = 3*(y/3);
    for(int i = xs; i < xs+3; i++){
        for(int j = ys; j < ys+3; j++){
            if(board[i][j] == option)
                return false;
        }
    }
    return true;
}

void sudokuSolver(vector<vector<int>> &board, int i, int j){
    if(i == board.size()){
        display(board);
        return;
    }
    int ni, nj;
    if(j == 8){
        ni = i+1;
        nj = 0;
    }else{
        ni = i;
        nj = j+1;
    }

    if(board[i][j] != 0){
        sudokuSolver(board, ni, nj);
    }else{
        for(int options = 1; options < 10; options++){
            if(is_valid(board, options, i, j)){
                board[i][j] = options;
                sudokuSolver(board, ni, nj);
                board[i][j] = 0;
            }
        }
    }

}

int main(){
    // taking input 
    vector<vector<int> > board(9, vector<int> (9));
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            cin>>board[i][j];
        }
    }
    /*
            3 0 6 5 0 8 4 0 0
            5 2 0 0 0 0 0 0 0
            0 8 7 0 0 0 0 3 1
            0 0 3 0 1 0 0 8 0
            9 0 0 8 6 3 0 0 5
            0 5 0 0 9 0 6 0 0
            1 3 0 0 0 0 2 5 0
            0 0 0 0 0 0 0 7 4
            0 0 5 2 0 6 3 0 0
    */
    cout<<endl;

    // function that solve the sudoku
    sudokuSolver(board, 0, 0);


    return 0;
}