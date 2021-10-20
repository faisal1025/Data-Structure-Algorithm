#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int cntWays(int n, vector<int> & dp){
    if(dp[n] != 0) return dp[n];
    dp[n] = (cntWays(n-1, dp)%mod+cntWays(n-2, dp)%mod)%mod;
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1; dp[2] = 2;
        cout<<cntWays(n, dp)<<endl;
    }
}