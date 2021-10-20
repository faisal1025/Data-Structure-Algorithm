#include<bits/stdc++.h>
using namespace std;

void reverse_arr(int *arr, int i, int j){
    if (i >= j)
        return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverse_arr(arr, i+1, j-1);
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    reverse_arr(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}