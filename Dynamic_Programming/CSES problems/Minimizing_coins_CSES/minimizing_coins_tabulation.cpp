#include<bits/stdc++.h>
#define m 1000000000
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    vector<int> dp(x+1, m);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(coins[j] > i) continue;
            dp[i] = min(dp[i], 1+dp[i - coins[j]]);
        }
    }
    if(dp[x] == m) cout<<-1;
    else cout<<dp[x];
    return 0;
}