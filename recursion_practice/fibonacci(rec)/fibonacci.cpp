// Fibonacci series : 0 1 1 2 3 5 8 13 ....so on

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 0 or n == 1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    int nthfib = fib(n);
    cout<<nthfib<<endl;
}