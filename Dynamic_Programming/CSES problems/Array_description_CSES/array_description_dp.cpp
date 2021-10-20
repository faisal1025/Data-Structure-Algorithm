#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector<vector<long long> > dp(m+1, vector<long long>(n+1, 0));
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(arr[i] != 0){
                dp[arr[i]][i] = 1;
            }else{
                for(int j = 1; j <= m; j++){
                    dp[j][i] = 1;
                }
            }
        }else{
            if(arr[i] != 0){
                dp[arr[i]][i] = (dp[arr[i]-1][i-1]%mod + dp[arr[i]][i-1]%mod + ((arr[i]+1 <= m)?dp[arr[i]+1][i-1]%mod:0))%mod;
            }else{
                for(int j = 1; j <= m; j++){
                    dp[j][i] = dp[j][i-1];
                    dp[j][i] = dp[j][i]%mod + dp[j-1][i-1]%mod;
                    dp[j][i] = dp[j][i]%mod + ((j < m)?dp[j+1][i-1]%mod:0);
                    dp[j][i]%=mod;
                }
            }
        }
    }

    long long ans = 0;
    if(arr[n-1] != 0){
        ans = dp[arr[n-1]][n-1]%mod;
    }else{
        for(int i = 1; i <= m; i++){
            ans = (ans%mod + dp[i][n-1]%mod)%mod;
        }
    }
    cout<<ans;
    return 0;
}