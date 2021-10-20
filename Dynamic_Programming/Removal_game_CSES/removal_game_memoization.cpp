#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxFirst(vector<int> &arr, int i, int j, vector<vector<ll> > &dp){
    if(dp[i][j] != 0) return dp[i][j];
    ll x, y, z;
    x = ((i+2 <= j)?maxFirst(arr, i+2, j, dp):0);
    y = ((i+1 <= j-1)?maxFirst(arr, i+1, j-1, dp):0);
    z = ((i <= j-2)?maxFirst(arr, i, j-2, dp):0);

    dp[i][j] = max(arr[i]+min(x, y), arr[j]+min(y, z));
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<vector<ll> > dp(n, vector<ll> (n, 0));
    cout<<maxFirst(arr, 0, n-1, dp);
    return 0;
}