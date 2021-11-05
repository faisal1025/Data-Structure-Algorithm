#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int find_it;
    cin>>find_it;

    int hi = n-1, lo = 0, pos = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] == find_it){
            pos = mid;
            lo = mid+1;
            hi = mid-1;
        }else if (arr[mid] < find_it){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    if(pos == -1){
        cout<<"Not Found\n";
    }else{
        cout<<pos<<"\n";
    }
    cout<<"Upper-bound "<<arr[lo]<<"\n";
    cout<<"Lower-bound "<<arr[hi]<<"\n";
    return 0;
}