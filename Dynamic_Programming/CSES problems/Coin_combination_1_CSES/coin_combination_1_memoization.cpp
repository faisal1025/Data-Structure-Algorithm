#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int waysToGetSum(int x, int n, vector<int> coins, vector<int> &dp){
    if(x == 0) return 1;
    if(dp[x] != 0) return dp[x];
    for(int i = 0; i < n; i++){
        if(coins[i] > x) {
            continue;
        } 
        dp[x] = (dp[x]%mod + waysToGetSum(x-coins[i], n, coins, dp)%mod)%mod;
    }
    return dp[x];
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    vector<int> dp(x+1, 0);
    cout<<waysToGetSum(x, n, coins, dp);
    return 0;
}