/*
Ques - Find the max cost a bag can handle given a capacity of bag can handle W kg and a
series of items n items i1 i2 i3 i4...in i array show the cost and there will be another
array w contain the weight of the each item as w1 w2 w3 w4...wn.

SAMPLE INPUT
4 -> n 
1 2 3 4 -> cost array
1 3 4 7 -> weight array
7 -> W

SAMPLE OUTPUT
5
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int w, int weight[], int cost[], int n) 
    { 
        // Your code here
        if(n == 0 || w == 0) return 0;
        
        int maxProf = 0;
        if(weight[n] > w) {
            maxProf = getMaxProfit(w, weight, cost, n-1);
        }else{
            int inc = getMaxProfit(w-weight[n], weight, cost, n-1);
            int ninc = getMaxProfit(w, weight, cost, n-1);
            maxProf = max(cost[n]+inc, ninc);
        }
        return maxProf;
    }

int main(){
    int n;
    cin>>n;
    int cost[n+1];
    int weight[n+1];
    for(int i = 1; i <= n; i++) cin>>cost[i];
    for(int i = 1; i <= n; i++) cin>>weight[i];
    
    int W;
    cin>>W;

    cout<<getMaxProfit(W, weight, cost, n);

    return 0;
}