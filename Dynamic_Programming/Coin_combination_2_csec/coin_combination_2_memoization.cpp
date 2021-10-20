#include<bits/stdc++.h>
using namespace std;

int getWays(int n, int x, vector<int> coins, vector<int> &dp){
    int coin = coins[n];
    for(int j = 1; j <= x; j++){
        if(coin > j) continue;
        getWays(n, j-coin, coins, dp);
        dp[j] += dp[j-coin];
    }
}

int main(){
    int n, x;  // n -> no of coins , x -> sum
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    vector<int> dp(x+1, 0);
    getWays(0, x, coins, dp);
    return 0;
}