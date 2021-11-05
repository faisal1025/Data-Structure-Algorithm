/*
PROBLEM STATEMENT:-
you have to find the maximum sum in the sub arrays of the given array Arr[].

Input:
N = 5
Arr[] = {1,2,3,-2,5}

Output:
9

Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

*/

#include<bits/stdc++.h>
using namespace std;

int kadensAlgo(int arr[], int n){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        sum += arr[i];
        if(sum > maxSum){
            maxSum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<kadensAlgo(arr, n);
    return 0;
}