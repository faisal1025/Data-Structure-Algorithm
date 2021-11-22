#include<bits/stdc++.h>

using namespace std;

int subArrayCount(vector<int> &arr, int k) {
    // Write your code here.
    int n = arr.size();
    vector<int> prefixSum(n+1);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(prefixSum[i]%k == 0) cnt++;

        for(int j = i-1; j >= 0; j--){
            if((prefixSum[i] - prefixSum[j]) % k == 0) cnt++;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<subArrayCount(arr, k)<<"\n";
    }

}