#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(j > i) break;
            dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
        }
    }
    cout<<dp[n]%mod;
    return 0;
}