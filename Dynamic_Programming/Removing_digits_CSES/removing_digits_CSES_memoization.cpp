#include<bits/stdc++.h>
#define m 1000000000
using namespace std;

vector<int> getCoin(int n){
    vector<int> coins;
    while (n != 0)  
    {
        int num = n%10;
        coins.push_back(num);
        n = n/10;
    }
    return coins;
}

int minsteps(int n, vector<int> coins, vector<int> &dp){
    if(dp[n] != m) return dp[n];
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] != 0){
            vector<int> coin = getCoin(n-coins[i]);
            dp[n] = min(dp[n], 1+minsteps(n-coins[i], coin, dp));
        }
    }
    return dp[n]; 
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, m);
    if(n != 0){
        vector<int> coins = getCoin(n);
        dp[0] = 0;
        cout<<minsteps(n, coins, dp);
    }
    return 0;
}