#include<bits/stdc++.h>
#define m 1000000000
using namespace std;

int getCoin(int n){
    int max = INT_MIN;
    while (n != 0)  
    {
        int num = n%10;
        if(max < num) max = num;
        n = n/10;
    }
    return max;
}

int minsteps(int n, int max, vector<int> &dp){
    if(dp[n] != m) return dp[n];
    int maxDigit = getCoin(n-max);
    dp[n] = 1+minsteps(n-max, maxDigit, dp);
    return dp[n]; 
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, m);
    if(n != 0){
        int max = getCoin(n);
        dp[0] = 0;
        cout<<minsteps(n, max, dp);
    }
    return 0;
}