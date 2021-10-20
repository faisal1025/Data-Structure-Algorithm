#include<bits/stdc++.h>
#define mod ((1000000000)+7)
using namespace std;

int dC(int n, vector<int>& dp){
    if(n == 0 || n == 1) return 1;
    if(dp[n] != 0) return dp[n];
    int ans = 0;
    for(int j = 1; n-j >= 0 and j <= 6; j++){
        ans = (ans%mod + dC(n-j, dp)%mod)%mod;
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    cout<<dC(n, dp);
}