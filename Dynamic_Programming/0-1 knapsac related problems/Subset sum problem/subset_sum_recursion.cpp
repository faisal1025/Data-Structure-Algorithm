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

bool isSubsetSum(int n, int arr[], int sum){
    if(sum == 0) return true;
    else if(n == 0) return false;

    if(arr[n] > sum){
        return isSubsetSum(n-1, arr, sum);
    }else{
        bool case1 = isSubsetSum(n-1, arr, sum-arr[n]);
        bool case2 = isSubsetSum(n-1, arr, sum);
        return(case1+case2);
    }
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

    cout<<isSubsetSum(n, arr, sum);
    return 0;
}