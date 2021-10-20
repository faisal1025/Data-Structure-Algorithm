// Fibonacci series : 0 1 1 2 3 5 8 13 .... so on
// Time Compexity : O(n)
// Memoization/Top-bottom approch
#include<bits/stdc++.h>
using namespace std;

// After applying dp time complexity decrease to O(n) because each fib(n) is calculated
//  only once and stored in dp[] and used when ever required.
int dp[100];

int fib(int n){
    if(n == 0 || n == 1) return n;
    if(dp[n] != 0) return dp[n];
    int i = fib(n-1)+fib(n-2);
    dp[n] = i;
    return i;
}

int main(){
    int n;
    cin>>n;
    int nth_fib = fib(n);
    cout<<nth_fib<<endl;
}