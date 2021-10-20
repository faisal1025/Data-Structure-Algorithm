#include<bits/stdc++.h>
using namespace std;

bool is_palin(string s){

    for(int i = 0, j = s.length()-1; i <= j; i++ , j--){
        if(s[i] != s[j])
        return false;
    }
    return true;
}

void palindromicPartition(string s, int i, string ans){
    if(i == s.length()){
        ans.erase(ans.begin()+(ans.length()-1));
        cout<< ans <<endl;
        return;
    }
    string store = "";
    for(int k = i; k < s.length(); k++){
        store += s[k];
        if(is_palin(store)){
            palindromicPartition(s, k+1, ans+store+" ");
        }
    }
    return;
}

int main(){
    string str;
    cin>>str;
    palindromicPartition(str, 0, "");
    return 0;
}