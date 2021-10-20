#include <bits/stdc++.h>

using namespace std;
class Solution{
    private:
        int n, m;
    public:
        Solution(int total_row, int total_col){
            n = total_row;
            m = total_col;
        }
        void maze_path(int row, int col, string osf){
            //base case (reach end of the maze)
            if(row == n-1 && col == m-1){
                cout<<"["+osf+"]"<<endl;
                return;
            }

            //from a block we can go either right or down or diagonally
            // (three option = three calls)
            
            if(col < m-1)   //Right move
                maze_path(row, col+1, osf+" R ");

            if (row < n-1)   //Down move
                maze_path(row+1, col, osf+" D ");

            if (row < n-1 && col < m-1)   //Diagonal move
                maze_path(row+1, col+1, osf+" Dia ");
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total_row, total_col;
    cin>>total_row>>total_col;
    Solution obj(total_row, total_col);
    obj.maze_path(0, 0, "");
}