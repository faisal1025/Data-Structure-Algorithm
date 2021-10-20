#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n, x;  // n -> no of coins , x -> sum
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(coins[i] > j) continue;
            dp[j] = (dp[j] + dp[j-coins[i]])%mod;
        }
    }
    cout<<dp[x]%mod;
    return 0;
}