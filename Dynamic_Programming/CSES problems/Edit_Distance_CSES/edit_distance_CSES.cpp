#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int size1 = s1.length();
    int size2 = s2.length();
    vector<vector<int> > dp(size1+1, vector<int>(size2+1, 0));
    dp[0][0] = 0; // When both string length is 0
    for(int i = 1; i <= size1; i++) dp[i][0] = i; // Filling first Row
    for(int i = 1; i <= size2; i++) dp[0][i] = i; // Filling first Column
    for(int i = 1; i <= size1; i++){
        for(int j = 1; j <= size2; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                dp[i][j] += 1;
            }
        }
    }
    cout<<dp[size1][size2];
}
    
