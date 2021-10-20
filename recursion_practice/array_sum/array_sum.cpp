#include <bits/stdc++.h>

using namespace std;

int array_sum (int *arr, int i, int n){
    if (i == n){
        return 0;
    }
    return arr[i] + array_sum(arr, i+1, n);
}

int main(){
    int n, arr[100], sum;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sum = array_sum(arr, 0, n);
    cout<<sum;
    return 0;
}