#include<bits/stdc++.h>
using namespace std;
#define size 100

void merge(int *arr, int l, int mid, int u){
    int i = l, j = mid+1;
    int arr1[size], k;
    k = l;
    while(i <= mid && j <= u){
        if(arr[i] < arr[j]){
            arr1[k] = arr[i];
            i++;
        }
        else{
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    for(; i <= mid; i++){
        arr1[k] = arr[i];
        k++;
    }
    for(; j <= u; j++){
        arr1[k] = arr[j];
        k++;
    }
    for(int x = l; x < k; x++){
        arr[x] = arr1[x];
    }
}

void merge_sort(int *arr, int l, int u){
    if(l < u){
        int mid = (l+u)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, u);
        merge(arr, l, mid, u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[size];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, n);
    for(int j = 0; j < n; j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}