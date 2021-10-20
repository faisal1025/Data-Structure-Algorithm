// Fibonacci series : 0 1 1 2 3 5 8 13 .... so on
// Time Compexity : O(2^n) exponential soo worse time compexity
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    int nth_fib = fib(n);
    cout<<nth_fib<<endl;
}