#include<bits/stdc++.h>
using namespace std;


int equalSubsetSum(int n, int arr[], int start, int sum, int total_sum){
    if(start == n){
        return 0;
    }
    for(int k = start; k < n; k++){
        sum += arr[k];
        int sum2 = total_sum - sum;

        if(sum <= sum2){
            if(sum == sum2)
                return 1;
            if(equalSubsetSum(n, arr, k+1, sum, total_sum)) return  1;
        } 
        
        sum -= arr[k];
    }
    return 0;
}

int main(){
    int N;
    cin>>N;
    int arr[N];
    int total_sum = 0;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
        total_sum+=arr[i];
    }
    cout<<equalSubsetSum(N, arr, 0, 0, total_sum);
    return 0;
}