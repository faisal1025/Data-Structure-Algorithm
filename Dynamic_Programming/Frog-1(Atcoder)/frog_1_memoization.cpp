#include<bits/stdc++.h>
using namespace std;

int findMinCost(int n, int h[], int dp[]){
    if(n == 1) return 0;
    if(n == 2) return abs(h[2] - h[1]);
    if(dp[n] != -1) return dp[n];

    int minCost = min(findMinCost(n-1, h, dp) + abs(h[n-1]-h[n]), findMinCost(n-2, h, dp) + abs(h[n-2]-h[n]));
    dp[n] = minCost;
    return minCost;
}

int main(){
    int n;
    cin>>n;
    int h[n+1];
    for(int i = 1; i <= n; i++) cin>>h[i];
    int dp[n+1];
    for(int i = 1; i <= n; i++) dp[i] = -1;

    cout<<findMinCost(n, h, dp)<<endl;
    return 0;
}