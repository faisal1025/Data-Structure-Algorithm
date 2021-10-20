#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int min = INT_MAX;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin>> arr[i];
            if(min > arr[i]){
                min = arr[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == min)
                cnt += 1;
        }
        int ans = n - cnt;
        cout<<ans<<endl;
    }
}