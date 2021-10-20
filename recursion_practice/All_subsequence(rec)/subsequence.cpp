#include<bits/stdc++.h>

using namespace std;

void all_subsequence(string str, int i, string osf){
    if(i == str.size()){
        cout<<osf<<"\n";
        return;
    }
    all_subsequence(str, i+1, osf+str[i]);
    all_subsequence(str, i+1, osf);
}

int main(){
    string str;
    cin>>str;
    all_subsequence(str, 0, "");
    return 0;
}