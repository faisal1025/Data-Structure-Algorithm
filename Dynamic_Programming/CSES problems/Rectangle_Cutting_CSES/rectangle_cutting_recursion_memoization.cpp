#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return ((a<b)?a:b);
}

int cutting(int n, int m, vector<vector<long long>> &dp){
    if(n == m) {
        dp[n][m] = 0;
        return dp[n][m];
     }
    if(dp[n][m] != INT_MAX) return dp[n][m];
    for(int i = 1; i < n; i++){ // Horizontal Cut
        dp[n][m] = min(dp[n][m], 1+cutting(i, m, dp)+cutting(n-i, m, dp));
    }
    for(int i = 1; i < m; i++){ // Vertical Cut
        dp[n][m] = min(dp[n][m], 1+cutting(n, i, dp)+cutting(n, m-i, dp));
    }
    return dp[n][m];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, INT_MAX));
    for(int i = 1; i <= m; i++){ // filling first row
        dp[1][i] = i-1; // for first row
    }
    for(int i = 1; i <= n; i++){ // filling first col
        dp[i][1] = i-1; // for first col
    }
    cout<<cutting(n, m, dp)<<endl;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}