#include<bits/stdc++.h>
#define m 1000000000
using namespace std;

vector<int> getNum(int n){
    vector<int> num;
    while (n != 0)
    {
        int no = n%10;
        num.push_back(no);
        n = n/10;
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, m);
    dp[0] = 0;
    for(int i = 1; i <= 9; i++) dp[i] = 1;
    for(int i = 10; i <= n; i++){
        vector<int> num = getNum(i);
        for(int j = 0; j < num.size(); j++){
            if(num[j] != 0){
                dp[i] = min(dp[i], 1+dp[i - num[j]]);
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}