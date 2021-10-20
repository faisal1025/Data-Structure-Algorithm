#include<bits/stdc++.h>
#define m 1000000000
using namespace std;

int minCoin(int x, int n, vector<int> coins, vector<int> &dp){
    if(dp[x] != m) return dp[x];
    for(int i = 0; i < n; i++){
        if(coins[i] > x) continue;
        dp[x] = min(dp[x], 1+minCoin(x-coins[i], n, coins, dp));
    }
    return dp[x];
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    vector<int> dp(x+1, m);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin>>coins[i];
        dp[coins[i]] = 1;
    }
    if(minCoin(x, n, coins, dp) == m) cout<<-1;
    else cout<<minCoin(x, n, coins, dp);
}