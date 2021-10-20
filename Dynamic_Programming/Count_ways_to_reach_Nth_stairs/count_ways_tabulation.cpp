#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        cout<<dp[n]<<endl;
    }
}
