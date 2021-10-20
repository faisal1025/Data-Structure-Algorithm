#include<bits/stdc++.h>
using namespace std;

int minOperation(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) dp[i][j] = minOperation(s1, s2, i-1, j-1, dp);
    else dp[i][j] = min(min(minOperation(s1, s2, i-1, j-1, dp), minOperation(s1, s2, i, j-1, dp)), minOperation(s1, s2, i-1, j, dp));
    return dp[i][j];
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
    dp[0][0] = 0; // If both strings are empty
    
    // Filling first column 
    for(int i = 1; i <= s1.size(); i++){ 
        dp[i][0] = i; // If one string is empty and second string length is i
    }

    // Filling first Row 
    for(int i = 1; i <= s1.size(); i++){ 
        dp[0][i] = i; // If one string is empty and second string length is i
    }

    cout<<minOperation(s1, s2, s1.size(), s2.size(), dp);

}