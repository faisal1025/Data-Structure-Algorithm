#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxFirst(vector<int> &arr, int i, int j){
    ll x, y, z;
    x = ((i+2 <= j)?maxFirst(arr, i+2, j):0);
    y = ((i+1 <= j-1)?maxFirst(arr, i+1, j-1):0);
    z = ((i <= j-2)?maxFirst(arr, i, j-2):0);

    return max(arr[i]+min(x, y), arr[j]+min(y, z));
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<maxFirst(arr, 0, n-1);
    return 0;
}