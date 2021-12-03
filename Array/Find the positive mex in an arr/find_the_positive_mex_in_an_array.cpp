#include<bits/stdc++.h>
#define sz 1e6+2
using namespace std;

int firstUnavailable(vector<int> a, int n){
    vector<bool> check(sz, false);
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            check[a[i]] = true;
        }
    }

    for(int j = 0; j < sz; j++){
        if(check[j] == false){
            return j;
        }
    }
    return -1;
}

int main(){
    // input taken
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    // Solution 
    cout<<firstUnavailable(a, n)<<endl;

}