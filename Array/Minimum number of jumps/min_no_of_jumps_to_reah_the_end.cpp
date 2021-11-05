#include<bits/stdc++.h>
#define lg INT_MAX
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n, int i, vector<int> &dp){
        // Base Case
        if(i >= n-1) return 0;
        if(dp[i] != -1) return dp[i];

        int minjumps = lg;
        int s = arr[i];
       
        for(int in = 1; in <= s && in+i <= n-1; in++){
            int step = minJumps(arr, n, in+i, dp);
            if(step == -1) continue;
            minjumps = min(minjumps, 1 + step);
        }
        dp[i] = minjumps;
        if(minjumps == lg) return -1;
        else return minjumps;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n,-1);
    dp[n-1] = 0;
    Solution obj;
    cout<<obj.minJumps(arr, n, 0, dp);
    return 0;
}