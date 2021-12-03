#include<bits/stdc++.h>
#define sz 1e6+2
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> idx(sz, -1);

    // maintaining min index
    int minIdx = INT_MAX;
    for(int i = 0; i < n; i++){
        if(idx[arr[i]] != -1){
            minIdx = min(minIdx, idx[arr[i]]);
        }else{
            idx[arr[i]] = i;
        }
    }
    if(minIdx == INT_MAX){
        cout<<-1<<"\n";
    }else{
        // if min index found print index
        cout<<minIdx<<"\n";
    }
}