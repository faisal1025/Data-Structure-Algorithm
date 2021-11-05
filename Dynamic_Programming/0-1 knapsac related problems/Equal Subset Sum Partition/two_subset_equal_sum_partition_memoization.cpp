#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int sum, int n, vector<vector<int> > &dp){
    if(dp[n][sum] != -1) return dp[n][sum];

    if(arr[n-1] > sum){
        dp[n][sum] = subsetSum(arr, sum, n-1, dp);
    }else{
        dp[n][sum] = (subsetSum(arr, sum - arr[n-1], n-1, dp)+subsetSum(arr, sum, n-1, dp));
    }
    return  dp[n][sum];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    vector<vector<int> > dp (n+1, vector<int>((sum/2)+1, -1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= sum/2; i++){
        dp[0][i] = 0;
    }
    if(sum %2 != 0){
        cout<<"NO\n";
    }else{
        if(subsetSum(arr, sum/2, n, dp)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}