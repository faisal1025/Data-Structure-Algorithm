#include<bits/stdc++.h>
using namespace std;

int minCost(int n,vector<int> h, vector<int> dp){
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);

    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));
    }

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> h(n+1);
    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }
    vector<int> dp(n+1, -1);
    cout<<minCost(n, h, dp)<<endl;
    return 0;
}