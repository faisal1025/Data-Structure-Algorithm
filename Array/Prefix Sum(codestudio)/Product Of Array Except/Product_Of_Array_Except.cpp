#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int *getProductArrayExceptSelf(int *arr, int n)
{
    //Write your code here
    int *pro = new int[n];
    int product = 1;
    int zero = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0) product = (product%mod *arr[i]%mod)%mod;
        else zero++;
    }
    if(zero == 1){
        for(int j = 0; j < n; j++){
            if(arr[j] != 0) {
                pro[j] = 0;
            }
            else {
                pro[j] = product;
            }
        }
    }else if(zero > 1){
        for(int j = 0; j < n; j++){
            pro[j] = 0;
        }
    }else{
        for(int j = 0; j < n; j++){
            pro[j] = product/arr[j];
        }
    }
    return pro;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int * res = getProductArrayExceptSelf(arr, n);
        for(int i = 0; i < n; i++){
            cout<<*(res+i)<<" ";  
        }
        cout<<"\n";
    }
}