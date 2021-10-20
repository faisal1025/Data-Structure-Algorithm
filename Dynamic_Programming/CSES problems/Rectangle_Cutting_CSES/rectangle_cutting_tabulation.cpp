#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    if(n == m){ cout<<0; return 0;}
    
    vector<vector<int> > dp(n+1, vector<int>(m+1, INT_MAX));

    for(int i = 1; i <= m; i++){ // filling first row
        dp[1][i] = i-1; // for first row
    }
    for(int i = 1; i <= n; i++){ // filling first col
        dp[i][1] = i-1; // for first col
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if(i == j) {dp[i][j] = 0; continue;}

            // Horizontal Cut
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
            }

            // Vertical Cut
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}