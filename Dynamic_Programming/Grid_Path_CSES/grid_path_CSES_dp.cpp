#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int> > grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch;
            cin>>ch;
            grid[i][j] = (ch == '.') ? 1 : 0;
        }
    }

    vector<vector<int> > dp(n, vector<int>(n, 0));
    if(grid[n-1][n-1] == 1) dp[n-1][n-1] = 1;

    for(int i = n-2; i >= 0; i--){ // for Column
        if(grid[i][n-1] == 0) dp[i][n-1] = 0;
        else{
            dp[i][n-1] += dp[i+1][n-1];
        }
    }

    for(int i = n-2; i >= 0; i--){ // for Row
        if(grid[n-1][i] == 0) dp[n-1][i] = 0;
        else{
            dp[n-1][i] += dp[n-1][i+1];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            if(grid[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] += (dp[i+1][j]%mod + dp[i][j+1]%mod)%mod;
            }
        }
    }

    cout<<dp[0][0];
    return 0;
}