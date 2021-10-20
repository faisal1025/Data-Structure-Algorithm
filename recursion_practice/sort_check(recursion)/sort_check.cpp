#include<bits/stdc++.h>

using namespace std;
#define size 100

bool is_sorted(int *arr, int i, int n){
    if(i >= n-1){
        return true;
    }
    if(arr[i] <= arr[i+1])
        return is_sorted(arr, i+1, n);
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[size];
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    if (is_sorted(arr, 0, n)){
        cout<<"Yes"<<"\n";
    }
    else
        cout<<"No"<<"\n";
    return 0;
}