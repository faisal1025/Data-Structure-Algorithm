#include<bits/stdc++.h>
using namespace std;

void floodfillDfs(vector<vector<int> > &image, int sr, int sc, int total_row, int total_col, int newcolor, int oldcolor){
    if(oldcolor == newcolor){
        return;
    }
    image[sr][sc] = newcolor;
    
    if(sr+1 >= 0 and sr+1 < total_row and sc >= 0 and sc < total_col and image[sr+1][sc] == oldcolor)
        floodfillDfs(image, sr+1, sc, total_row, total_col, newcolor, oldcolor); 
    if(sr-1 >= 0 and sr-1 < total_row and sc >= 0 and sc < total_col and image[sr-1][sc] == oldcolor)
        floodfillDfs(image, sr-1, sc, total_row, total_col, newcolor, oldcolor); 
    if(sr >= 0 and sr < total_row and sc+1 >= 0 and sc+1 < total_col and image[sr][sc+1] == oldcolor)
        floodfillDfs(image, sr, sc+1, total_row, total_col, newcolor, oldcolor); 
    if(sr >= 0 and sr < total_row and sc-1 >= 0 and sc-1 < total_col and image[sr][sc-1] == oldcolor)
        floodfillDfs(image, sr, sc-1, total_row, total_col, newcolor, oldcolor); 
    
}

vector<vector<int> > floodfill(vector<vector<int> > &image, int sr, int sc, int newcolor){
    int m = image.size();
    int n = image[0].size();
    int oldcolor = image[sr][sc];
    floodfillDfs(image, sr, sc, m, n, newcolor, oldcolor);
    return image; 
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int> (n, 0));
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            cin>>grid[r][c];
        }
    }

    int sr, sc, newcolor;
    cin>>sr>>sc>>newcolor;
    vector<vector<int>> image = floodfill(grid, sr, sc, newcolor);
    for(auto r : image){
        for(auto c : r){
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}