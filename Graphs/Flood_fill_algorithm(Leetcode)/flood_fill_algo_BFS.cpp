#include<bits/stdc++.h>
using namespace std;

bool isOldColor(vector<vector<int> > &image, int r, int c, int oldcolor){
    int total_row = image.size();
    int total_col = image[0].size();
    if(r >= 0 and r < total_row and c >= 0 and c < total_col and image[r][c] == oldcolor){
        return true;
    }
    return false;
}

vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newcolor){
    queue<pair<int, int>> q;
    int oldcolor = image[sr][sc];
    if(oldcolor == newcolor){
        return image;
    }

    q.push(make_pair(sr, sc));
    image[sr][sc] = newcolor;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        if(isOldColor(image, x+1, y, oldcolor)){
            image[x+1][y] = newcolor;
            q.push(make_pair(x+1, y));
        }
        if(isOldColor(image, x-1, y, oldcolor)){
            image[x-1][y] = newcolor;
            q.push(make_pair(x-1, y));
        }
        if(isOldColor(image, x, y+1, oldcolor)){
            image[x][y+1] = newcolor;
            q.push(make_pair(x, y+1));
        }
        if(isOldColor(image, x, y-1, oldcolor)){
            image[x][y-1] = newcolor;
            q.push(make_pair(x, y-1));
        }
    }
    return image;

}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int> > image(m, vector<int> (n, 0));
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            cin>>image[r][c];
        }
    }
    cout<<image.size();
    int sr, sc, newcolor;
    cin>>sr>>sc>>newcolor;
    vector<vector<int> > result = floodFill(image, sr, sc, newcolor);
    for(int r = 0; r < result.size(); r++){
        for(int c = 0; c < result[r].size(); c++){
            cout<<result[r][c]<<" ";
        }
        cout<<"\n";
    }
}