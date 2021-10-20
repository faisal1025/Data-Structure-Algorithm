#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> cost(n+1);
    vector<int> page(n+1);
    for(int i = 1; i <= n; i++){
        cin>>cost[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>page[i];
    }

    vector<vector<int> > dp(n+1, vector<int>(x+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(cost[i] > j){  // if not in budget
                dp[i][j] = dp[i-1][j];
            }else{ // if book is in budget
                dp[i][j] = max(dp[i-1][j], page[i]+dp[i-1][j-cost[i]]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}