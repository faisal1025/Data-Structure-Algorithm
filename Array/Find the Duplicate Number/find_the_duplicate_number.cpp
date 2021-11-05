#include<bits/stdc++.h>

using namespace std;

int getDup(vector<int> arr, int n){

    // modifying the array simply add n at arr[arr[i]]
    for(int i = 0; i < n; i++){
        arr[arr[i]%n] = arr[arr[i]%n] + n;
    }

    // find if there is any value in the array in which n is added double time
    // that's index is the correct answer.
    for(int i = 0; i < n; i++){
        if(arr[i]/n > 1) return i;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<getDup(arr, n);
}