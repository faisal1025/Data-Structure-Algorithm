#include<bits/stdc++.h>

using namespace std;

int str_to_int(string str, int i, int result){
    if(i == str.size()){
        return result;
    }
    result = result*10+str[i]-'0';
    return str_to_int(str, i+1, result);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int ans;
    cin>>str;
    ans = str_to_int(str, 1, str[0]-'0'); //to convert string to integer (str[0]-'0')
    cout<<ans;
    return 0;
}