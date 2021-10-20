#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n, x; // n -> no of coin , x -> sum
    cin>>n>>x;
    vector<int> coin(n+1);
    for(int i = 1; i <= n; i++) cin>>coin[i];
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(coin[j] > i) continue;
            dp[i] = (dp[i] + dp[i - coin[j]])%mod;
        }
    }
    cout<<dp[x]%mod; 
    return 0;
}