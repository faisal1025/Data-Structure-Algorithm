#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum % 2 != 0){
        cout<<0<<endl;
    }else{
        int t = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= t; j++){
                dp[i][j] = ((j < i)?dp[i-1][j]%mod:(dp[i-1][j-i]%mod+dp[i-1][j]%mod)%mod);
            }
        }
        cout<<dp[n][t]<<endl;
    }
    return 0;
}