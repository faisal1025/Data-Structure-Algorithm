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

bool isSubsetSum(int n, int arr[], int sum, vector<vector<int> > &dp){
    if(dp[n][sum] != -1) return dp[n][sum];

    if(arr[n] > sum){
        dp[n][sum] =  isSubsetSum(n-1, arr, sum, dp);
    }else{
        bool case1 = isSubsetSum(n-1, arr, sum-arr[n], dp);
        bool case2 = isSubsetSum(n-1, arr, sum, dp);
        dp[n][sum] = (case1+case2);
    }
    return dp[n][sum];
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    vector<vector<int> > dp(n+1, vector<int> (sum+1, -1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= sum; i++){
        dp[0][i] = 0;
    }
    cout<<isSubsetSum(n, arr, sum, dp);
    return 0;
}