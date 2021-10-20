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

class Solution
{
    private:
    int Helper(int w, int weight[], int cost[], int n, vector<vector<int> > &dp) 
    { 
        // Your code here
        if(dp[n][w] != -1) return dp[n][w];
        
        if(weight[n] > w) {
            dp[n][w] = Helper(w, weight, cost, n-1, dp);
        }else{
            int inc = Helper(w-weight[n], weight, cost, n-1, dp);
            int ninc = Helper(w, weight, cost, n-1, dp);
            dp[n][w] = max(cost[n]+inc, ninc);
        }
        return dp[n][w];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int weight[], int cost[], int n) 
    { 
        // Your code here
        vector<vector<int> > dp(n+1, vector<int> (W+1, -1));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= W; i++) {
            dp[0][i] = 0;
        }
        return Helper(W, weight, cost, n, dp);
    }
};

int main(){
    int n;
    cin>>n;
    int cost[n+1];
    int weight[n+1];
    for(int i = 1; i <= n; i++) cin>>cost[i];
    for(int i = 1; i <= n; i++) cin>>weight[i];
    
    int W;
    cin>>W;
    Solution obj;
    cout<<obj.knapSack(W, weight, cost, n);
}