#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll  factorial (int n){
    //base case
    if (n == 1 ||  n == 0){
        return 1;
    }
    //self work and recursive intution
    return n*factorial(n-1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    cout<<factorial(x)<<endl;
    return 0;
}