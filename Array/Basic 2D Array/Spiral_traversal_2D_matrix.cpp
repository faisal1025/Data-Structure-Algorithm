#include<bits/stdc++.h>
using namespace std;


vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    // Write your code here.
    vector<int>  ans;
    int ele = 0;
    int top = 0;
    int right = m-1;
    int bottom = n-1;
    int left = 0;
    while(ele < n*m){
        //top wall
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
            ele++;
        }
        top++;
        if(ele == n*m) break;

        // right wall
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
            ele++;
        }
        right--;
        if(ele == n*m) break;
        
        // bottom wall
        for(int i = right; i >= left; i--){
            ans.push_back(matrix[bottom][i]);
            ele++;
        }
        bottom--;
        if(ele == n*m) break;
        
        // left wall
        for(int i = bottom; i >= top; i--){
            ans.push_back(matrix[i][left]);
            ele++;
        }
        left++;       
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> >  arr(n, vector<int> (m));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }

        cout<<endl;
        vector<int> ans = spiralPathMatrix(arr, n, m);
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}