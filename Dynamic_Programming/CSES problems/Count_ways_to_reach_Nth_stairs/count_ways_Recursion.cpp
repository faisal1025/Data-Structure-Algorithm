#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int cntWays(int n){
    if(n == 0 || n == 1) return 1;
    return (cntWays(n-1)%mod+cntWays(n-2)%mod)%mod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<cntWays(n)<<endl;
    }
}