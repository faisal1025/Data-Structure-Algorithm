
#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int sum, int n, vector<vector<int> > &dp){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
        }
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