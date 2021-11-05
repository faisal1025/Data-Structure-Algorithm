#include<bits/stdc++.h>
#define lg 100000000
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n, int i, vector<int> &dp){
        // Base Case
        for(int i = n-2; i >= 0; i--){
            int s = arr[i];
            for(int j = 1; j <= s and i+j < n; j++){
                dp[i] = min(dp[i], 1+dp[j+i]);
            }
        }
        if(dp[0] != lg) return dp[0];
        else return -1;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n, lg);
    dp[n-1] = 0;
    Solution obj;
    cout<<obj.minJumps(arr, n, 0, dp);
    return 0;
}