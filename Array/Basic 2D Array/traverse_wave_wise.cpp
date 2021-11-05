#include<bits/stdc++.h>
using namespace std;


vector<int> rowWaveForm(vector<vector<int>> &mat) {
    // Write your code here.
    int flag = 1;
    vector<int> ans;
    for(int i = 0; i < mat.size(); i++){
        if(flag){
            flag = 0;
            for(int j = 0; j < mat[i].size(); j++){
            	ans.push_back(mat[i][j]);
        	}
        }else{
            flag = 1;
            for(int j = mat[i].size()-1; j >= 0; j--){
            	ans.push_back(mat[i][j]);
        	}
        }  
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

        vector<int> ans = rowWaveForm(arr);
        for(int i = 0; i < ans.size(); i ++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}