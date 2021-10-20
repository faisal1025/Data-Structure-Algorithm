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

int main(){
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i = 1; i <= n; i++){
        cin>>val[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>wt[i];
    }

    int w;
    cin>>w;

    vector<vector<int> > dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(wt[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
            }
        }
    }
    
    cout<<dp[n][w]<<endl;
}