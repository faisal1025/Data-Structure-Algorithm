#include<bits/stdc++.h>
using namespace std;

// Tabulation method/bottom-up approch DP  
// Time complexity : O(n)

int fib(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}