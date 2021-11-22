#include<bits/stdc++.h>

using namespace std;

int subArrayCount(vector<int> &arr, int k) {
    // Write your code here.
    int n = arr.size();
    vector<int> arr_(n+1);
    arr_[0] = 0;
    for(int i = 1; i < arr_.size(); i++){
        arr_[i] = arr[i-1];
    }
    int total_cnt = 0, cnt = 0;
    for(int i = 1; i < n+1; i++){
        arr_[i] += arr_[i-1];
        if(arr_[i] % k == 0){
            total_cnt = total_cnt + cnt;
            cnt++;
            arr_[i] = 0;
        }
    }
    total_cnt += cnt;
    return total_cnt;
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

        cout<<subArrayCount(arr, k)<<endl;
    }
}