/*
PROBLEM STATEMENT

Given an array of non-negative integers, and a value sum, determine if there is a 
subset of the given set with sum equal to given sum.

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    vector<vector<bool> > dp(n+1, vector<bool> (sum+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= sum; i++){
        dp[0][i] = false;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j-arr[i]]+dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
    return 0;
}